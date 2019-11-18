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