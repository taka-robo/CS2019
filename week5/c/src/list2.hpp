#ifndef INCLUDE_LIST2_H
#define INCLUDE_LIST2_H

#include <iostream>

struct point
{
    int col = 0;
    int row = 0;
    int step = 0;
};
struct node
{
    struct point cell;
    struct node *next; //次のノードのアドレス
};

// void list_initialize(struct node *head);
struct node *insert_after(struct point point, struct node *pt);
void print_whole_list(struct node *pt);
void delete_all(struct node *head);

void stackinit(struct node *head);
void push(struct node *head, int col, int row, int step);
struct point pop(struct node *head);
int stackempty(struct node *head);

void queueinit(struct node *head);
void put(struct node *head, int col, int row, int step);
struct point get(struct node *head);
int queueempty(struct node *head);

struct point delete_next(struct node *pt);
#endif