#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    float x, y;
}Ponto;

float Area(int n, Ponto *p)
{
    int i, j;
    float a = 0;

    for(i = 0; i < n; i++)
    {
        j = (i + 1) % n;
        a += (p[j].x - p[i].x) * (p[i].y + p[j].y) / 2;
    }

    if(a < 0) return -a;
    return a;
}

int main()
{
    int n;

    printf("Digite o número de Pontos: ");
    scanf("%d", &n);

    Ponto *q;
    q = (Ponto *)malloc(sizeof(Ponto) * n); // Retorna o ponteiro onde está alocado o espaço.

    int i;
    for(i = 0; i < n; i++)
    {
        printf("Digite os valores de x e y: ");
        scanf("%f %f", &q[i].x, &q[i].y);
    }

    printf("Area = %f\n", Area(n, q));

    return 0;
}