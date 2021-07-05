#include <stdio.h>

int exponencial(int k, int n)
{
    if(n == 0)
        return 1;
    return k * exponencial(k, n - 1);
}

int main()
{
    printf("%d\n", exponencial(3, 2));
    return 0;
}