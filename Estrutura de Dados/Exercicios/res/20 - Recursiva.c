#include <stdio.h>

int FatQuad(int n) // Fatorial Quádruplo
{
    static int i = -1;

    ++i;
    if(2*n - i == n) return 1;

    return (2*n - i) * FatQuad(n);
}

int main()
{
    printf("%d\n", FatQuad(3));
    return 0;
}