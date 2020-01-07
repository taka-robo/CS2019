#include <iostream>
#include "./include/stack_queue.hpp"
//スタックに用いる配列
int STACK[SIZE] = {};
int QUEUE[SIZE] = {};
//stack配列要素番号
extern int stacknum;
//キュー先頭要素番号
extern int head;
//キュー末尾要素番号
extern int tail;
//キューの配列内に入っている要素数
extern int queuenum;
void stackinit()
{
    stacknum = 0;
}
void push(int num)
{
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
int pop()
{
    int temp;
    if (stackempty() == 0)
    {
        printf("Stack is empty\n");
        //exit(0);
    }
    //配列要素番号をディクリメント
    stacknum--;
    temp = STACK[stacknum];
    STACK[stacknum] = 0;
    printStack();
    return temp;
}
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
void printStack()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d,", STACK[i]);
    }
    printf("\n");
}
void queueinit()
{
    head = 0;
    tail = 0;
    queuenum = 0;
}
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
void printQueue();
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d,", QUEUE[i]);
    }
    printf("\n");
}