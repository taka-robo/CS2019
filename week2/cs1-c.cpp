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
//計算する桁数
constexpr int8_t Length = 64;
//配列一要素に格納する桁数
constexpr int8_t Scale = 8;
//配列の要素数
constexpr int32_t ArrayNum = (Length + 7) / Scale;
//桁をシフトする大きさ
int32_t Shift = std::pow(10, Scale);
/**
 * @fn
 * @brief 自然数Nの階乗を計算する関数（64bit以上の計算結果に対応）
 * @param 自然数N
 * @return なし
 */

void multi(std::vector<int32_t> &a, int32_t b, std::vector<int32_t> &c)
{
  int64_t carry = 0, w;
  //入力されたnを配列nに分割して格納(あとで実装)
  int32_t i;
  for (i = ArrayNum; i >= 0; --i)
  {
    w = a[i];
    c[i] = (w * b + carry) % Shift;
    carry = (w * b + carry) / Shift;
  }
}
void show(std::vector<int32_t> &result)
{
  int64_t i;
  for (i = 0; i < ArrayNum; ++i)
  {
    printf("%08d,", result[i]);
  }
  std::cout << std::endl;
}
void factrial(int64_t N, std::vector<int32_t> &result)
{
  int32_t i;
  result[ArrayNum - 1] = 1;
  for (i = 1; i <= N; ++i)
  {
    multi(result, i, result);
    printf("%4d!=", i);
    show(result);
  }
}
int main()
{
  int32_t N;
  //計算結果を格納する配列
  std::vector<int32_t> result(Length, 0);
  std::cout << "32bitより小さい自然数を入力してください" << std::endl;
  std::cin >> N;
  //64bit:w以上の値，０以下の値，文字列の入力があった場合の例外処理
  if (N > std::pow(2, sizeof(int32_t) * 8) || (N <= 0) || std::cin.fail())
  {
    std::cout << "入力値が不正です" << std::endl;
    return -1;
  }
  factrial(N, result);

  return 0;
}