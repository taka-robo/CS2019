/**
 * @file cs3-a1.c
 * @brief 計算基礎工学の課題3a-1
 * @author Takaaki NARA
 * @date 11/19
 */
//標準入出力ライブラリ
#include <iostream>
//自作listライブラリ
#include "list.hpp"
//vector型を使うためのライブラリ
#include <vector>
int main(void)
{
    //スタックとキューに使うリストの宣言
    node stackhead, queuehead;
    node *shead = &stackhead, *qhead = &queuehead;
    //テスト用の要素
    std::vector<int> array = {8, 5, 3, 4, 7};
    unsigned int i;
    //スタックを初期化
    stackinit(shead);
    //スタックが空かチェック
    stackempty(shead);
    //キューを初期化
    queueinit(qhead);
    //キューが空かチェック
    queueempty(qhead);

    /*---------------------------以下動作確認用テスト--------------------------------*/

    for (i = 0; i < array.size(); i++)
    {
        push(shead, array[i]);
        put(qhead, array[i]);
    }
    pop(shead);
    get(qhead);
    push(shead, 9);
    put(qhead, 9);
    push(shead, 5);
    put(qhead, 5);
    for (i = 0; i < array.size() + 2; i++)
    {
        pop(shead);
        get(qhead);
    }
    return 0;
}