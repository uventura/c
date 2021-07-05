#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 50

/*

	Filas possuem um comportamento semelhante ao de uma pilha, porém de
maneira inversa, o primeiro elemento inserido será o primeiro a sair
(First In First Out - FIFO), sendo então um comportamento análogo
ao de uma fila, muito útil quando processos devem ser agurdadados.

	Este primeiro caso irá criar uma fila de tamanho definido(estática).
*/

typedef struct
{
	float elementos[MAX]; /* Pode ser utilizado outros tipos de dados.*/
	int ini, fim;
} Fila;

Fila* Criar()
{
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->ini = f->fim = 0;

	return f;
}

void Inserir(Fila* f, float v)
{
	if((f->fim + 1) % MAX == f->ini)
	{
		printf("Fila cheia, impossível inserir novos elementos.\n");
		exit(1);
	}

	f->elementos[f->fim] = v;
	f->fim = (f->fim + 1)%MAX; // Incremento circular.
}

float Remover(Fila* f)
{
	if(f->fim == f->ini)
	{
		printf("Fila vazia");
		exit(1);
	}
		
	float v = f->elementos[f->ini];
	f->ini = (f->ini + 1)%MAX;

	return v;
}

void Exibir(Fila* f)
{
	printf("| Elementos da Fila:\n");

	int i;
	for(i = f->ini; i < f->fim; ++i)
	{
		printf("|   %.3f\n", f->elementos[i]);
	}

	printf("\n");
}

void Liberar(Fila* f)
{
	free(f);
	printf("Memória liberada!\n");
}

int main()
{
	Fila* f = Criar();

	Inserir(f, 2);
	Inserir(f, 3);
	Inserir(f, 5);

	Exibir(f);

	Liberar(f);

	return 0;
}