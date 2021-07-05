//  Implementação das funções: cria, libera, acessa e atribui com matrizes dinâmicas.

#include <stdio.h>
#include <stdlib.h>

struct matriz
{
    int lin, col;
    float *val;
};

typedef struct matriz Matriz;

// Utilizando O Primeiro Método

Matriz *Criar1(int m, int n)
{
    Matriz *mat =  (Matriz *)malloc(sizeof(Matriz));
    
    mat->lin = m;// A variável lin para qual mat aponta.
    mat->col = n;// A variável col para qual mat aponta.
    mat->val = (float *)malloc(m * n * sizeof(float));

    return mat;
}

void Libera1(Matriz *mat)
{
    free(mat->val);
    free(mat);
}

float Acessa1(Matriz *mat, int i, int j)
{
    int p;

    if(i < 0 || i >= mat->lin || j < 0 || j >= mat->col)
    {
        printf("Impossível acessar elemento.");
        exit(1);
    }

    p = i * mat->col + j;
    return mat->val[p]; // Retorna o elemento p da lista val para o qual mat aponta.
}

void Atribui1(Matriz *mat, int i, int j, float v)
{
    if(i < 0 || i >= mat->lin || j < 0 || j >= mat->col)
    {
        printf("Impossível atribuir elemento");
        exit(1);
    }

    mat->val[i * mat->col + j] = v;
}

int main()
{
    Matriz *M = Criar1(2, 2);

    Atribui1(M, 0, 0, 3);
    Atribui1(M, 0, 1, 12);
    Atribui1(M, 1, 0, 14);
    Atribui1(M, 1, 1, 20);

    int i, j;
    printf("Digite a Linha e Coluna do elemento desejado: ");
    scanf("%d %d", &i, &j);

    printf("O elemento é %f\n\n", Acessa1(M, i, j));

    Libera1(M);

    return 0;
}