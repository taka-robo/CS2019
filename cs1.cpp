/**
 * @file ec1.cpp
 * @brief 計算基礎工学の課題1(エラトステネスの篩と最大公約数)
 * @author Takaaki NARA
 * @date 10/08
 */

#include <algorithm>
#include <cmath>
//標準入出力ライブラリ
#include <iostream>
//vector型ライブラリ
#include <vector>
//時間計測用ライブラリ
#include <chrono>
//数値計算用ライブラリ(動作検証用(gcd))
#include <numeric>

/**
 * @fn
 * @brief 2つの配列の中身が等しいかを調べる関数（作成したアルゴリズムがあっているか検証するため）
 * @param 検証したい配列(1次元配列)
 * @param 正しい答えの配列(1次元配列)
 * @return 中身が等しい:true,中身が等しくない:false
 */
bool checkArray(std::vector<bool> &a, std::vector<bool> &b)
{
  std::cout << __func__ << std::endl;
  if (a.size() != b.size())
  {
    std::cout << "配列の大きさが違います" << std::endl;
    return false;
  }
  for (int64_t i = 1, n = a.size(); i < n; ++i)
  {
    if (a[i] != b[i])
    {
      std::cout << "Mismatch" << i << std::endl;
      return false;
    }
  }
  std::cout << "Matched" << std::endl;
  return true;
}
/**
 * @fn
 * @brief 2つの配列の中身が等しいかを調べる関数（課題があってるか確認するため）
 * @param 検証したい配列(2次元配列)
 * @param 正しい答えの配列(2次元配列)
 * @return 中身が等しい:true,中身が等しくない:false
 */
bool checkArray2D(std::vector<std::vector<bool>> &a, std::vector<std::vector<bool>> &b)
{
  std::cout << __func__ << std::endl;
  if ((a.size() != b.size()) || (a.at(0).size() != b.at(0).size()))
  {
    std::cout << "配列の大きさが違います" << std::endl;
    return false;
  }
  for (int64_t i = 0, n = a.size(); i < n; ++i)
  {
    for (int64_t j = 0, n = a.at(0).size(); j < n; ++j)
    {
      if (a[i][j] != b[i][j])
      {
        std::cout << "Mismatch" << i << ":" << j << std::endl;
        std::cout << a[i][j] << ":" << b[i][j] << std::endl;
        return false;
      }
    }
  }
  std::cout << "Matched" << std::endl;
  return true;
}
/**
 * @fn
 * @brief 自然数Nまでの自然数i,jの組の最大公約数が1だったとき配列の対応する箇所に1を格納する(ユークリッドのやつ)
 * @param 自然数N
 * @param 計算結果を格納する配列
 * @return なし
 */
void getCoprimeyuqlid(int64_t N, std::vector<std::vector<bool>> &isCoprime)
{
  auto start = std::chrono::system_clock::now();
  isCoprime.assign(N + 1, std::vector<bool>(N + 1, true));
  int64_t i, j;
  for (i = 1; i <= N; ++i)
  {
    for (j = i; j <= N; ++j)
    {
      if (std::gcd(i, j) != 1)
      {
        isCoprime[i][j] = false;
        isCoprime[j][i] = false;
      }
    }
  }
  auto end = std::chrono::system_clock::now();
  std::cout << __func__ << ":" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "[ms]" << std::endl;
}
/**
 * @fn
 * @brief 自然数Nまでの自然数i,jの組の最大公約数が1だったとき配列の対応する箇所に1を格納する
 * @param 自然数N
 * @param 計算結果を格納する配列
 * @return なし
 */
void getCoprime(int64_t N, std::vector<std::vector<bool>> &isCoprime)
{
  auto start = std::chrono::system_clock::now();
  isCoprime.assign(N + 1, std::vector<bool>(N + 1, true));
  int64_t i, j, k, ik, jk;
  for (i = 1; i <= N; ++i)
  {
    for (j = i; j <= N; ++j)
    {
      if (!isCoprime[i][j])
      {
        continue;
      }
      for (k = 2; j * k <= N; ++k)
      {
        ik = i * k;
        jk = j * k;
        isCoprime[ik][jk] = false;
        // i,jが逆の組も最大公約数の結果は一緒
        isCoprime[jk][ik] = false;
      }
    }
  }
  auto end = std::chrono::system_clock::now();
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
  //aのサイズを変更し配列の要素をtrueで初期化
  isPrime.assign(N + 1, true);
  int64_t i, j, sqrtN;
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
  // 時間の出力（今回はマイクロ秒（1/1000000秒）を使用）
  std::cout << __func__ << ":" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "[us]" << std::endl;
}

int main()
{
  //課題aのa配列を宣言
  std::vector<bool> a;
  //課題検証用のa配列を宣言
  std::vector<bool> a2;
  //課題bのb配列を宣言
  std::vector<std::vector<bool>> b;
  //課題検証用の配列宣言
  std::vector<std::vector<bool>> b2;
  //自然数Nを宣言
  int64_t N = 100000;
  //int64_t N = 100;
  int64_t counter = 0; //素数の数をカウント(デバック用)
  //外部入力でNに値を代入
  std::cout << N << std::endl;
  if (N > std::pow(2, sizeof(int64_t) * 8) || (N <= 0))
  {
    std::cout << "64bitより大きい自然数には対応してないです" << std::endl;
    return -1;
  }
  //エラトステネスの篩関数(課題1-a)(引数は自然数Nと配列aの先頭のアドレス)
  sieveOfEratosthenes(N, a);
  // 配列aの中身を表示
  for (int64_t k = 1; k < a.size(); k++)
  {
    // std::cout << k << ":" << a[k] << " ";
    if (a[k] == true)
      counter++;
    //見やすくするために10の倍数ごとに改行
    // if (k % 10 == 0)
    //   std::cout << std::endl;
  }
  //互いに素なペアを列挙する関数(課題1-b)(引数は自然数Nと配列bの先頭のアドレス)
  getCoprime(100000, b);
  //getCoprimeyuqlid(N, b2);
  //checkArray2D(b, b2);
  std::cout << counter << std::endl;
  return 0;
}