#include <stdio.h>
#include <malloc.h>

typedef struct lista
{
    int valor; // O próprio valor da lista
    struct lista* anterior; // Endereço para o próximo elemento
} Lista;

Lista* Inicializar(){ return NULL; }

void Finalizar(Lista *l)
{
    Lista* atual = l;
    while(atual != NULL)
    {
        atual = l->anterior;
        free(l);
        l = atual;
    }
}

int Vazia(Lista* l){return l == NULL;};

Lista* Inserir(Lista *l, int valor)
{
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->anterior = l;
    return novo;
}

Lista* Remover(Lista* l, int valor)
{
    Lista* lAtual;
    Lista* lAnterior = NULL;

    for(lAtual = l; lAtual != NULL; lAtual = lAtual->anterior)
    {
        if(lAtual->valor == valor)
        {
            lAnterior->anterior = lAtual->anterior;

            if(lAtual == l)
                l = lAnterior->anterior;

            free(lAtual);
            break;
        }
        lAnterior = lAtual;
    }

    return l;
}

void Exibir(Lista* l)
{
    Lista* atual = l;
    
    while(atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

Lista* Buscar(Lista *l, int valor)
{
    Lista* atual;
    for(atual = l; atual != NULL; atual = atual->anterior)
    {
        if(valor == atual->valor) return atual;
    }
    return NULL;
}

int main()
{
    Lista* num = Inicializar();
    num = Inserir(num, 5);
    num = Inserir(num, 8);
    num = Inserir(num, 9);
    num = Inserir(num, 10);

    num = Remover(num, 8);
    num = Inserir(num, 7);
    
    Exibir(num);

    Lista* k = Buscar(num, 10);
    if(k != NULL) printf("Achei!\n");

    Finalizar(num);

    return 0;
}