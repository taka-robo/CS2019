/**
 * @brief listの全ノードを削除する
 * @return なし
 */
void delete_all(void)
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
        //headの次のノードを，tempに記憶しておいた次の次のノードのアドレスにつなぎ直す．
        head->next = temp;
    }
}