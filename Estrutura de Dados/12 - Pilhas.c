#include <stdio.h>
#include <stdlib.h>

enum Boolean {true, false};
typedef enum Boolean bool;

// Pilha dinâmica (Não possui Limitações)

typedef struct
{
    int info;
} Estrutura;


typedef struct
{
    int tam;
    Estrutura *lista;
} Pilha;

void Inicializar(Pilha *p)
{
    p->tam = 0;
}

void Finalizar(Pilha *p)
{
    free(p->lista);
}

int Elementos(Pilha p)
{
    return p.tam;
}

void Exibir(Pilha p)
{
    printf("Pilha:");

    int i;
    for(i = 0; i < p.tam; ++i)
        printf(" %d ", p.lista[i].info);
    printf("\n");
}

bool Inserir(Pilha *p, Estrutura dado)
{
    bool resultado = false;
    ++p->tam;

    if(p->tam == 1)
        p->lista = malloc(sizeof(Estrutura));
    else
        p->lista = realloc(p->lista, p->tam * sizeof(Estrutura));

    if(p->lista != NULL)
    {
        p->lista[p->tam - 1] = dado;
        resultado  = true;
    }

    return resultado;
}

bool Remover(Pilha *p, Estrutura *lixo)
{
    Estrutura dado;
    bool resultado = false;

    if(p == 0)
    {
        printf("\n[Impossivel remover]\n");
    }
    else
    {
        resultado = true;

        *lixo = p->lista[p->tam - 1];
        
        --p->tam;
        p->lista = realloc(p->lista, p->tam * sizeof(Estrutura));
    }

    return resultado;   
}

int main()
{
    Pilha p;
    Inicializar(&p);

    Estrutura e;
    
    e.info = 8;
    Inserir(&p, e);
    
    e.info = 15;
    Inserir(&p, e);

    e.info = 20;
    Inserir(&p, e);

    Exibir(p);
    Remover(&p, &e);
    Exibir(p);
    Remover(&p, &e);
    Exibir(p);

    Finalizar(&p);

    return 0;
}