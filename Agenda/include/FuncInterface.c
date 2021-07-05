// INTERFACE

void Titulo(char titulo[100])
{
	int tamanho = strlen(titulo);
	int i;

	printf(" ");
	for(i = 0; i < tamanho + 31; i++)
		printf("=");
	printf("\n ||");

	for(i = 0; i < 28; i++)
	{
		if(i == 15)
			printf("%s", titulo);
		else
			printf(" ");
	}

	printf("||\n ");
	for(i = 0; i < tamanho + 31; i++)
		printf("=");
	printf("\n");
}

void Cabecalho()
{
	system(comandoLimparTela);

	printf("\n");
	Titulo("Tarefas");
		
	printf("\n ");
	Tempo();
	printf(".\n");
}

void Demarcar(char frase[150])
{
	int tamanho = strlen(frase);
	int i = 0;

	printf("\n");
	while(i < tamanho + 10)
	{
		printf("-");
		++i;
	}

	printf("\n");
}