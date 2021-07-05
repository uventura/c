// Listas Duplamente Encadeadas
#include <stdio.h>
#include <malloc.h>

typedef struct lista
{
	int valor, indice;
	struct lista* ant;
	struct lista* prox;
} Lista;

Lista* Inserir(Lista* list, int valor)
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->valor = valor;
	novo->indice = list == NULL? 0: list->indice + 1;
	novo->ant = list;
	novo->prox = NULL;

	if(list != NULL)
		list->prox = novo; // Valor para o qual o antigo elemento principal aponta;

	return novo;
}

Lista* Remover(Lista* list, int indice, int* armazena)
{
	Lista* ativo = list;

	if(list == NULL) return NULL;

	if(indice > list->indice || indice < 0)
	{
		printf("\n Impossivel Remover Elemento, fora do indice.\n");
		return list;
	}
	else if(indice == list->indice)
	{
		*armazena = list->valor;
		ativo = list->ant;

		if(ativo != NULL)
			ativo->prox = NULL;

		free(list);
		return ativo;
	}

	int i;
	for(i = list->indice; i > 0; --i)
	{
		ativo->indice -= 1;
		ativo = ativo->ant;
	}

	ativo->prox->ant = ativo->ant;

	if(ativo->ant != NULL) ativo->ant->prox = ativo->prox;
	free(ativo);

	return list;
}

void Exibir(Lista* list)
{
	printf("\nElementos: ' ");
	while(list != NULL)
	{
		printf("%d ", list->valor);
		list = list->ant;
	}
	printf("'\n");
}

Lista* Liberar(Lista* list)
{
	Lista* ativo = list;
	while(ativo != NULL)
	{
		ativo = list->ant;
		free(list);
		list = ativo;
	}

	printf("\nMemória Liberada.\n");
}

int main()
{
	int a;
	Lista* l = NULL;

	l = Inserir(l, 5);
	l = Inserir(l, 6);
	l = Inserir(l, 7);
	Exibir(l);
	l = Remover(l, 0, &a);
	Exibir(l);
	l = Liberar(l);

	return 0;
}