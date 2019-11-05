#ifndef INCLUDE_LIST_H
#define INCLUDE_LIST_H

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;           //ノードの中に入っているデータ部分
    struct node *next; //次のノードのアドレス
};
extern struct node head0;
extern struct node *head = &head0;
void list_initialize(void);
struct node *insert_after(int key, struct node *pt);
void print_list(struct node *pt);
void print_whole_list(void);
int insert_sorted_list(int key);
#endif