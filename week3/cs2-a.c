#include "stdio.h"
//#include "list.h"
#define SIZE 100
static int array[SIZE] = {};
int array_end = 0;
// void array_initialize()
// {
//     printf(__func__);
//     int i;
//     for (i = 0; i < SIZE; ++i)
//     {
//         array[i] = NULL;
//     }
// }
void print_array()
{
    int i;
    for (i = 0; i < array_end; ++i)
    {
        printf("%3d,", array[i]);
    }
    printf("\n");
}
void sort_array()
{
    int i, j, temp;
    for (i = 0; i < array_end; ++i)
    {
        for (j = i + 1; j < array_end; ++j)
        {

            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
int insert_sorted_list(int key)
{
    int i;
    //配列の中にkeyと同値が存在するか探索.存在すればソートし　return 1．なければ配列の最後に追加してreturn 0．
    for (i = 0; i < array_end; ++i)
    {
        if (array[i] == key)
        {
            sort_array();
            print_array();
            return 1;
        }
    }
    array[array_end] = key;
    array_end++;
    sort_array();
    print_array();
    return 0;
}
int main(void)
{
    insert_sorted_list(8);
    insert_sorted_list(3);
    insert_sorted_list(12);
    insert_sorted_list(1);
    insert_sorted_list(8);
    insert_sorted_list(10);
    insert_sorted_list(5);
    insert_sorted_list(0);
    insert_sorted_list(3);
    return 0;
}