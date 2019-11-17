#include "stdio.h"
#include "list.h"

struct node head0;
struct node *head;
void list_initialize(void)
{
    printf("%s\n", __func__);
    head = &head0;
    head->next = NULL;
}
/**
 * @brief 指定したポインタの後ろにkeyの値を挿入 
 * @param key:配列に格納したい変数
 * @param pt:挿入したい位置の前のノードのポインタ
 * @return 新しく挿入したノードのアドレス
 * 　　
 */
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
void print_whole_list(struct node *pt)
{
    printf("%s\n", __func__);
    for (pt = pt->next; pt != NULL; pt = pt->next)
    {
        printf("%d -> ", pt->key); //pのkeyを表示して
    }
    printf("\n");
}
/**
 * @brief 配列の中にkeyと同値が存在するか探索し存在しなければ昇順の適切な位置に挿入する．
 * @param key:配列に格納したい変数
 * @return 配列に既にkeyが存在すれば1(Yesの意味)
 * 　　　　 存在しなければ0(Noの意味)
 */
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
int delete (int key)
{
    struct node *p;
    struct node *temp;
    for (p = head->next; p != NULL; p = p->next)
    {
        if (p->next != NULL && key == p->next->key)
        {
            temp = p->next->next;
            free(p->next);
            p->next = temp;
            printf("hit and delete\n");
            return 1;
        }
    }
    printf("no hit\n");
    return 0;
}
void oddeven(struct node *nodehead, struct node *oddhead, struct node *evenhead)
{
    printf("%s\n", __func__);
    struct node *oddlist = oddhead, *evenlist = evenhead, *p;
    for (p = nodehead->next; p != NULL; p = p->next)
    {
        //遇奇判定
        if ((p->key) % 2 == 0)
        {
            oddlist->next = p;
            oddlist = oddlist->next;
        }
        else
        {
            evenlist->next = p;
            evenlist = evenlist->next;
        }
    }
    oddlist->next = NULL;
    evenlist->next = NULL;
}