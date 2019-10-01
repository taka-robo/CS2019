#include "stdio.h"

int main(void){
    printf("Lower triangle\n");
    for (int col = 1; col < 10; col++)
    {
        for(int row = 1;row <col+1;row++){
            printf("%3d",col*row);
        }
        printf("\n");
    }
    printf("Upper triangle\n");
    for (int col = 1; col < 10; col++)
    {
        for(int row = 1;row <10;row++){
            if(row<col) printf("   ");
            else printf("%3d",col*row);
        }
        printf("\n");
    }
}