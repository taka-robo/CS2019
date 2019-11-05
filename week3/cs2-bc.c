#include "stdio.h"
#include "stdlib.h"
//#include "list.h"
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
    printf("%s\n", __func__);
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
    printf("%s\n", __func__);
    struct node *p;
    for (p = pt; p != NULL; p = p->next)
    {
        printf("%d -> ", p->key); //pのkeyを表示して
    }
    printf("\n");
}
void print_whole_list(void)
{
    printf("%s\n", __func__);
    struct node *p;
    for (p = head->next; p != NULL; p = p->next)
    {
        printf("%d -> ", p->key); //pのkeyを表示して
    }
    printf("\n");
}
void sort_list()
{
    printf("%s\n", __func__);
    struct node *temp, *i, *j;
    for (i = head->next; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {

            if (i->key > j->key)
            {
                temp->next = i->next;
                i->next = j->next;
                j->next = temp->next;
            }
        }
    }
}
int insert_sorted_list(int key)
{
    printf("%s\n", __func__);
    struct node *p;
    for (p = head->next; p != NULL; p = p->next)
    {
        if (key == p->key)
        {
            sort_list();
            print_whole_list();
            return 1;
        }
        // if (NULL == p->next)
        // {
        //     insert_after(key, p);
        // }
    }
    insert_after(key, head);
    sort_list();
    print_whole_list();
    return 0;
}
int main(void)
{
    list_initialize();
    printf("%d\n", insert_sorted_list(8));
    printf("%d\n", insert_sorted_list(12));
    printf("%d\n", insert_sorted_list(1));
    printf("%d\n", insert_sorted_list(8));
    printf("%d\n", insert_sorted_list(10));
    printf("%d\n", insert_sorted_list(5));
    printf("%d\n", insert_sorted_list(0));
    printf("%d\n", insert_sorted_list(3));
    print_whole_list();
    return 0;
}