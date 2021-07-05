#include <stdio.h>

int tetranacci(int n, int n1, int n2, int n3, int n4)
{
    if(n == 4) return n4;
    else if(n <= 3) return 0;
    return tetranacci(n - 1, n2, n3, n4, n1 + n2 + n3 + n4);
}

int main()
{
    printf("%d\n", tetranacci(10, 0, 0, 0, 1));
    return 0;
}