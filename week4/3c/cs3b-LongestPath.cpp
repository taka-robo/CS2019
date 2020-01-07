#include <iostream>
#include <cstring>
#include "list2.hpp"
#include <vector>
#define MAX 50 //MAX×MAXの迷路を生成(迷路自体は周りに壁があるのでMAX+2xMAX+2)
//迷路をint型に変換したときの対応`
#define OBSTACLE -1
#define START -2
#define GOAL -3

//経路探索につかうスタック
node stackhead;
node *shead = &stackhead;
//探索した最短経路を入れておくリスト
node routehead;
node *rhead = &routehead;
//歩数カウンター
int steps = 1;
int max_step = 0;
//プログラム強制終了用変数
int count = 0;
//最長経路歩数マップ
int longest_path_map[MAX + 2][MAX + 2];
//分岐したときのステップ数を格納しておく変数
std::vector<int> branch_steps;
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
void copyMap(int width, int height, int map[][MAX + 2])
{
    std::cout << __func__ << std::endl;
    //コピー開始
    int col, row;
    for (col = 0; col < height + 2; col++)
    {
        for (row = 0; row < width + 2; row++)
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
void clearPath(int width, int height, int map[][MAX + 2], int num)
{
    std::cout << __func__ << num << std::endl;
    //表示開始
    int col, row;
    for (col = 0; col < height + 2; col++)
    {
        for (row = 0; row < width + 2; row++)
        {
            if (map[row][col] > num)
            {
                map[row][col] = 0;
            }
        }
    }
}
int getStep(int width, int height, int map[][MAX + 2], struct point pt)
{
    std::cout << __func__ << ":" << pt.col << "," << pt.row;
    //上，右，下，左の順で探索
    int col[4] = {pt.col - 1, pt.col, pt.col + 1, pt.col}, row[4] = {pt.row, pt.row + 1, pt.row, pt.row - 1};
    int max = 0;
    //ptが0のときは新しいところに進んだので四方で一番大きい数字の連番になるようにする．
    for (int index = 0; index < 4; index++)
    {
        if ((map[col[index]][row[index]] > max) && (map[pt.col][pt.row] == 0) && (map[col[index]][row[index]] != OBSTACLE))
        {
            max = map[col[index]][row[index]];
        }
    }
    std::cout << ":" << max + 1 << std::endl;
    return max + 1;
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
void moveCheck_stack(int width, int height, int map[][MAX + 2], struct point pt)
{

    std::cout << "----------------------------------------------" << std::endl;
    //関数名の表示と再帰回数のカウントアップ
    std::cout << __func__ << count++ << std::endl;
    //上，右，下，左の順で探索するための配列
    int col[4] = {pt.col - 1, pt.col, pt.col + 1, pt.col}, row[4] = {pt.row, pt.row + 1, pt.row, pt.row - 1};
    //移動フラグ
    bool move_flag = 0;
    //四方を見て一番大きい数字の+1をステップ数とする．
    steps = getStep(width, height, map, pt);
    map[pt.col][pt.row] = steps;
    printmap(width, height, map);
    for (int index = 0; index < 4; index++)
    {
        if ((map[col[index]][row[index]] != OBSTACLE) && (map[col[index]][row[index]] == 0))
        { //移動可能な場合
            //移動フラグを立てる
            move_flag = 1;
            //移動可能座標をスタックにpush
            push(shead, col[index], row[index]);
            //分岐するところのステップ数を記録　
            branch_steps.push_back(steps);
        }
        else if (map[col[index]][row[index]] == GOAL)
        { //ゴールのとき
            //これまでよりステップ数が大きいかを判別
            if (max_step < steps + 1)
            { //大きい場合
                //最大ステップ数を更新
                max_step = steps + 1;
                //現状で最大ステップ数のマップをコピーしておく
                copyMap(width, height, map);
                //ゴールの部分に歩数をいれる
                longest_path_map[col[index]][row[index]] = max_step;
            }
            std::cout << col[index] << "," << row[index] << " is GOALLLLL!!!!!!" << std::endl;
        }
    }
    //スタックが空かをチェック
    if (stackempty(shead) != 0)
    { //空の場合
        return;
    }
    else
    { //空出ない場合
        //次に移動する座標をスタックからpop
        pt = pop(shead);
        //移動不可能かを判別
        if (move_flag == 0)
        { //どこにも移動できなかった場合
            std::cout << "DO NOT MOVE" << std::endl;
            //最後に分岐したところのステップ数より大きいステップ数のマスを消す（今きた道を消す）．
            clearPath(width, height, map, branch_steps.back());
        }
        branch_steps.pop_back();
        //再帰呼出し
        moveCheck_stack(width, height, map, pt);
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
void findRoute(int width, int height, const int map[][MAX + 2])
{ //width:幅 height:高さ map[MAX]:要素
    int searchMapStack[MAX + 2][MAX + 2];
    //スタックを初期化
    stackinit(shead);
    //最短ルートのリストを初期化
    rhead->next = NULL;
    //スタート地点を探索しつつ，もとのマップを探索用のsearchMapにコピー
    int col, row;
    struct point start_point;
    for (col = 0; col < height + 2; col++)
    {
        for (row = 0; row < width + 2; row++)
        {
            searchMapStack[col][row] = map[col][row];
            if (map[col][row] == START)
            { //スタート座標のとき
                //スタートの座標をスタックにpush
                push(shead, col, row);
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
{                                   //argc:引数の個数 argv:引数の文字列配列
    char charMap[MAX + 2][MAX + 2]; //壁を含むのでMAX+2分の要素を確保
    int width, height, col, intMap[MAX + 2][MAX + 2];
    if (argc <= 1)
    { //コマンドラインからの入力がない場合
        width = 5;
        height = 5;
        strcpy(charMap[0], "+++++++");
        strcpy(charMap[1], "+0s000+");
        strcpy(charMap[2], "+00000+");
        strcpy(charMap[3], "+0000++");
        strcpy(charMap[4], "+00000+");
        strcpy(charMap[5], "+0000g+");
        strcpy(charMap[6], "+++++++");
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