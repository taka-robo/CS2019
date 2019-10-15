/**
 * @file ec1.cpp
 * @brief 計算基礎工学の課題1(エラトステネスの篩と最大公約数)
 * @author Takaaki NARA
 * @date 10/08
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define true 1
#define false 0
/**
 * @fn
 * @brief 自然数i,jの最大公約数が1だったとき配列に1を格納する
 * @param 自然数i
 * @param 自然数j
 * @param 計算結果を格納する配列
 * @return なし
 */
bool getGCD(int64_t N,std::vector<std::vector<bool>> & b){
    std::cout<<"GCD"<<std::endl;
    std::vector<std::vector<bool>> serchList(N+1,std::vector<bool>(N+1,true));
    for(int64_t i=1;i<= N;++i)
    {
        for(int64_t j=i;j<= N;++j)
        {
            if(serchList[i][j]==false){
                continue;
            }
            for(int64_t k=2;k<=N;++k)
            {
                if(j*k>N){
                    break;
                }
                serchList[i*k][j*k]=false;
                serchList[j*k][i*k]=false;
            }
        }
    }
    // for(int64_t i=1;i<=N,++i){
    //     std::cout<<i;
    // }
    for(int64_t i=1;i<=N;++i){
        std::cout<<i<<":";
        for(int64_t j=1;j<=N;++j){
            std::cout<<serchList[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

}
/**
 * @fn
 * @brief エラトステネスの篩を実行する関数(自然数Nまでの素数を探索する)
 * @param 自然数N
 * @param 計算結果を格納する配列
 * @return 0
 */
void SieveOfEratosthenes(int64_t N,std::vector<bool> & a){
    std::cout<<"エラトステネスの篩"<<std::endl;
    std::vector<bool> serchList(N+1,true);
    for(int64_t i=2;i*i <= N;++i)
    {
        if(serchList[i]=true){
            for(int64_t j=2;j*i <= N;++j){
                serchList[j*i]=false;
            }
        }
    }
    //0と1は素数じゃないので強制的にfalse（頭悪そう）
    serchList[0]=false;
    serchList[1]=false;
    //serchListの中身をaにコピー
    a.resize(serchList.size());
    std::copy(serchList.begin(),serchList.end(),a.begin());
} 

int main(){
    //課題aのa配列を宣言
    std::vector<bool> a;
    //課題bのb配列を宣言
    std::vector<std::vector<bool>> b;
    //自然数Nを宣言
    int64_t N;
    int64_t counter=0;//素数の数をカウント(デバック用)
    //外部入力でNに値を代入
    std::cin >> N;
    // if(N>sizeof(int64_t)*8){
    //     std::cout<<"64bitより大きい数字には対応してないです"<<std::endl;
    //     return -1;
    // }
    //エラトステネスの篩関数の呼びだし(引数は自然数Nと配列aのポインタ) 
    SieveOfEratosthenes(N,a);
    //互いに素を探すやつ
    getGCD(N,b);
    // //配列aの中身を表示
    // for(int64_t k=1;k<a.ksize();k++){
    //     std::cout <<k<<":"<< a[k]<<" ";
    //     if(a[k]==true)counter++;
    //     //見やすくするために10の倍数ごとに改行
    //     if(k%10==0) std::cout<<std::endl;
    // }
    //std::cout<<counter<<std::endl;
    return 0;
}