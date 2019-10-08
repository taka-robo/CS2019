#include <stdio.h>
int main(void){
   // Your code here!
   int a[32768] = {};
    int N;
    int i=2, j=2, k=2;
    
    scanf("%d",&N);
    
    a[0] = 1;
    a[1] = 1;
    for(i=2;i<=N;i++){
        for(j=i;j<=N;j++){
            a[i*j] = 1;
        }
    }
    for(k=0;k<=N;k++) printf("%d\n",a[k]);
    
    return 0;
}