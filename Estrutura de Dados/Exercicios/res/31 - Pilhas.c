/*
    Escreva um programa solicite ao usuario uma sequencia de caracteres
sem limite de máximo de tamanho e realize as seguintes operações usando
uma pilha:
a) Imprimir o texto na ordem inversa;
b) Verificar se o texto é um palíndromo, ou seja, se a string é escrita da
mesma maneira de frente para trás e de trás para frente. Ignore espaços e
pontos.
*/

#include <stdio.h>
#include <malloc.h>

typedef struct ElemAux
{
    char letra;
    struct ElemAux *lAnterior; // Utilizado Para variáveis de topo
    struct ElemAux *lProx; // Utilizado Para variáveis de base
} Elemento;

typedef struct 
{
    Elemento *topo;
    Elemento *base;
    int tamanho;
} Pilha;

typedef enum {false, true} bool;

bool push(Pilha *p, char letra)
{
    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    if(e == NULL) return false;

    e->letra = letra;
    e->lAnterior = p->topo;
    e->lProx = NULL;

    if(p->topo == NULL) p->base = e;
    else p->topo->lProx = e;

    p->topo = e;
    ++p->tamanho;

    return true;
}

bool popTopo(Pilha *p, char *local)
{
    if(p->topo == NULL) return false;

    Elemento *e = p->topo->lAnterior;
    *local = p->topo->letra;

    free(p->topo);
    p->topo = e;
    --p->tamanho;

    return true;
}

bool popBase(Pilha *p, char *local)
{
    if(p->topo == NULL) return false;

    Elemento *e = p->base->lProx;
    *local = p->base->letra;

    free(p->base);
    e->lAnterior = NULL;
    p->base = e;
    --p->tamanho;

    return true;
}

void Finalizar(Pilha *p)
{
    Elemento *e;

    int i;
    for(i = 0; i < p->tamanho; i++)
    {
        e = p->topo->lAnterior;
        free(p->topo);
        p->topo = e;
    }
}

// Problema
bool Palindromo(Pilha *p)
{
    char a, b;

    int i = 0;
    while(i <= p->tamanho)
    {
        popTopo(p, &a);
        popBase(p, &b);

        if(a != b) return false;
        i += 2;
    }

    return true;
}

int main()
{
    Pilha letras;
    letras.base = NULL;
    letras.topo = NULL;
    letras.tamanho = 0;

    printf("Digite sua palavra: ");
    while(1)
    {
        char letra;
        scanf("%c", &letra);
        
        if(letra == '\n') break;
        push(&letras, letra);
    }

    if(!Palindromo(&letras)) printf("Não ");
    printf("é Palindromo.\n");

    Finalizar(&letras);
    return 0;
}