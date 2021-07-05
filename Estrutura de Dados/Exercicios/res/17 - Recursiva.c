#include <stdio.h>

// INCOMPLETO

void ExibeArray(int *vetor, int n)
{
    // O vetor deve possuir tamanho definido.

    if(n == 0)
    {
        printf("\n");
    }
    else
    {
        printf("%d ", vetor[0]);
        ExibeArray(vetor + 1, n - 1);
    }
    
}

int main()
{
    int v[6] = {1, 2, 3, 4, 5, 6};

    ExibeArray(v, 6);
    return 0;
}