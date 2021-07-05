#include <stdio.h>

void ExibirInts(int n)
{
    if(n == 0)
    {
        printf("0 ");
    }
    else
    {
        ExibirInts(n - 1);
        printf("%d ", n);
    }
}

int main()
{
    ExibirInts(5);
    printf("\n");

    return 0;
}