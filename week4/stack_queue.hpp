#ifndef INCLUDE_STAKC_QUEUE_HPP
#define INCLUDE_STACK_QUEUE_HPP

#include <iostream>
#define SIZE 4
void stackinit();   // stackを初期化して空にする
void push(int num); // stackに整数numを入れる
int pop();          // stackから整数を1つ取り出す
int stackempty();   // stackが空だったら非0の整数を返し，中身があったら0を返す．
void printStack();
void queueinit();  // queueを初期化して空にする
void put(int num); // queueに整数numを入れる
int get();         // queueから整数を1つ取り出す
int queueempty();  // queueが空だったら非0の整数を返し，中身があったら0を返す．
void printQueue();
#endif