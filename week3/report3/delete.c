/**
 * @brief 指定されたkeyを持つノードを削除する
 * @param key:削除したい値
 * @return 0:削除できなかった
 *         1:削除
 */
int delete (int key)
{
    struct node *p;
    struct node *temp;
    //リストの最後までfor文を回す
    for (p = head->next; p != NULL; p = p->next)
    {
        if (p->next != NULL && key == p->next->key)
        {//pの次のノードがkeyと同じ値であった場合
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