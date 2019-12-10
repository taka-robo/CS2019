/**
 * @file cs3-a1.c
 * @brief 計算基礎工学の課題3a-1
 * @author Takaaki NARA
 * @date 11/19
 */
//標準入出力ライブラリ
#include <iostream>
//自作stack&queueライブラリ
#include "stack_queue.hpp"
//vector型を使うためのライブラリ
#include <vector>

int main(void)
{
    //テスト用の要素
    std::vector<int> array = {8, 5, 3, 4, 7};
    int i;
    //スタックの初期化
    stackinit();
    //スタックが空かチェック
    if (stackempty() == 0)
    {
        std::cout << "stack is empty" << std::endl;
    }
    //キューの初期化
    queueinit();
    //キューが空かチェック
    if (queueempty() == 0)
    {
        std::cout << "queue is empty" << std::endl;
    }

    /*--------------------以下動作確認用テストコード--------------------------*/

    for (i = 0; i < array.size(); i++)
    {
        push(array[i]);
        put(array[i]);
    }
    pop();
    get();
    push(9);
    put(9);
    push(5);
    put(5);
    for (i = 0; i < SIZE + 1; i++)
    {
        pop();
        get();
    }

    return 0;
}