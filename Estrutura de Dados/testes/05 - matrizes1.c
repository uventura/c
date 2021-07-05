#include <stdio.h>

/* Esses foram testes para provar que matrizes não possuem
uma soma linear na aritmética de ponteiros.*/

float **ObterElemento(float **matriz, int nColunas, int i, int j)
{
    return matriz + nColunas * i - nColunas + j - 1;
}

int main()
{
    float m[2][2] = 
    {
        2.0f, 3.0f,
        4.0f, 5.0f
    };

    //float **a = ObterElemento(m, 2, 1, 2);

    printf("%p\n", &m[1][0]); //    140736294903184
    printf("%f\n", *(&m[1][0])); // 140721718813284
                                 // 140734247419592

    return 0;
}