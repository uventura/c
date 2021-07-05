#include <stdio.h>

// Exibir Inteiros em Ordem Decrescente
void ExibirInts(int n)
{
    if(n == -1)
    {
        printf("\n");
    }
    else
    {
        printf("%d ", n);
        ExibirInts(n - 1);
    }
    
}

int main()
{
    ExibirInts(5);
    return 0;
}