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
extern struct node *head;
void list_initialize(void);
struct node *insert_after(int key, struct node *pt);
void print_list(struct node *pt);
void print_whole_list(struct node *pt);
int insert_sorted_list(int key);
int insert_sorted_list2(struct node *pt, int key);
void delete_all(void);
int delete (int key);
int delete2(struct node *p, int key);
void oddeven(struct node *head, struct node *oddhead, struct node *evenhead);
struct node *merge(struct node *head1, struct node *head2);
#endif