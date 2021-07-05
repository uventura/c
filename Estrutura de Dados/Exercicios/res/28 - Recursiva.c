#include <stdio.h>

int hex(int n)
{
    if(n == 0) return 0;
    return (n % 2) + 10 * bin(n / 2); 
}

int main()
{
    printf("%d\n", bin(187));
    return 0;
}