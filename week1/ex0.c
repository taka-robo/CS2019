/*
計算工学基礎一週目課題0
掛け算九九表の対角成分の下半分，上半分を出力するプログラム．
author 19257514　奈良貴明
*/
#include "stdio.h"

int main(void){
    int row,col;
    printf("Lower triangle\n");
    for (row = 1; row < 10;row++)
    {
        /*列(col)が行(row)より大きくなるまで掛け算の結果を出力*/
        for(col= 1;col <= row;col++)
        {
            printf("%3d",row*col);
        }
        printf("\n");
    }
    printf("Upper triangle\n");
    for (row = 1; row < 10;row++)
    {
        for(col = 1;col < 10;col++)
        {
            /*列(col)が行(row)より小さいときは3桁の半角空白を出力,それ以外のときは掛け算の結果を出力*/
            if(col<row) printf("   ");
            else printf("%3d",row*col);
        }
        printf("\n");
    }

    return 0;
}