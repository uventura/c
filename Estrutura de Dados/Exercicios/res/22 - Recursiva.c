#include <stdio.h>

int exponencial(int a, int b)
{
    if(b == 1) return a;
    return a * exponencial(a, b - 1);
}

int hiperfatorial(int n)
{
    if(n == 1) return 1;
    return exponencial(n, n) * hiperfatorial(n - 1);
}

int main()
{
    printf("%d\n", hiperfatorial(3));
    return 0;
}