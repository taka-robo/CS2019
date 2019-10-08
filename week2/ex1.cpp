#include<iostream>
#include<vector>
#include <algorithm>

#define true 1
#define false 0

void SieveOfEratosthenes(int x,std::vector<bool> & a){
    std::vector<bool> serchList(x,true);
    for(int i=2;i<x;i++)
    {
        for(int j=2;j<x;j++){
            serchList[j*i]=false;
        }
    }
    //0と1は素数じゃないので強制的にfalse（頭悪そう）
    serchList[0]=false;
    serchList[1]=false;
    //serchListをコピー
    a.resize(serchList.size());
    std::copy(serchList.begin(),serchList.end(),a.begin());
} 

int main(){
    //課題のa配列を宣言
    std::vector<bool> a;
    //自然数Nを宣言
    int N;
    int counter=0;//素数の数をカウント
    //外部入力でNに値を代入
    std::cin >> N;
    //エラトステネスの篩関数の呼びだし(引数は自然数Nと配列aのポインタ) 
    SieveOfEratosthenes(N,a);
    for(int k=1;k<a.size();k++){
        std::cout <<k<<":"<< a[k]<<" ";
        if(a[k]==true)counter++;
        //見やすくするために10の倍数ごとに改行
        if(k%10==0) std::cout<<std::endl;
    }
    std::cout<<counter<<std::endl;
    return 0;
}