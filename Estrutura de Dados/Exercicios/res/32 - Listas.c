/* Concatenar duas listas */

#include <stdio.h>
#include <malloc.h>

typedef struct lista
{
	float valor;
	lista* ant;
} Lista;

Lista* inserir(Lista* atual, float v)
{
	Lista* l = (Lista*)malloc(sizeof(Lista));
	l->ant = atual;
	l->valor = v;

	return l;
}

int main()
{
	return 0;
}