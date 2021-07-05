#include <stdio.h>

int fatorial(int n)
{
    if(n == 1) return 1;
    return n * fatorial(n-1);
}

int SuperFatorial(int n)
{
    if(n == 1) return 1;
    return fatorial(n) * SuperFatorial(n-1);
}

int main()
{
    printf("%d\n", SuperFatorial(4));
    return 0;
}