#include <stdio.h>

typedef struct
{
    float x, y, z;
} Vetor;

Vetor Soma(Vetor a, Vetor b)
{
    Vetor res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    res.z = a.z + b.z;

    return res;
}

int main()
{
    Vetor v1, v2;

    v1.x = 10;
    v1.y = 13;
    v1.z = 11;

    v2.x = 11;
    v2.y = 5;
    v2.z = 7;

    Vetor resultante = Soma(v1, v2);
    printf("%f\n", resultante.x);

    return 0;
}