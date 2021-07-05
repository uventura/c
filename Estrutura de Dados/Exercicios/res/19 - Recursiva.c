#include <stdio.h>

int FatDuplo(int n)
{
    if(n == 1) return 1;

    if(n % 2 != 0)
        return n * FatDuplo(n - 1);
    else
        return FatDuplo(n - 1);
}

int main()
{
    printf("%d\n", FatDuplo(7));
    return 0;
}