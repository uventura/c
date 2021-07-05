#include <stdio.h>
#include <math.h>

/*
    Struct:
        É uma estrutura de dado que representa um conjunto de
    dados(variáveis) que se referem a um ente que então forma um tipo.

        Este é um tipo de estrutura heterogênea, ou seja, os tipos
    que a compõe não necessariamente devem ser do mesmo tipo.

        O objetivo é estruturar dados complexos, nos quais as infor-
    mações são compostas por diversos tipos. Uma estrutura em C, serve
    basicamente para agrupar diversas variáveis dentro de um único con-
    texto.
*/

typedef struct{
    float x, y, z;
} vetor;

float modulo(vetor v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

int main()
{
    vetor vel;
    vel.x = 5;
    vel.y = 6;
    vel.z = 7;

    printf("O moódulo do vetor é: %f\n", modulo(vel));

    return 0;
}