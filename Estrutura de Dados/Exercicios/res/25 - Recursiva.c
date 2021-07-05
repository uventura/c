#include <stdio.h>

int func(int *vetor, int n)
{
    if(n == 0) return 0;
    return vetor[0] + func(vetor + 1, n - 1);
}

int main()
{
    int v[3] = {1, 2, 3};
    printf("%d\n", func(v, 3));

    return 0;
}