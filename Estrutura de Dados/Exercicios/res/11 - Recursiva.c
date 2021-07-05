#include <stdio.h>

int TermoFibb(int n, int a, int b)
{
    if(n == 1)
        return a;

    return TermoFibb(n - 1, b, a + b);
}

int main()
{
    printf("%d\n", TermoFibb(5, 0, 1));
    return 0;
}