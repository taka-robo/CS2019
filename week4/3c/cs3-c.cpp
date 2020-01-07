#include <iostream>
#include <vector>
#include <cstring>
#include <thread>

#include "list2.hpp"
#define MAX 50 //MAX×MAXの迷路を生成(迷路自体は周りに壁があるのでMAX+2xMAX+2)
//迷路をint型に変換したときの対応`
#define OBSTACLE -1
#define START -2
#define GOAL -3

//経路探索につかうキュー
node queuehead;
node *qhead = &queuehead;
//探索した最短経路を入れておくリスト
node routehead;
node *rhead = &routehead;
//歩数カウンター
int steps = 1;
//スタート座標
std::vector<struct point> startpt;
//探索したゴール座標
struct point Goalpt;

/**
 *  @fn     printmap
 *  @brief  int型の迷路全体をchar型の書式に合わせて表示する
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @return なし
 * */
void printmap(int width, int height, int map[][MAX + 2])
{
    //表示開始
    int col, row;
    for (col = 0; col < height + 2; col++)
    {
        for (row = 0; row < width + 2; row++)
        {
            //int型を課題の例題に合わせて表示
            switch (map[col][row])
            {
            case OBSTACLE:
                printf("  +");
                break;
            case START:
                printf("  s");
                break;
            case GOAL:
                printf("  g");
                break;
            case 0:
                printf("  .");
                break;
            default:
                printf("%3d", map[col][row]);
                break;
            }
        }
        printf("\n");
    }
}
/**
 *  @fn     printShotestPath
 *  @brief  1つの最短ルートだけを表示する
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @return なし
 * */
void printShotestPath(int width, int height, int map[][MAX + 2])
{
    // std::cout << __func__ << std::endl;
    int col, row;
    struct node *p;
    //歩数の数
    int num = 1;
    //移動数が入ったマップをけす
    for (col = 1; col < height + 1; col++)
    {
        for (row = 1; row < width + 1; row++)
        {
            if (map[col][row] != OBSTACLE)
            {
                map[col][row] = 0;
            }
        }
    }
    //最短ルートの座標が入ったリストのデータをプロットしていく
    for (p = rhead->next; p != NULL; p = p->next, num++)
    {
        map[p->cell.col][p->cell.row] = num;
    }
    printmap(width, height, map);
}
/**
 *  @fn    findShortestPath 
 *  @brief  移動数が格納された迷路データから1つの最短経路を逆算する 
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @param  pt:逆算を始める座標
 *  @return なし
 * */
//移動数が入った迷路データから最短ルートを逆算する関数
void findShortestPath(int width, int height, int map[][MAX + 2], struct point pt)
{
    // std::cout << __func__ << std::endl;
    int col[4] = {pt.col - 1, pt.col, pt.col + 1, pt.col}, row[4] = {pt.row, pt.row + 1, pt.row, pt.row - 1};
    struct point shortRoute;
    steps = map[pt.col][pt.row] - 1;
    for (int index = 0; index < 4; index++)
    {
        if (map[col[index]][row[index]] == steps)
        {
            shortRoute.col = col[index];
            shortRoute.row = row[index];
            insert_after(shortRoute, rhead);
            if (map[col[index]][row[index]] != 1)
            {
                //スタート地点に戻るまで再帰呼び出し
                findShortestPath(width, height, map, shortRoute);
            }
        }
    }
}
/**
 *  @fn     moveCheck_queue
 *  @brief  注目座標の4近傍に対して移動できるかをチェックし移動できる座標をキューにputする
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @param  pt:注目座標
 *  @return なし
 * */
void moveCheck_queue(int width, int height, int map[][MAX + 2], struct point pt)
{
    // std::cout << __func__ << std::endl;
    //上，右，下，左の順で探索
    int col[4] = {pt.col - 1, pt.col, pt.col + 1, pt.col}, row[4] = {pt.row, pt.row + 1, pt.row, pt.row - 1};
    steps = map[pt.col][pt.row] + 1;
    for (int index = 0; index < 4; index++)
    { //4近傍探索
        if ((map[col[index]][row[index]] != OBSTACLE) && (map[col[index]][row[index]] == 0))
        { //移動可能場所があればキューにプットしその座標を探索済みに
            map[col[index]][row[index]] = steps;
            put(qhead, col[index], row[index]);
        }
        else if (map[col[index]][row[index]] == GOAL)
        { //ゴールのとき
            map[col[index]][row[index]] = steps;
            //ゴール座標変数に座標を追加
            Goalpt.col = col[index];
            Goalpt.row = row[index];
            //ゴール座標を最短ルートリストに追加
            insert_after(Goalpt, rhead);
            std::cout << col[index] << "," << row[index] << " is GOALLLLL!!!!!!" << std::endl;
            return;
        }
    }
    printmap(width, height, map);
    moveCheck_queue(width, height, map, get(qhead));
}
/**
 *  @fn     findRoute
 *  @brief  キューとスタックを用いて経路探索を行う
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @return なし
 * */
void findRoute(int width, int height, const int map[][MAX + 2])
{ //width:幅 height:高さ map[MAX]:要素
    int searchMapQueue[MAX + 2][MAX + 2];
    struct point pt;
    //キューを初期化
    queueinit(qhead);
    //最短ルートのリストを初期化
    rhead->next = NULL;
    //スタート地点を探索しつつ，もとのマップを探索用のsearchMapにコピー
    int col, row;
    for (col = 0; col < height + 2; col++)
    {
        for (row = 0; row < width + 2; row++)
        {
            searchMapQueue[col][row] = map[col][row];
            if (map[col][row] == START)
            { //スタート座標のとき
                pt.col = col;
                pt.row = row;
                startpt.push_back(pt);
                searchMapQueue[col][row] = 1;
            }
        }
    }
    //スタート座標が正しくとれているか表示
    for (size_t i = 0; i < startpt.size(); i++)
    {
        std::cout << startpt.at(i).col << "," << startpt.at(i).row << std::endl;
        put(qhead, startpt.at(i).col, startpt.at(i).row);
    }
    //
    //経路探索アルゴリズムの実装部分
    //
    //スタート座標をキューに追加
    std::cout << "start search(queue)" << std::endl;
    moveCheck_queue(width, height, searchMapQueue, get(qhead));
    std::cout << "finish search(queue) and find shortest path" << std::endl;
    findShortestPath(width, height, searchMapQueue, Goalpt);
    std::cout << "show result" << std::endl;
    printShotestPath(width, height, searchMapQueue);
}
/**
 *  @fn     c2imap
 *  @brief  char型の迷路データをint型に変換する
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  charMap:char型の迷路データ
 *  @param  intMap:int型の迷路データ
 *  @return なし
 * */
void c2imap(int width, int height, const char charMap[][MAX + 2], int intMap[][MAX + 2])
{
    int col, row;
    //表示開始
    for (col = 0; col < height + 2; col++)
    {
        for (row = 0; row < width + 2; row++)
        {
            switch (charMap[col][row])
            {
            case '+':
                intMap[col][row] = OBSTACLE;
                break;
            case '.':
                intMap[col][row] = 0;
                break;
            case 's':
                intMap[col][row] = START;
                break;
            case 'g':
                intMap[col][row] = GOAL;
                break;
            }
        }
    }
}
int main(int argc, char *argv[])
{                                   //argc:引数の個数 argv:引数の文字列配列
    char charMap[MAX + 2][MAX + 2]; //壁を含むのでMAX+2分の要素を確保
    int width, height, col, intMap[MAX + 2][MAX + 2];
    if (argc <= 1)
    { //コマンドラインからの入力がない場合
        width = 6;
        height = 5;
        strcpy(charMap[0], "++++++++");
        strcpy(charMap[1], "+.g....+");
        strcpy(charMap[2], "+....s.+");
        strcpy(charMap[3], "+..s.s.+");
        strcpy(charMap[4], "+......+");
        strcpy(charMap[5], "+g..g.g+");
        strcpy(charMap[6], "++++++++");
    }
    else
    { //コマンドラインからの入力がある場合
        //入力が正しいという前提
        height = argc - 1;
        width = strlen(argv[1]);
        for (col = 0; col < height; col++)
        {
            strcpy(charMap[col], argv[col + 1]);
        }
    }
    //char型のマップをint型に変換
    c2imap(width, height, charMap, intMap);
    //探索する迷路を表示
    std::cout << "input map" << std::endl;
    printmap(width, height, intMap);
    //経路探索
    findRoute(width, height, intMap);
    return 0;
}