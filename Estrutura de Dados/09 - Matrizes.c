// Matrizes Dinâmicas

#include <stdio.h>
#include <stdlib.h>

void AtribVal(float *matriz, int colunas, int i, int j, float valor)
{
    matriz[i * colunas + j] = valor;
}

int main()
{
    // 1° Forma de Representação de uma Matriz Dinâmica(Através de um vetor simples)

    /*
        Dado uma matriz 4x4, esta poderia ser representada por um vetor apenas, onde
    seus elementos seriam analisados linearmente, ou seja:
        se M é a matriz e é da forma:
            M = | a  b |
                | c  d |

        Ela poderia ser representada por M = {a, b, c, d}, sendo que para acessar um
    elemento ij, basta que siga a equação posição = i * n + j, sendo n o número de colunas.
        Portanto uma matriz mxn pode ser representada por uma lista. Abaixo a implementação.
    */

    int m = 2, n = 2;
    float *matriz = (float *)malloc(m * n * sizeof(float));

    AtribVal(matriz, n, 0, 0, 2);
    AtribVal(matriz, n, 0, 1, 3);
    AtribVal(matriz, n, 1, 0, 7);
    AtribVal(matriz, n, 1, 1, 13);

    printf("O valor da primeira posição é: %f\n", matriz[0]);
    
    free(matriz);

    // 2° Forma: Matriz Representada por um vetor de ponteiros
    /*
        Desta maneira irá tornar cada linha de uma matriz é um vetor
    independente, logo, a matriz será representada por um vetor, ou vetor
    de ponteiros, no qual cada elemento armazena o endereço do primeiro
    o endereço do primeiro elemento de cada linha. Abaixo um exemplo.
    */

    int i;
    float **mat; // Devem ser **, pois caso fosse um, seria o mesmo que dizer que é um vetor de float
    // Ao usar **, é o mesmo que escrever float**. Ou seja, é um ponteiro de float de um ponteiro de float.

    mat = (float**)malloc(m * sizeof(float *)); // irá criar uma lista de ponteiros float.
    
    for(i = 0; i < m; i++)
        mat[i] = (float*)malloc(n * sizeof(float));

    // Após o uso dessa forma
    for(i = 0; i < m; i++)
        free(mat[i]);
    free(mat);

    // A vantagem do segundo método é o acesso a matrizes da mesma forma que seria estaticamente, mas são
    // necessários mais processos do que a 1° forma.

    return 0;
}