#include <stdio.h>

int cubo(int n)
{
    if(n == 1)
        return 1;
    return (n * n * n) + cubo(n - 1);
}

int main()
{
    printf("%d\n", cubo(3));
    return 0;
}