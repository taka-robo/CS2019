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
    std::cout << __func__ << std::endl;
    stacknum = 0;
}
/**
 * @brief スタックに整数numを入れる
 * @param num:スタックに挿入したい整数
 * @return なし
 */
void push(int num)
{
    std::cout << __func__ << num << ":";
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
        //プログラムを終了
        //exit(0);
    }
    //配列要素番号をディクリメント
    stacknum--;
    //スタックの要素を一時変数に入れておく
    temp = STACK[stacknum];
    //スタックの要素が入っていたところを0で上書き（動作がわかりやすくするため）
    STACK[stacknum] = 0;
    std::cout << __func__ << temp << ":";
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
        return 0;
    }
    else
    {
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
    std::cout << __func__ << std::endl;
    //headの位置を0に
    head = 0;
    //tailの位置を0に
    tail = 0;
    //要素数を0に
    queuenum = 0;
}
/**
 * @brief  キューに整数numを入れる
 * @param num:キューに挿入したい整数
 * @return なし
 */
void put(int num)
{
    std::cout << __func__ << num << ":";
    //要素数がサイズを超えてないかチェック
    if (queuenum + 1 > SIZE)
    {
        printf("Queue is full\n");
        return;
    }
    //tailがサイズ数を超えてかつheadが0以上のときtailを先頭にもってくる
    else if ((tail + 1 > SIZE) && (head > 0))
    {
        tail = 0;
    }
    //tailの位置にnumを挿入
    QUEUE[tail] = num;
    //tailを後ろに1つずらす
    tail++;
    //要素数をインクリメント
    queuenum++;
    printQueue();
}
/**
 * @brief キューから整数を取り出す
 * @return 取り出した整数
 */
int get()
{
    //整数を保管しておく一時変数
    int temp;
    //キューが空かチェック
    if (queueempty() == 0)
    {
        printf("Queue is empty\n");
        //プログラムを終了
        //exit(0);
    }
    //headの値を一時的に保管
    temp = QUEUE[head];
    //headの値を0に（動作をわかりやすくするため）
    QUEUE[head] = 0;
    //headの位置を1つうしろへ
    head++;
    //headがサイズを超えていた場合先頭に戻す
    if (head + 1 > SIZE)
    {
        head = 0;
    }
    //要素数をディクリメント
    queuenum--;
    std::cout << __func__ << temp << ":";
    printQueue();
    return temp;
}
/**
 * @brief キューが空かチェック
 * @return 空だったら非0，中身があったら0
 */
int queueempty()
{
    if (queuenum == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/**
 * @brief キューの中身を表示
 * @return なし
 */
void printQueue()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d,", QUEUE[i]);
    }
    printf("\n");
}