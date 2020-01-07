#include <iostream>
#define N 100
double C(int n)
{
    if (0 == n)
    {
        return 1;
    }
    else if (1 == n)
    {
        return 2;
    }
    else
    {
        return 2 * C(n / 3) - C(n / 2);
    }
}
int main(int argc, char *argv[])
{ //argc:引数の個数 argv:引数の文字列配列
    for (int i = 0; i <= N; i++)
    {
        std::cout << i << "," << C(i) << std::endl;
    }
    return 0;
}