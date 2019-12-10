#include "list.hpp"

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
 * @brief スタックリストの初期化
 * @param *head:スタックリストに使うリストの先頭のアドレス 
 * @return なし
 */
void stackinit(struct node *head)
{
    std::cout << __func__ << std::endl;
    head->next = NULL;
}
/**
 * @brief スタックに整数numを入れる
 * @param *head:スタックリストに使うリストの先頭のアドレス 
 * @param  num:スタックに入れたい整数 
 * @return なし
 */
void push(struct node *head, int num)
{
    std::cout << __func__ << ":" << num << "  ";
    struct node *p;
    for (p = head; p->next != NULL; p = p->next)
    {
        //リストの末尾までnextを辿っていく処理（効率が悪い）
    }
    //リストの末尾の次にnumを挿入
    insert_after(num, p);
    print_whole_list(head);
}
/**
 * @brief スタックから整数を一つとりだす
 * @param *head:スタックリストに使うリストの先頭のアドレス 
 * @return 取り出した整数
 */
int pop(struct node *head)
{
    std::cout << __func__;
    int temp;
    struct node *p;
    if (stackempty(head) == 0)
    {
        for (p = head; p->next->next != NULL; p = p->next)
        {
            //リストの末尾の一個前までリストを辿っていく処理（効率が悪い）
        }
    }
    else
    {
        std::cout << " stack is empty" << std::endl;
        //空のスタックからpopしようとしたのでプログラムを終了
        //exit(1);
        return 0;
    }
    //pの次の要素の値を取得し削除
    temp = delete_next(p);
    std::cout << ":" << temp << "   ";
    print_whole_list(head);
    return temp;
}
/**
 * @brief スタックが空だったら非0の整数を返し，中身があったら0を返す
 * @param *head:スタックリストに使うリストの先頭のアドレス 
 * @return 非0:スタックが空
 *           0:スタックに中身がある
 */
int stackempty(struct node *head)
{
    //headの後ろに要素が存在すれば0を返す，なければ非0を返す
    if (head->next != NULL)
    {
        //中身が存在するので0を返す
        return 0;
    }
    else
    {
        //中身が存在しないので非0を返す
        return 1;
    }
}
/**
 * @brief キューリストの初期化
 * @param *head:キューリストに使うリストの先頭のアドレス 
 * @return なし
 */
void queueinit(struct node *head)
{
    std::cout << __func__ << std::endl;
    delete_all(head);
    head->next = NULL;
}
/**
 * @brief キューに整数numを入れる
 * @param *head:キューリストに使うリストの先頭のアドレス 
 * @param  num:キューに入れたい整数 
 * @return なし
 */
void put(struct node *head, int num)
{
    std::cout << __func__ << ":" << num << "   ";
    struct node *p;
    for (p = head; p->next != NULL; p = p->next)
    {
        //リストの末尾までnextを辿っていく処理（効率が悪い）
    }
    insert_after(num, p);
    print_whole_list(head);
}
/**
 * @brief キューから整数を一つとりだす
 * @param *head:スタックリストに使うリストの先頭のアドレス 
 * @return 取り出した整数
 */
int get(struct node *head)
{
    std::cout << __func__;
    int temp;
    if (queueempty(head) == 0)
    {
        //リストの一番先頭のノードのkeyを取得して先頭のノードを削除
        temp = delete_next(head);
        std::cout << ":" << temp << "   ";
        print_whole_list(head);
        return temp;
    }
    else
    {
        std::cout << " queue is empty" << std::endl;
        //空のキューからゲットしようとしたのでプログラムを終了
        //exit(1);
        return 0;
    }
}
/**
 * @brief キューが空だったら非0の整数を返し，中身があったら0を返す
 * @param *head:キューリストに使うリストの先頭のアドレス 
 * @return 非0:キューが空
 *           0:キューに中身がある
 */
int queueempty(struct node *head)
{
    //headの後ろに要素が存在すれば0を返す，なければ非0を返す
    if (head->next != NULL)
    {
        //要素が存在するので0を返す
        return 0;
    }
    else
    {
        //要素が存在しないので非0を返す
        return 1;
    }
}
/**
 * @brief 指定場所の直後の要素のkeyを返すと共にその要素を削除する
 * @param *pt:keyを取得し消去したいノードの前のノードのアドレス 
 * @return　指定場所の直後のノードのkey
 */
int delete_next(struct node *pt)
{
    //ptの次にノードがなければエラーとしてプログラムを終了
    if (NULL == pt->next)
    {
        std::cout << "delete_next error" << std::endl;
        exit(1);
    }
    //指定箇所の次のノードのkeyを格納
    int key = pt->next->key;
    //指定箇所の次のノードの次のノードのアドレスを格納
    struct node *temp = pt->next->next;
    //指定箇所の次のノードのメモリを開放
    free(pt->next);
    //指定箇所の次のノードを削除したノードの次のノードにつなぎ替える
    pt->next = temp;
    //削除したノードのkeyを返す
    return key;
}
