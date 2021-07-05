#include <stdio.h>

void ExibeNPares(int n)
{
    if(n == 0)
    {
        printf("0\n");
    }
    else
    {
        if(n % 2 == 0)
            printf("%d ", n);
        ExibeNPares(n - 1);
    }
}

int main()
{
    ExibeNPares(10);
    return 0;
}