#include <stdio.h>

int Menor(int *vetor, int n)
{
    if(n == 1) return vetor[0];

    if(vetor[0] < vetor[1])
        vetor[1] = vetor[0];

    Menor(vetor + 1, n - 1); 
}

int main()
{
    int v[4] = {1, 2, 3, 0};
    printf("%d\n", Menor(v, 4));
    return 0;
}