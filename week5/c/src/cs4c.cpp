/**
 *ナイトの巡回問題 
 * 
 * */
#include <iostream>
#include <cstring>
#include "list2.hpp"
#include <vector>
#include <array>

#define DEBUG 40000
constexpr int MAXMAPSIZE = 50; //MAX×MAXの迷路を生成
/*迷路をint型に変換したときの対応*/
constexpr int OBSTACLE = -1;
constexpr int START = -2;
constexpr int GOAL = -3;
constexpr int KNIGHT = -4;

//経路探索につかうスタック
node stackhead;
node *shead = &stackhead;
//探索した最短経路を入れておくリスト
node routehead;
node *rhead = &routehead;
//歩数カウンター
int max_step = 0;
//プログラム強制終了用変数
uint64_t count = 0;
//最長経路歩数マップ
int longest_path_map[MAXMAPSIZE][MAXMAPSIZE];
/**
 *  @fn     printmap
 *  @brief  int型の迷路全体をchar型の書式に合わせて表示する
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @return なし
 * */
void printmap(int width, int height, int map[][MAXMAPSIZE])
{
    //表示開始
    int col, row;
    for (col = 1; col < height - 1; col++)
    {
        for (row = 1; row < width - 1; row++)
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
            default:
                printf("%3d", map[col][row]);
                break;
            }
        }
        printf("\n");
    }
}
/**
 *  @fn     copyMap
 *  @brief  int型の迷路データをコピーする　
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:コピーもとのint型の迷路データ
 *  @return なし
 * */
void copyMap(int width, int height, int map[][MAXMAPSIZE])
{
    std::cout << __func__ << std::endl;
    //コピー開始
    int col, row;
    for (col = 0; col < height; col++)
    {
        for (row = 0; row < width; row++)
        {
            longest_path_map[row][col] = map[row][col];
        }
    }
}
/**
 *  @fn     clearPath
 *  @brief  指定した数以上の歩数の要素を0にする
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @param  num:指定する数
 *  @return なし
 * */
void clearPath(int width, int height, int map[][MAXMAPSIZE], int num)
{
    std::cout << __func__ << num << std::endl;
    //表示開始
    int col, row;
    for (col = 0; col < height; col++)
    {
        for (row = 0; row < width; row++)
        {
            if (map[row][col] >= num)
            {
                map[row][col] = 0;
            }
        }
    }
}
int getStep(int width, int height, int map[][MAXMAPSIZE], struct point pt)
{
    // std::cout << __func__ << ":" << pt.col << "," << pt.row;
    // steps++;
    // return steps;
    // //上，右，下，左の順で探索
    // int col[4] = {pt.col - 1, pt.col, pt.col + 1, pt.col}, row[4] = {pt.row, pt.row + 1, pt.row, pt.row - 1};
    // int max = 0;
    // //ptが0のときは新しいところに進んだので四方で一番大きい数字の連番になるようにする．
    // for (int index = 0; index < 4; index++)
    // {
    //     if ((map[col[index]][row[index]] > max) && (map[pt.col][pt.row] == 0) && (map[col[index]][row[index]] != OBSTACLE))
    //     {
    //         max = map[col[index]][row[index]];
    //     }
    // }
    // std::cout << ":" << max + 1 << std::endl;
    // return max + 1;
}
/**
 *  @fn     moveCheck_stack
 *  @brief  注目座標の4近傍に対して移動できるかをチェックし移動できる座標をスタックにpushしその点へ注目座標を移動させる
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @param  pt:注目座標
 *  @return なし
 * */
void moveCheck_stack(int width, int height, int map[][MAXMAPSIZE], struct point attentionPt)
{
#ifdef DEBUG
    if (count > DEBUG)
    {
        std::exit(-1);
    }
#endif
    std::cout << "----------------------------------------------" << std::endl;
    //関数名の表示と再帰回数のカウントアップ
    std::cout << __func__ << count++ << "steps" << attentionPt.step << std::endl;
    //上，右，下，左の順で探索するための配列
    std::vector<struct point> checkPt{
        {attentionPt.col - 2, attentionPt.row + 1},
        {attentionPt.col - 1, attentionPt.row + 2},
        {attentionPt.col + 1, attentionPt.row + 2},
        {attentionPt.col + 2, attentionPt.row + 1},
        {attentionPt.col + 2, attentionPt.row - 1},
        {attentionPt.col + 1, attentionPt.row - 2},
        {attentionPt.col - 1, attentionPt.row - 2},
        {attentionPt.col - 2, attentionPt.row - 1},
    };
    //移動フラグ
    bool moveed_flag = 0;
    //歩数
    int steps = 0;
    //四方を見て一番大きい数字の+1をステップ数とする．
    map[attentionPt.col][attentionPt.row] = attentionPt.step;
    steps = attentionPt.step + 1;
#ifdef DEBUG
    printmap(width, height, map);
#endif
    for (size_t i = 0; i < checkPt.size(); i++)
    {
        if ((map[checkPt[i].col][checkPt[i].row] != OBSTACLE) && (map[checkPt[i].col][checkPt[i].row] == 0))
        { //移動可能な場合
            //移動フラグを立てる
            moveed_flag = 1;
            //移動可能座標をスタックにpush
            push(shead, checkPt[i].col, checkPt[i].row, steps);
        }
    }
    //スタックが空かをチェック
    if (stackempty(shead) != 0)
    { //空の場合
        return;
    }
    else
    { //空でない場合
        //次に移動する座標をスタックからpop
        attentionPt = pop(shead);
        //移動不可能かを判別
        if (moveed_flag == 0)
        { //どこにも移動できなかった場合
            std::cout << "DO NOT MOVE" << std::endl;
            if (max_step < steps + 1)
            { //大きい場合
                //最大ステップ数を更新
                max_step = steps + 1;
                //現状で最大ステップ数のマップをコピーしておく
                copyMap(width, height, map);
                //ゴールの部分に歩数をいれる
            }
            //最後に分岐したところのステップ数より大きいステップ数のマスを消す（今きた道を消す）．
            clearPath(width, height, map, attentionPt.step);
        }
        //再帰呼出し
        moveCheck_stack(width, height, map, attentionPt);
    }
}
/**
 *  @fn     findRoute
 *  @brief  キューとスタックを用いて経路探索を行う
 *  @param  width:迷路の幅
 *  @param  height:迷路の高さ
 *  @param  map:int型の迷路データ
 *  @return なし
 * */
void findRoute(int width, int height, const int map[][MAXMAPSIZE])
{ //width:幅 height:高さ map[MAX]:要素
    int searchMapStack[MAXMAPSIZE][MAXMAPSIZE];
    //スタックを初期化
    stackinit(shead);
    //最短ルートのリストを初期化
    rhead->next = NULL;
    //スタート地点を探索しつつ，もとのマップを探索用のsearchMapにコピー
    int col, row;
    struct point start_point;
    for (col = 0; col < height; col++)
    {
        for (row = 0; row < width; row++)
        {
            searchMapStack[col][row] = map[col][row];
            if (map[col][row] == START)
            { //スタート座標のとき
                //スタートの座標をスタックにpush
                push(shead, col, row, 1);
            }
        }
    }
    //
    //経路探索アルゴリズムの実装部分
    //
    std::cout << "start search(stack)" << std::endl;
    moveCheck_stack(width, height, searchMapStack, pop(shead));
    std::cout << "show result" << std::endl;
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
void c2imap(int width, int height, const char charMap[][MAXMAPSIZE], int intMap[][MAXMAPSIZE])
{
    int col, row;
    //表示開始
    for (col = 0; col < height; col++)
    {
        for (row = 0; row < width; row++)
        {
            switch (charMap[col][row])
            {
            case '+':
                intMap[col][row] = -1;
                break;
            case '0':
                intMap[col][row] = 0;
                break;
            case 's':
                intMap[col][row] = -2;
                break;
            case 'g':
                intMap[col][row] = -3;
                break;
            }
        }
    }
}
int main(int argc, char *argv[])
{                                         //argc:引数の個数 argv:引数の文字列配列
    char charMap[MAXMAPSIZE][MAXMAPSIZE]; //壁を含むのでMAX+2分の要素を確保
    int width, height, col, intMap[MAXMAPSIZE][MAXMAPSIZE];
    if (argc <= 1)
    { //コマンドラインからの入力がない場合
        width = 9;
        height = 9;
        strcpy(charMap[0], "+++++++++");
        strcpy(charMap[1], "+++++++++");
        strcpy(charMap[2], "++s0000++");
        strcpy(charMap[3], "++00000++");
        strcpy(charMap[4], "++00000++");
        strcpy(charMap[5], "++00000++");
        strcpy(charMap[6], "++00000++");
        strcpy(charMap[7], "+++++++++");
        strcpy(charMap[8], "+++++++++");
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
    std::cout << "MAX STEP: " << max_step + 1 << std::endl;
    printmap(width, height, longest_path_map);
    //経路探索
    return 0;
}