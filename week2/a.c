#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* @func getPrimeNum
* @brief エラトステネスの篩で自然数Nまでの素数を判定
* 素数の要素番号をもつ要素には0, 合成数には1を格納
* @param 自然数N
* @param 配列を確保するための先頭アドレス
* @return なし
*/
void getPrimeNum(int N, bool *prime)
{
    printf("エラトステネスの篩\n");
    int i, j, k;

    //配列の要素数を動的に確保する
    prime = (bool *)calloc(N + 1, sizeof(bool *));

    if (N < 1)
    {
        printf("素数判定には自然数を入力してください\n");
    }
    else
    {
        //0と1は合成数なので1とする
        prime[0] = 1;
        prime[1] = 1;

        //エラトステネスの篩
        for (i = 2; i * i <= N; ++i)
        {
            if (prime[i])
                continue;
            for (j = i * i; j <= N; j += i)
            {
                prime[j] = 1;
            }
        }

        //結果出力
        for (k = 0; k <= N; ++k)
            printf("%2d\n", prime[k]);
    }
}

/**
* @func getDisjoint
* @brief 剰余や割り算を用いないで互いに素を判定する
* 互いに素となる要素番号の要素には1, それ以外は0を格納
* @param 自然数N
* @param 二次元配列を確保するための先頭アドレス
* @return なし
*/
void getDisjoint(int N, bool **tmp)
{
    printf("互いに素\n");
    int i, j, k;

    //配列の要素数を入力Nに対して動的に確保する(C言語やめたい)
    tmp = (bool **)malloc((N + 1) * sizeof(bool *));
    for (i = 0; i <= N + 1; i++)
    {
        tmp[i] = (bool *)malloc((N + 1) * sizeof(bool));
    }
    //配列を1で初期化する(ここでC++勉強しようと決意)
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            tmp[i][j] = true;
        }
    }

    /* 1はどんな整数と組んでも互いに素だから2から考える
* 互いに素となる組の整数倍は互いに素ではない
* kがN/j以下(k*j<=N)となる整数倍について考えればよい
*/
    for (i = 1; i <= N; ++i)
    {
        for (j = i; j <= N; ++j)
        {
            if (!tmp[i][j])
            {
                continue; //次のfor分は飛ばしてこの前のfor文に戻る
            }
            for (k = 2; j * k <= N; ++k)
            {
                //最大公約数はiとjの順序に依存しない
                tmp[i * k][j * k] = 0;
                tmp[j * k][i * k] = 0;
            }
        }
    }

    //出力
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            printf("%2d", tmp[i][j]);
        }
        printf("\n");
    }
}

//main関数
int main(void)
{
    int N;
    bool *a;
    bool **b;

    scanf("%d", &N);

    getPrimeNum(N, a); //エラトステネスの篩
    getDisjoint(N, b); //互いに素
    return 0;
}