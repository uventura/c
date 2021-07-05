#include <stdio.h>
#define MAX 50

// Lista Linear Sequencial (Maneira Estática)

typedef struct
{
    int dado;
} info; // O grupo de informações que formam um dado

typedef struct
{
    info dados[MAX];
    int tamanho;
} lista;

void Inicializar(lista *l)
{
    l->tamanho = 0;
}

int Elementos(lista *l)
{
    return l->tamanho;
}

int main()
{
    
}