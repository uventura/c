#include <stdio.h>
#include <malloc.h>
#define MAX 50

typedef struct
{
	int ini, fim;
	float elementos[MAX];
}FilaDu;

FilaDu* criar()
{
	FilaDu* f = (FilaDu*)malloc(sizeof(FilaDu));
	f->ini = f->fim = 0;
	return f;
}

void inserirIni(FilaDu* f, float val)
{
	if(f->ini - 1 != f->fim)
	{
		f->elementos[f->ini] = val;

		if(f->ini - 1 < 0)
			f->ini = MAX - 1;
		else --f->ini;
	}
	else
	{
		printf("Impossível inserir novos elementos.\n");
	}
}

void inserirFim(FilaDu* f, float val)
{
	if((f->fim + 1) % MAX == f->ini)
	{
		printf("Impossível inserir novos elementos.\n");
	}
	else
	{
		if(f->fim == 0) ++f->fim;

		f->elementos[f->fim] = val;
		f->fim = (f->fim + 1)%MAX;
	}
}

void liberar(FilaDu* f)
{
	free(f);
	printf("Memória Liberada!\n");
}

int main()
{
	FilaDu* f = criar();

	inserirIni(f, 5);
	inserirIni(f, 6);
	inserirIni(f, 7);
	inserirIni(f, 8);

	liberar(f);
	return 0;
}