#include <stdio.h>

int fibg(int f0, int f1, int n)
{
    if(n == 0) return f0;
    else if(n == 1) return f1;
    return fibg(f0, f1, n - 1) + fibg(f0, f1, n - 2);
}

int main()
{
    printf("%d\n", fibg(0, 1, 3));
    return 0;
}