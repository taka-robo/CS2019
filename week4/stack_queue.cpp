#include <iostream>
#include "stack_queue.hpp"
//スタックに用いる配列
int STACK[SIZE] = {};
int QUEUE[SIZE] = {};
//stack配列要素番号
int stacknum;
//キュー先頭要素番号
int head;
//キュー末尾要素番号
int tail;
//キューの配列内に入っている要素数
int queuenum;
/**
 * @brief スタック配列の初期化
 * @return なし
 */
void stackinit()
{
    stacknum = 0;
}
/**
 * @brief スタックに整数numを入れる
 * @param num:スタックに挿入したい整数
 * @return なし
 */
void push(int num)
{
    //スタックが一杯かどうかをチェック
    if (stacknum + 1 > SIZE)
    {
        printf("Stack is full\n");
        return;
    }
    //STACKNUMが示すところにnumを代入
    STACK[stacknum] = num;
    //配列要素番号をインクリメント
    stacknum++;
    printStack();
}
/**
 * @brief スタックから整数を取り出す
 * @return 取り出した整数
 */
int pop()
{
    //要素を一時的に保管しておく変数
    int temp;
    //スタックが空かチェック
    if (stackempty() == 0)
    {
        printf("Stack is empty\n");
        exit(0);
    }
    //配列要素番号をディクリメント
    stacknum--;
    //スタックの要素を一時変数に入れておく
    temp = STACK[stacknum];
    //スタックの要素が入っていたところを0で上書き（動作がわかりやすくするため）
    STACK[stacknum] = 0;
    printStack();
    return temp;
}
/**
 * @brief スタックが空かチェック
 * @return 空だったら非0，中身があったら0
 */
int stackempty()
{
    if (0 == stacknum)
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        printf("Stack is not empty\n");
        return 1;
    }
}
/**
 * @brief スタックの中身を表示
 * @return なし
 */
void printStack()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d,", STACK[i]);
    }
    printf("\n");
}
/**
 * @brief キュー配列を初期化
 * @return なし
 */
void queueinit()
{
    head = 0;
    tail = 0;
    queuenum = 0;
}
/**
 * @brief  キューに整数numを入れる
 * @param num:キューに挿入したい整数
 * @return なし
 */
void put(int num)
{

    if (queuenum + 1 > SIZE)
    {
        printf("Queue is full\n");
        return;
    }
    else if ((tail + 1 > SIZE) && (head > 0))
    {
        tail = 0;
    }

    QUEUE[tail] = num;
    tail++;
    queuenum++;
    //先頭に戻す
    printQueue();
}
int get()
{
    int temp;
    if (queueempty() == 0)
    {
        printf("Queue is empty\n");
        //exit(0);
    }
    temp = QUEUE[head];
    QUEUE[head] = 0;
    head++;
    if (head + 1 > SIZE)
    {
        head = 0;
    }
    queuenum--;
    printQueue();
    return head;
}
int queueempty()
{
    if (queuenum == 0)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        printf("Queue is not empty\n");
        return 1;
    }
}
void printQueue()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d,", QUEUE[i]);
    }
    printf("\n");
}