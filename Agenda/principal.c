/* [LISTA DE TAREFAS] 
	
	Observações:
		Para um sistema operacional diferente de Linux, vá em FuncPrincipais.c e
	modifique a variável comandoLimparTela para um valor diferente que resulte na
	limpeza de tela do terminal.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "include/Tipos.c"
#include "include/FuncPrincipais.c"
#include "include/FuncInterface.c"
#include "include/FuncTarefas.c"


int main()
{
	char comando[2];

	while(1)
	{
		Cabecalho();

		Demarcar(" Comandos Disponiveis:");
			printf("%s\n\n", " Comandos Disponiveis:");

			printf("  [A] - Adicionar Tarefas.\n");
			printf("  [E] - Exibir Todos as Tarefas.\n");
			/*printf("  [C] - Criar o Arquivo txt das Tarefas.\n");*/
			printf("  [S] - Sair.");
		Demarcar(" Comandos Disponiveis:");

		printf("\n Digite um comando: ");
		scanf("%c", &comando[0]);

		if(comando[0] == 'e' || comando[0] == 'E')
		{
			// EXIBIÇÃO DE TAREFAS

			system(comandoLimparTela);
			int item = 0, sele = 0;

			comando[0] = ' ';

			setbuf(stdin, NULL);

			do
			{
				Cabecalho();

				printf("\n Observacoes:\n");
				printf("  1) Para exibir um item basta digitar e + numero do item.\n");
				printf("  2) Para excluir um item basta digitar r + numero do item.\n");

				Demarcar(" Tarefas Existentes: ");
					printf(" Tarefas Existentes: \n\n");

				ExibirTarefas();

				if(comando[0] == 'e' || comando[0] == 'E' || sele == 1)
				{
					scanf("%d", &item);
					sele = 1;

					Demarcar(" Informações do Item n:");
						printf(" Informações do item %d: \n\n", item);

					ExibirTarefa(item);

					comando[0] = ' ';
					setbuf(stdin, NULL);	
				}
				
				if(comando[0] == 'r' || comando[0] == 'R')
				{
					scanf("%d", &item);
					ExcluirTarefa(item);

					sele = 0;
				}
				else if(comando[0] == 'l' || comando[0] == 'L')
				{
					LimparTarefas();
					sele = 0;
				}

				Demarcar(" Tarefas Existentes: ");

				printf(" Digite um comando: ");
				scanf("%c", &comando[0]);

				if(comando[0] == 's' || comando[0] == 'S')
					break;

			}while(1);
		}
		else if(comando[0] == 'a' || comando[0] == 'A')
		{
			// ADICIONAR TAREFAS

			setbuf(stdin, NULL);

			int itens = -1;
			while(itens < 0 || itens >= 200)
			{
				Demarcar(" Digite o Numero de tarefas:");
				printf(" Digite o Numero de tarefas: ");
				scanf("%d", &itens);
				setbuf(stdin, NULL);
			}

			tarefa tarefas[itens];

			printf("\n >>> Adicionar Tarefas:");

			int i = 0;
			for(i = 0; i < itens; i++)
			{
				
				printf("\n  Tarefa n°%d: \n", i + 1);

				printf("   Titulo: ");
				scanf("%[^\n]s", tarefas[i].titulo);
				setbuf(stdin, NULL);

				if(!strcmp(tarefas[i].titulo, "s"))
					break;
				
				printf("   Horario (hh:mm): ");
				scanf("%d:%d", &tarefas[i].tempo.hora, &tarefas[i].tempo.minuto);
				setbuf(stdin, NULL);

				if(!Vizinho(tarefas[i].tempo.hora, 0, 23) || !Vizinho(tarefas[i].tempo.minuto, 0, 59))
					tarefas[i].tempo.hora = 25;

				printf("   Data (dd/mm/aa): ");
				scanf("%d/%d/%d", &tarefas[i].tempo.dia, &tarefas[i].tempo.mes, &tarefas[i].tempo.ano);
				setbuf(stdin, NULL);

				if(!Vizinho(tarefas[i].tempo.dia, 1, 30) || !Vizinho(tarefas[i].tempo.mes, 1, 12))
				{
					tarefas[i].tempo.dia = 0;
					tarefas[i].tempo.mes = 0;
					tarefas[i].tempo.ano = 0;
				}

				printf("   Categoria: ");
				scanf("%[^\n]s", tarefas[i].categoria);
				setbuf(stdin, NULL);

				if(!strcmp(tarefas[i].categoria, "x"))
					strcpy(tarefas[i].categoria, " ");

				printf("   Descricao: ");
				scanf("%[^\n]s", tarefas[i].desc);

				if(!strcmp(tarefas[i].desc, "x"))
					strcmp(tarefas[i].desc, " ");

				setbuf(stdin, NULL);
			}

			if(i)
				AdicionarTarefas(tarefas, i);
		}
		else if(comando[0] == 's' || comando[0] == 'S')
		{
			// Sair do Programa
			break;
		}

		setbuf(stdin, NULL);
	}

	Demarcar(" Ate mais!\0");
	printf(" Ate mais!\n\n");

	return 0;
}