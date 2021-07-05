#include <stdio.h>

int func(int n)
{
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else return 2 * func(n - 1) + 3 * func(n - 2); 
}

int main()
{
    printf("%d\n", func(3));
    return 0;
}