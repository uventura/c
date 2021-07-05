typedef struct
{
	int dia, mes, ano, hora, minuto;
} data;

typedef struct
{
	char titulo[100], categoria[50], desc[300];
	data tempo;
} tarefa;