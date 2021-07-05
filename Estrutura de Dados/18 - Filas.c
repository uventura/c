// Fila Dinâmica( Minha implementação )

#include <stdio.h>
#include <malloc.h>

typedef struct fila
{
	float valor;
	struct fila* proximo;
} Fila;

void* Inicializar()
{
	return NULL;
}

Fila* Inserir(Fila* f, float val)
{
	Fila* novo = (Fila*)malloc(sizeof(Fila));	
	novo->valor = val;
	novo->proximo = NULL;

	if(f != NULL)
	{
		// Buscar o último elemento:
		Fila* aux = f;
		while(aux->proximo != NULL)
			aux = aux->proximo;

		aux->proximo = novo;

		return f;
	}
	
	return novo;
}

Fila* Remover(Fila* f)
{
	if(f == NULL) return NULL;

	Fila* novo = f->proximo;
	free(f);

	return novo;
}

void Exibir(Fila* f)
{
	printf("Fila de Elementos:\n");

	if(f == NULL)
		printf("  Fila Vázia.\n");

	while(f != NULL)
	{
		printf("  %f\n", f->valor);
		f = f->proximo;
	}
}

void Liberar(Fila* f)
{
	Fila* aux = f;
	while(f != NULL)
	{
		aux = f->proximo;
		free(f);
		f = aux;
	}

	printf("Memória liberada.\n");
}

int main()
{
	Fila* f = Inicializar();

	f = Inserir(f, 8);
	f =  Inserir(f, 9);
	f = Inserir(f, 7);

	f = Remover(f);
	f = Remover(f);

	Exibir(f);

	Liberar(f);

	return 0;
}