#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int info;
} Dado;


typedef struct aux
{
    Dado d;
    struct aux* anterior;
} Elemento;

typedef struct
{
    Elemento *topo; // Lista de Ponteiros
} Pilha;

typedef enum {false, true} bool;

// Funções

void Inicializar(Pilha *p)
{
    p->topo = NULL;
}

int Tamanho(Pilha *p)
{
    Elemento *ende = p->topo;
    int tam = 0;

    while(ende != NULL)
    {
        ++tam;
        ende = ende->anterior;
    }

    return tam;
}

bool Vazio(Pilha *p)
{
    if(p->topo == NULL) return true;
    return false;
}

void Exibir(Pilha *p)
{
    Elemento *ende = p->topo; // Começa do elemento de topo
    while (ende != NULL)
    {
        printf(" %d ", ende->d.info);
        ende = ende->anterior;
    }
    
    printf("\n");
}

bool Inserir(Pilha *p, Dado d)
{
    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    e->d = d;
    e->anterior = p->topo;

    p->topo = e;

    return true;
}

bool Remover(Pilha *p, Dado *lixo)
{
    if(p->topo != NULL)
    {
        Elemento *elem = p->topo->anterior; // Endereço da memória tpo anterior.
        *lixo = p->topo->d; // Armazena os dados do endereço.

        free(p->topo);
        p->topo = elem;

        return true;
    }
    else
    {
        return false;
    }
}

void Reinicializar(Pilha *p)
{
    Elemento *apagar = p->topo;

    while(apagar != NULL)
    {
        apagar = p->topo->anterior;
        free(p->topo);
    }
}

int main()
{
    Pilha p;
    Dado d;
    d.info = 8;

    Inicializar(&p);
    Inserir(&p, d);
    Exibir(&p);
    Reinicializar(&p);
    Exibir(&p);

    return 0;
}