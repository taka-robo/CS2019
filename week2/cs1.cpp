/**
 * @file ec1.cpp
 * @brief 計算基礎工学の課題1(エラトステネスの篩と最大公約数)
 * @author Takaaki NARA
 * @date 10/08
 */
//算術計算ライブラリ
#include <cmath>
//標準入出力ライブラリ
#include <iostream>
//STL型ライブラリ
#include <vector>
//時間計測用ライブラリ
#include <chrono>

constexpr int64_t MAX_VAL = 1000000;
/**
 * @fn
 * @brief 自然数Nまでの自然数i,jの組の最大公約数が1だったとき配列の対応する箇所に1を格納する
 * @param 自然数N
 * @param 計算結果を格納する配列
 * @return なし
 */
void getCoprime(int64_t N, std::vector<std::vector<bool>> &isCoprime)
{
  //時間計測開始
  auto start = std::chrono::system_clock::now();
  //N+1×N+1のbool型のvectorを1で再定義
  isCoprime.assign(N + 1, std::vector<bool>(N + 1, true));
  int64_t i, j, k;
  //互いに素である組の倍数を削除していくアルゴリズム
  for (i = 1; i <= N; ++i)
  {
    //i,jの組を逆にしても結果は同じなのでj=iから探索する
    for (j = i; j <= N; ++j)
    {
      //互いに素でなければすでにその先の倍数は探索済みなのでjをカウントアップ
      if (!isCoprime[i][j])
      {
        continue;
      }
      //i,jの組の倍数を消していく
      for (k = 2; j * k <= N; ++k)
      {
        isCoprime[i * k][j * k] = false;
        // i,jが逆の組も最大公約数の結果は一緒
        isCoprime[j * k][i * k] = false;
      }
    }
  }
  //時間計測終了
  auto end = std::chrono::system_clock::now();
  // 時間の出力（今回はミリ秒（1/1000秒）を使用）
  std::cout << __func__ << ":" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]" << std::endl;
}

/**
 * @fn
 * @brief エラトステネスの篩を実行する関数(自然数Nまでの素数を探索する)
 * @param 自然数N
 * @param 計算結果を格納する配列
 * @return なし
 */
void sieveOfEratosthenes(int64_t N, std::vector<bool> &isPrime)
{
  //時間計測開始
  auto start = std::chrono::system_clock::now();
  //isPrimeのサイズを変更し配列の要素をtrueで再定義
  isPrime.assign(N + 1, true);
  int64_t i, j, sqrtN;
  //√Nを計算（誤差を考慮して+1している)
  sqrtN = std::sqrt(N) + 1;
  //√Nまで探索
  for (i = 2; i <= sqrtN; ++i)
  {
    //素数でなければすでにその先の倍数は探索済みなのでiをカウントアップ
    if (!isPrime[i])
    {
      continue;
    }
    //jをi*iからスタート（それより小さい値はすでに探索済みのはずなので)
    for (j = i * i; j <= N; j += i)
    {
      isPrime[j] = false;
    }
  }
  // 0と1は素数じゃないので強制的にfalse:w
  isPrime[0] = false;
  isPrime[1] = false;
  //時間計測終了
  auto end = std::chrono::system_clock::now();
  // 時間の出力（今回はミリ秒（1/1000秒）を使用）
  std::cout << __func__ << ":" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]" << std::endl;
}

int main()
{
  //課題aのa配列を宣言
  std::vector<bool> a;
  //課題bのb配列を宣言
  std::vector<std::vector<bool>> b;
  //自然数Nを宣言
  int64_t N;
  //素数の数をカウント(デバック用)
  int64_t counter = 0;
  std::cout << "64bitより小さい自然数を入力してください" << std::endl;
  //外部入力でNに値を代入
  std::cin >> N;
  //64bit:w以上の値，０以下の値，文字列の入力があった場合の例外処理
  if (N > std::pow(2, sizeof(int64_t) * 8) || (N <= 0) || std::cin.fail())
  {
    std::cout << "入力値が不正です" << std::endl;
    return -1;
  }
  //エラトステネスの篩関数(課題1-a)(引数は自然数Nと配列aの先頭のアドレス)
  sieveOfEratosthenes(N, a);
  // 素数の数をカウント
  for (int64_t k = 1; k < a.size(); k++)
  {
    if (a[k] == true)
      counter++;
  }
  std::cout << counter << std::endl;
  std::cout << "自然数を入力してください(完全ではないので数百万程度の値をいれると落ちます）" << std::endl;
  std::cin >> N;
  //MAX_VAL以上の値，０以下の値，文字列の入力があった場合の例外処理
  if (N > MAX_VAL || (N <= 0) || std::cin.fail())
  {
    std::cout << "入力値が不正です" << std::endl;
    return -1;
  }
  //互いに素なペアを列挙する関数(課題1-b)(引数は自然数Nと配列bの先頭のアドレス)
  getCoprime(N, b);

  return 0;
}