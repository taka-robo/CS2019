/**
 * @file ec1.cpp
 * @brief 計算基礎工学の課題1(多桁の階乗計算)
 * @author Takaaki NARA
 * @date 10/24
 */
//算術計算ライブラリ
#include <cmath>
//標準入出力ライブラリ
#include <iostream>
//出力整形ライブラリ
#include <iomanip>
//STL型ライブラリ
#include <vector>
//時間計測用ライブラリ
#include <chrono>
//配列一要素に格納する桁数
constexpr int8_t Scale = 8;
//計算する桁数
constexpr int8_t Length = Scale * 9;
//配列の要素数
constexpr int32_t ArrayNum = (Length + 7) / Scale;
//桁をシフトする大きさ
int32_t Shift = std::pow(10, Scale);
/**
 * @fn
 * @brief 多桁の掛け算を行う関数 
 * @param かけられる配列
 * @param 掛けるあたい
 * @return なし
 */

void multi(std::vector<int32_t> &a, int32_t k)
{
  int64_t carry = 0, w;
  //入力されたnを配列nに分割して格納(あとで実装)
  int32_t i;
  for (i = ArrayNum; i >= 0; --i)
  {
    w = a[i];
    a[i] = (w * k + carry) % Shift;
    carry = (w * k + carry) / Shift;
  }
}

/**
 * @fn
 * @brief 結果を確認するために配列を表示する関数 
 * @param 表示したい配列 
 * @return なし
 */

void show(std::vector<int32_t> &result)
{
  int64_t i;
  for (i = 0; i < ArrayNum; ++i)
  {
    printf("%08d,", result[i]);
  }
  std::cout << std::endl;
}
/**
 * @fn
 * @brief 自然数Nの階乗を計算する関数（64bit以上の計算結果に対応）
 * @param 自然数N
 * @param 結果を格納する配列
 * @return なし
 */

void factrial(int32_t N, std::vector<int32_t> &result)
{
  int32_t i;
  result[ArrayNum - 1] = 1;
  //0!=1の例外処理
  if (N == 0)
  {
    show(result);
    return;
  }
  else
  {
    //iがNになるまでresultにiをかけていく
    for (i = 1; i <= N; ++i)
    {
      //多桁の掛け算を行う関数
      multi(result, i);
      printf("%4d!=", i);
      //計算結果を表示する関数
      show(result);
    }
  }
}
int main()
{
  //入力される階乗数を格納する変数
  int32_t N;
  //計算結果を格納する配列
  std::vector<int32_t> result(Length, 0);
  std::cout << "50より小さい自然数を入力してください" << std::endl;
  //値の入力
  std::cin >> N;
  //32bit以上の値，０以下の値，文字列の入力があった場合の例外処理
  if (N > 50 || (N < 0) || std::cin.fail())
  {
    std::cout << "入力値が不正です" << std::endl;
    return -1;
  }
  factrial(N, result);

  return 0;
}