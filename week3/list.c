#include "stdio.h"
#include "list.h"

// struct node head0;
// struct node *head;
// void list_initialize(void)
// {
//     head = &head0;
//     head->next = NULL;
// }
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
/**
 * @brief 指定したリストの中身をすべて表示する
 * @param *pt:表示したいリストの先頭のアドレス
 */
void print_whole_list(struct node *pt)
{
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
int insert_sorted_list(struct node *head, int key)
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
/**
 * @brief 配列の中にkeyと同値が存在するか探索し存在しなければ昇順の適切な位置に挿入する．
 * @param key:配列に格納したい変数
 * @return 配列に既にkeyが存在すれば1(Yesの意味)
 * 　　　　 存在しなければ0(Noの意味)
 */
int insert_sorted_list2(struct node *pt, int key)
{
    struct node *insert_pt = pt;
    for (pt = pt->next; pt != NULL && pt->key <= key; insert_pt = pt, pt = pt->next)
    {
        if (key == pt->key)
        {
            return 1;
        }
    }
    insert_after(key, insert_pt);
    return 0;
}
/**
 * @brief listの全ノードを削除する
 * @return なし
 */
void delete_all(struct node *head)
{
    struct node *p;
    struct node *temp;
    //pの値がNULLになるまで繰り返す
    for (p = head->next; p != NULL; p = p->next)
    {
        //headの次の次のノードアドレスを一時変数に記憶しておく
        temp = p->next;
        //headの次のノードのメモリを開放する
        free(head->next);
        //headの次のノードを記憶しておいた次の次のノードのアドレスにつなぎ直す．
        head->next = temp;
    }
}
/**
 * @brief 指定されたkeyを持つノードを削除する
 * @param key:削除したい値
 * @return 0:削除できなかった
 *         1:削除
 */
// int delete (int key)
// {
//     struct node *p;
//     struct node *temp;
//     //リストの最後までfor文を回す
//     for (p = head; p != NULL; p = p->next)
//     {
//         if (p->next != NULL && key == p->next->key)
//         { //pの次のノードがkeyと同じ値であった場合
//             //削除したいノードの次のノードのアドレスを一時変数に記憶させておく
//             temp = p->next->next;
//             //keyと同じ値を持つノードのメモリを開放
//             free(p->next);
//             //pのnextに削除したノードの次のノードのアドレスを格納
//             p->next = temp;
//             //削除したので1を返す
//             return 1;
//         }
//     }
//     //keyと同じ値がなければ0を返す
//     return 0;
// }
/**
 * @brief 指定されたkeyを持つノードを削除する
 * @param p:削除したいリストの先頭のアドレス
 * @param key:削除したい値
 * @return 0:削除できなかった
 *         1:削除
 */
int delete2(struct node *p, int key)
{
    struct node *temp;
    //リストの最後までfor文を回す
    for (; p != NULL; p = p->next)
    {
        if (p->next != NULL && key == p->next->key)
        { //pの次のノードがkeyと同じ値であった場合
            //削除したいノードの次のノードのアドレスを一時変数に記憶させておく
            temp = p->next->next;
            //keyと同じ値を持つノードのメモリを開放
            free(p->next);
            //pのnextに削除したノードの次のノードのアドレスを格納
            p->next = temp;
            //削除したので1を返す
            return 1;
        }
    }
    //keyと同じ値がなければ0を返す
    return 0;
}
/**
 * @brief 与えられたリストについてkeyが偶数なら偶数リストへ奇数なら奇数リストに分割する
 * @param *head:分割したいリストの先頭のアドレス
 *        *oddhead:奇数リストの先頭のアドレス
 *        *evenhead:偶数リストの先頭のアドレス
 */
void oddeven(struct node *head, struct node *oddhead, struct node *evenhead)
{
    //操作用の変数を作成
    struct node *oddlist = oddhead, *evenlist = evenhead, *p;
    //headの最後までfor文を回す
    for (p = head->next; p != NULL; p = p->next)
    {
        //遇奇判定
        if ((p->key) % 2 != 0)
        {
            //奇数の場合奇数リストにpのアドレスを追加する
            oddlist->next = p;
            //oddlistが指す場所を更新
            oddlist = oddlist->next;
        }
        else
        {
            //動作は奇数と同様
            evenlist->next = p;
            evenlist = evenlist->next;
        }
    }
    //リストの最後にNULLを追加して終了
    oddlist->next = NULL;
    evenlist->next = NULL;
}
struct node *merge(struct node *head1, struct node *head2)
{
    printf("%s\n", __func__);
    static struct node merge0;
    struct node *merge = &merge0;
    merge->next = NULL;
    struct node *i = head1->next, *j = head2->next, *p = merge, *temp;
    for (i = head1->next; i != NULL; i = temp)
    {
        for (j = head2->next; j != NULL; j = temp)
        {
            temp = j->next;
            if (i->key > j->key)
            {
                p->next = j;
                p = p->next;
                head2->next = temp;
            }
            // else if (i->key == j->key)
            // {
            //     delete2(head2, j->key);
            // }
        }
        temp = i->next;
        p->next = i;
        p = p->next;
        head1->next = temp;
    }
    p->next = head2->next;
    head2->next = NULL;
    return merge;
}
void naturalsort(struct node *head)
{
    struct node sorted_list1, sorted_list2; //昇順部分リスト1,2
    struct node *head1 = &sorted_list1, *head2 = &sorted_list2;
    struct node *p, *temp; //for文処理用変数，一時退避用変数

    //与えられたリストの先頭をhead1に置き換え
    head1->next = head->next;
    //head2のnextをNULLで初期化
    head2->next = NULL;
    //headのnextをNULLで再初期化
    head->next = NULL;
    for (p = head1->next; p != NULL; p = p->next)
    {
        //昇順になっていないところを探索
        if (p->next != NULL && p->key > p->next->key)
        {
            //一回目の区切り,リスト1を確定　
            if (NULL == head2->next)
            {
                head2->next = p->next;
                //sorted_list1の末尾をNULLに
                p->next = NULL;
                //探査をhead2からに変更
                p = head2;
            } //二回目の区切り
            else if (NULL != head2->next)
            {
                //昇順になっていないリストの先頭のアドレスであるheadのnextをpのnextに
                head->next = p->next;
                //sorted_list2の末尾をNULLにsorted_list2を確定
                p->next = NULL;
                //探索をheadに切り替える
                p = head;
                //部分リストが2つ確定したのでhead1とhead2をマージ
                temp = merge(head1, head2);
                //headの末尾にhead1とhead2をマージしたものをマージ
                merge_end(head, temp);
                //昇順になっていないので再帰呼び出し
                naturalsort(head);
                //再帰から抜けた場合昇順になっているので関数を終了
                return;
            }
        }
    }
    //headを2つにしか分割できなかった場合あと一回マージすれば昇順になる
    temp = merge(head1, head2);
    merge_end(head, temp);
}
void merge_end(struct node *head1, struct node *head2)
{
    struct node *p;
    for (p = head1; p->next != NULL; p = p->next)
    {
        //空の処理
    }
    //headの末尾にhead2をマージ
    p->next = head2->next;
}