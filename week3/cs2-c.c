/**
 * @file cs2-c.c
 * @brief 計算基礎工学の課題2b:リストの基本操作
 * @author Takaaki NARA
 * @date 11/18
 */
#include "stdio.h"
#include "stdlib.h"
#include "list.h"

int main(void)
{
    int i;
    int index1[9] = {1, 2, 3, 3, 4, 5, 7, 9, 10};
    int index2[10] = {1, 2, 5, 5, 6, 8, 9, 10, 11, 12};
    struct node list1, list2;
    struct node *head1 = &list1, *head2 = &list2, *result;

    head1->next = NULL;
    head2->next = NULL;
    result = head1;
    for (i = 0; i < 9; i++)
    {
        result = insert_after(index1[i], result);
    }
    result = head2;
    for (i = 0; i < 10; i++)
    {
        result = insert_after(index2[i], result);
    }
    print_whole_list(head1);
    print_whole_list(head2);
    result = merge(head2, head1);
    printf("result ");
    print_whole_list(result);
    return 0;
}