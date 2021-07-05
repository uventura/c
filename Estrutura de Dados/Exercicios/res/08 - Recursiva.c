#include <stdio.h>

int somatorio(int n)
{
    if(n == 1)
        return 1;
    return n + somatorio(n-1);
}

int main()
{
    printf("%d\n", somatorio(3));
    return 0;
}