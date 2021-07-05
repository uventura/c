#include <stdio.h>
#include <malloc.h>

struct ar
{
	char info;
	struct ar* sae;
	struct ar* sad;
};

typedef struct ar Arvore;

Arvore* inicializar(){return NULL;};

Arvore* criar(char valor, Arvore* sae, Arvore* sad)
{
	Arvore* no = (Arvore*)malloc(sizeof(Arvore));
	no->info = valor;
	no->sae = sae;
	no->sad = sad;

	return no;
}

Arvore* liberar(Arvore* ar)
{
	if(ar != NULL)
	{
		liberar(ar->sae);
		liberar(ar->sad);
		free(ar);
	}

	return NULL;
}

void exibir(Arvore* ar)
{
	printf("<");
	if(ar != NULL)
	{
		printf("%c", ar->info);
		exibir(ar->sae);
		exibir(ar->sad);
	}
	printf(">");
}

int altura(Arvore* ar)
{
	static int alt = -1;
	static int max = -1;

	if(ar != NULL)
	{
		++alt;
		
		if(ar->sae == NULL && ar->sad == NULL)
		{
			if(alt > max) max = alt;
		}
		else
		{
			if(ar->sae != NULL)
			{
				altura(ar->sae);
				--alt;
			}

			if(ar->sad != NULL)
			{
				altura(ar->sad);
				--alt;
			}
		}
	}

	return max;
}

int main()
{
	// Folhas
	Arvore* a0 = criar('e', criar('f', inicializar(), inicializar()), inicializar());
	Arvore* a1 = criar('d', inicializar(), inicializar());
	Arvore* a2 = criar('c', a0, a1);
	Arvore* a3 = criar('b', a2, inicializar());
	Arvore* a4 = criar('a', a3, inicializar());

	exibir(a4);
	printf("\n");

	printf("%d\n", altura(a3));

	liberar(a4);

	return 0;
}