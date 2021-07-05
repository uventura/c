#include <time.h>

char *comandoLimparTela = "clear";

void Tempo()
{
	struct tm *tempo;
	
	time_t segundos;
	time(&segundos);
	
	tempo = localtime(&segundos);

	printf("Data: %d/%d/%d, Hora: %d:%d", tempo->tm_mday, tempo->tm_mon + 1, tempo->tm_year + 1900, 
		tempo->tm_hour, tempo->tm_min);
}

int elevado(int base, int expoente)
{
	if(expoente == 0)
		return 1;
	return base * elevado(base, expoente - 1);
}

int numerico(char valor[100])
{
	int tamanho = strlen(valor);
	int i = 0;

	int convertido = 0;

	while(i < tamanho)
	{
		if((valor[i] >= '0' && valor[i] <= '9'))
		{
			return -1;
		}
		else
		{
			convertido += elevado(10, tamanho - i) * (valor[i] - '0');
		}

	}

	return convertido;
}

int Vizinho(int valor, int min, int max)
{
	if(valor >= min && valor <= max)
		return 1;
	return 0;
}

FILE *AbrirArquivo(char nome[100], char tipo[2])
{

	FILE *arquivo;

	if(tipo[1] == '+' || tipo[1] == ' ')
	{
		arquivo = fopen(nome, tipo);
	}
	else
	{
		printf("Impossivel abrir o arquivo, pois seu tipo e %c%c.\n", tipo[0], tipo[1]);
		return 0;
	}

	if(!arquivo)
	{
		printf("Arquivo nao encontrado.\n");
		return 0;
	}
	else
	{
		return arquivo;
	}

}