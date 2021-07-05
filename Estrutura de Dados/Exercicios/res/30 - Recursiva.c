#include <stdio.h>

int recorrencia(int val, int alg)
{
    static int cont = 0;

    if(val < 1) return cont;
    else if((int)(val - 10 * (int)(val / 10)) == alg) ++cont;

    return recorrencia(val / 10, alg);
}

int main()
{
    printf("%d\n", recorrencia(12232125, 2));
    return 0;
}