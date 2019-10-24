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
//STL型ライブラリ
#include <vector>
//時間計測用ライブラリ
#include <chrono>

constexpr int64_t MAX_VAL = 1000000;
/**
 * @fn
 * @brief 自然数Nの階乗を計算する関数（64bit以上の計算結果に対応）
 * @param 自然数N
 * @return なし
 */

void factrial(int64_t N)
{
  int64_t carry = 0;
  std::vector<int32_t> n = {100, 000, 000};
  std::vector<int32_t> temp;
  temp.resize(n.size());

  //入力されたNを配列nに分割して格納(あとで実装)
  size_t i;
  for (i = n.size() - 1; i >= 0; --i)
  {
    carry = n[i] * temp[i] + carry;
    n[i] = carry % 10000;
  }
}
int main()
{
  int64_t N;
  std::cout << "64bitより小さい自然数を入力してください" << std::endl;
  //64bit:w以上の値，０以下の値，文字列の入力があった場合の例外処理
  if (N > std::pow(2, sizeof(int64_t) * 8) || (N <= 0) || std::cin.fail())
  {
    std::cout << "入力値が不正です" << std::endl;
    return -1;
  }

  return 0;
}