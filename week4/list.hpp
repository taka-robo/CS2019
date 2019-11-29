#ifndef INCLUDE_LIST_H
#define INCLUDE_LIST_H

#include <iostream>

struct node
{
    int key;           //ノードの中に入っているデータ部分
    struct node *next; //次のノードのアドレス
};

// void list_initialize(struct node *head);
struct node *insert_after(int key, struct node *pt);
void print_whole_list(struct node *pt);
void delete_all(struct node *head);

void stackinit(struct node *head);
void push(struct node *head, int num);
int pop(struct node *head);
int stackempty(struct node *head);

void queueinit(struct node *head);
void put(struct node *head, int num);
int get(struct node *head);
int queueempty(struct node *head);

int delete_next(struct node *pt);
#endif