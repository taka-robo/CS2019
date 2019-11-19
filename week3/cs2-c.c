/**
 * @file cs2-c.c
 * @brief 計算基礎工学の課題2b:リストの基本操作
 * @author Takaaki NARA
 * @date 11/18
 */
//標準入出力ライブラリ
#include "stdio.h"
//自作リスト構造用ライブラリ
#include "list.h"

int main(void)
{
    int i;                                                    //for文よう変数
    int index1[9] = {1, 2, 3, 3, 4, 5, 7, 9, 10};             //動作確認用リスト1
    int index2[10] = {1, 2, 5, 5, 6, 8, 9, 10, 11, 12};       //動作確認用リスト2
    int index3[12] = {1, 2, 3, 11, 12, 4, 5, 8, 9, 6, 7, 10}; //動作確認用リスト3
    struct node list1, list2, list3, list4;
    struct node *head1 = &list1, *head2 = &list2, *head3 = &list3;
    struct node *temp;   //一時変数
    struct node *result; //結果
    head1->next = NULL;  //末尾をNULLで初期化
    head2->next = NULL;  //末尾をNULLで初期化
    head3->next = NULL;  //末尾をNULLで初期化
    temp = head1;
    for (i = 0; i < 9; i++)
    {
        temp = insert_after(index1[i], temp);
    }
    temp = head2;
    for (i = 0; i < 10; i++)
    {
        temp = insert_after(index2[i], temp);
    }
    temp = head3;
    for (i = 0; i < 12; i++)
    {
        result = insert_after(index3[i], temp);
    }
    printf("merge input list\n");
    print_whole_list(head1);
    print_whole_list(head2);
    result = merge(head2, head1);
    printf("merge result ");
    print_whole_list(result);
    printf("natural sort input list\n");
    print_whole_list(head3);
    naturalsort(head3);
    printf("natural sort result ");
    print_whole_list(head3);
    return 0;
}