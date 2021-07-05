#include <stdio.h>
#define MAX 50

// Funções de Uma Pilha:
/*
    - Inicializar;
    - Quantidade de Elementos;
    - Exibir os elementos;
    - Inserir elementos (push);
    - Excluir elementos (pop);
    - Reinicializar;
*/

enum boolean {false, true};
typedef enum boolean bool;

typedef struct
{
    int info;
}Estrutura;


typedef struct
{
    int topo;
    Estrutura vetor[MAX];
}Pilha;

void Inicializar(Pilha *p)
{
    p->topo = -1; // -1 pois caso fosse 0, haveria a posição.
}

int Quantidade(Pilha *p)
{
    return p->topo + 1;
}

void Exibir(Pilha p)
{
    printf("Pilha: \" ");
    int i;
    for(i = p.topo; i >= 0; i--)
    {
        printf("%i ", p.vetor[i].info);
    }

    printf("\"\n");
}

bool Inserir(Pilha *p, Estrutura dado)
{
    if(p->topo + 1 >= MAX) return false;

    p->topo++;
    p->vetor[p->topo] = dado;

    return true;
}

bool Deletar(Pilha *p, Estrutura lixo)
{
    if(p->topo == -1) return false;

    lixo = p->vetor[p->topo];
    --p->topo;

    return true;
}

int main()
{
    Pilha testes;

    Estrutura d1;
    d1.info = 6;

    Inicializar(&testes);
    Inserir(&testes, d1);  
    Exibir(testes);

    if(Deletar(&testes, d1))
    {
        printf("Dado de Topo excluido.\n");
    }

    d1.info = 67;
    Inserir(&testes, d1);
    d1.info = 8;
    Inserir(&testes, d1);

    Exibir(testes);
}