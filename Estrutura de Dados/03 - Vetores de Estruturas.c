#include <stdio.h>

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
    Ponto q[3];
    
    q[0].x = 1;
    q[0].y = 1;

    q[1].x = 3;
    q[1].y = 1;

    q[2].x = 2;
    q[2].y = 5;

    printf("%f\n", Area(4, q));

    return 0;
}