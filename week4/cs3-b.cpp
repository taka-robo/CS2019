#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "list2.hpp"
#define MAX 50 //MAX×MAXの迷路を生成

//経路探索につかうキュー
node queuehead;
node *qhead = &queuehead;
//探索した最短経路を入れておくリスト
node routehead;
node *rhead = &routehead;
int count = 1;
//スタート座標
struct point startpt;
//探索したゴール座標
struct point Goalpt;
//迷路全体を表示する
void printmap(int width, int height, char map[][MAX + 2])
{
    //表示開始
    int i, j;
    for (i = 0; i < height + 2; i++)
    {
        for (j = 0; j < width + 2; j++)
        {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}
void printMSR(int width, int height, char map[][MAX + 2])
{
    // std::cout << __func__ << std::endl;
    int i, j;
    struct node *p;
    //歩数の数
    int num = 1;
    //移動数が入ったマップをけす
    for (i = 1; i < height + 1; i++)
    {
        for (j = 1; j < width + 1; j++)
        {
            if (map[i][j] != '+')
            {
                map[i][j] = ' ';
            }
        }
    }
    //最短ルートの座標が入ったリストのデータをプロットしていく
    for (p = rhead->next; p != NULL; p = p->next, num++)
    {
        map[p->cell.x][p->cell.y] = '0' + num;
    }
    printmap(width, height, map);
}
//移動数が入った迷路データから最短ルートを逆算する関数
void findMSR(int width, int height, char map[][MAX + 2], struct point pt)
{
    // std::cout << __func__ << std::endl;
    int i[4] = {pt.x - 1, pt.x, pt.x + 1, pt.x}, j[4] = {pt.y, pt.y + 1, pt.y, pt.y - 1};
    char temp;
    struct point shoteRoute;
    temp = map[pt.x][pt.y];
    count = atoi(&temp);
    count--;
    for (int index = 0; index < 4; index++)
    {
        if (map[i[index]][j[index]] == ('0' + count))
        {
            shoteRoute.x = i[index];
            shoteRoute.y = j[index];
            insert_after(shoteRoute, rhead);
            if (map[i[index]][j[index]] == '1')
            {
                std::cout << i[index] << "," << j[index] << "is Start!!!!!!" << std::endl;
                return;
            }
            findMSR(width, height, map, shoteRoute);
        }
    }
}
//4近傍で移動できるかをチェックし移動できる座標をキューにputする
void movecheck(int width, int heigt, char map[][MAX + 2], struct point pt)
{
    // std::cout << __func__ << std::endl;
    int i[4] = {pt.x - 1, pt.x, pt.x + 1, pt.x}, j[4] = {pt.y, pt.y + 1, pt.y, pt.y - 1};
    char temp;
    temp = map[pt.x][pt.y];
    count = atoi(&temp);
    count++;
    for (int index = 0; index < 4; index++)
    {
        if ((map[i[index]][j[index]] != '+') && (map[i[index]][j[index]] == '0'))
        {
            put(qhead, i[index], j[index]);
            temp = '0' + count;
            std::cout << temp << std::endl;
            map[i[index]][j[index]] = temp;
        }
        else if (map[i[index]][j[index]] == 'g')
        { //ゴールのとき
            temp = '0' + count;
            std::cout << temp << std::endl;
            map[i[index]][j[index]] = temp;
            //ゴール座標変数に座標を追加
            Goalpt.x = i[index];
            Goalpt.y = j[index];
            //ゴール座標を最短ルートリストに追加
            insert_after(Goalpt, rhead);
            std::cout << i[index] << "," << j[index] << "is GOALLLLL!!!!!!" << std::endl;
            return;
        }
    }
    movecheck(width, heigt, map, get(qhead));
}
//経路探索関数
void findRoute(int width, int height, char map[][MAX + 2])
{ //width:幅 height:高さ map[MAX]:要素
    //キューを初期化
    queueinit(qhead);
    //ルートのリストを初期化
    rhead->next = NULL;

    //表示開始
    int i, j;
    char temp;
    for (i = 0; i < height + 2; i++)
    {
        for (j = 0; j < width + 2; j++)
        {
            if (map[i][j] == 's')
            {
                startpt.x = i;
                startpt.y = j;
                temp = '0' + count;
                map[i][j] = temp;
            }
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
    //表示終了
    //
    //経路探索アルゴリズムの実装部分
    //
    put(qhead, startpt.x, startpt.y);
    struct point next = get(qhead);
    movecheck(width, height, map, next);
    findMSR(width, height, map, Goalpt);
    print_whole_list(rhead);
    printMSR(width, height, map);
}

int main(int argc, char *argv[])
{                               //argc:引数の個数 argv:引数の文字列配列
    char map[MAX + 2][MAX + 2]; //壁を含むのでMAX+2分の要素を確保
    int width, height;          //幅,高さ
    int i;
    if (argc <= 1)
    { //コマンドラインからの入力がない場合
        width = 5;
        height = 5;
        strcpy(map[0], "+++++++");
        strcpy(map[1], "+0s000+");
        strcpy(map[2], "+00000+");
        strcpy(map[3], "+0000++");
        strcpy(map[4], "+00000+");
        strcpy(map[5], "+0000g+");
        strcpy(map[6], "+++++++");
    }
    else
    { //コマンドラインからの入力がある場合
        //入力が正しいという前提
        height = argc - 1;
        width = strlen(argv[1]);
        for (i = 0; i < height; i++)
        {
            strcpy(map[i], argv[i + 1]);
        }
    }

    //経路探索関数
    findRoute(width, height, map);

    return 0;
}