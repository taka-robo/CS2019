#include "stdio.h"
#include "stdlib.h"
struct node
{
    int key;           //ノードの中に入っているデータ部分
    struct node *next; //次のノードのアドレス
};
static struct node head0;
static struct node *head = &head0;
void list_initialize(void)
{
    printf("%s\n", __func__);
    head->next = NULL;
}
struct node *insert_after(int key, struct node *pt) //挿入したいkeyの値と次に挿入したい場所のポイン
{
    struct node *new_node;                              //挿入されるキーを格納するノードへのポインタ
    new_node = (struct node *)malloc(sizeof *new_node); //ノードの確保
    if (new_node == NULL)
    { //確保できなかった場合は
        printf("Not enough memory\n");
        exit(1); //終了
    }
    new_node->key = key;       //新しいノードのキーに値を格納
    new_node->next = pt->next; //new_nodeのnextはptのnext
    pt->next = new_node;       //ptのnextはnew_node
    return new_node;           //new_nodeの先頭アドレスを返す
}
void print_list(struct node *pt)
{
    struct node *p;
    for (p = pt; p != NULL; p = p->next)
    {
        printf("%d -> ", p->key); //pのkeyを表示して
    }
    printf("\n");
}
void print_whole_list(void)
{
    struct node *p;
    for (p = head->next; p != NULL; p = p->next)
    {
        printf("%d -> ", p->key); //pのkeyを表示して
    }
    printf("\n");
}
int insert_sorted_list(int key)
{
    struct node *p;
    struct node *insert_pt = head;
    for (p = head->next; p != NULL && p->key <= key; insert_pt = p, p = p->next)
    {
        if (key == p->key)
        {
            return 1;
        }
    }
    insert_after(key, insert_pt);
    return 0;
}
void delete_all(void)
{
    printf("%s\n", __func__);
    struct node *p;
    struct node *temp;
    for (p = head->next; p != NULL; p = temp)
    {
        temp = p->next;
        free(head->next);
        head->next = temp;
    }
}
int main(void)
{
    int i;
    int index[10] = {8, 12, 1, 8, 10, 0, 5, 3, 8, 4};
    list_initialize();
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
        print_whole_list();
    }

    delete_all();
    print_whole_list();
    return 0;
}