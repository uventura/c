#include <stdio.h>

void ExibeNPares(int n)
{
    if(n == 0)
    {
        printf("0 ");
    }
    else
    {
        ExibeNPares(n - 1);
        if(n % 2 == 0)
            printf("%d ", n);
    }
}

int main()
{
    ExibeNPares(10);
    printf("\n");
    return 0;
}