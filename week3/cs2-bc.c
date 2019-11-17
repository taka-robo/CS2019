/**
 * @file cs2-bc.c
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
    int index[10] = {8, 12, 1, 8, 10, 0, 5, 3, 8, 4};
    struct node oddhead, evenhead;
    list_initialize();
    oddhead.next = NULL;
    evenhead.next = NULL;
    for (i = 0; i < 10; ++i)
    {
        if (insert_sorted_list(index[i]) == 1)
        {
            printf("%d has been inserted.\n", index[i]);
        }
        else
        {
            printf("%d was inserted.\n", index[i]);
        }
        print_whole_list(head);
    }
    delete (5);
    print_whole_list(head);
    oddeven(head, &oddhead, &evenhead);
    print_whole_list(head);
    print_whole_list(&oddhead);
    print_whole_list(&evenhead);
    return 0;
}