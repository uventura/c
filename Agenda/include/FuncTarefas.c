// FUNÇÕES DE TAREFAS

void DefinirTarefa(tarefa *t, char titulo[100], int hora, int minuto)
{
	strcpy(t->titulo, titulo);
	t->tempo.hora = hora;
	t->tempo.minuto = minuto;
}

void AdicionarTarefas(tarefa *NovasTarefas, int quantidade)
{
	FILE *arquivo = AbrirArquivo("agenda.txt", "a+");

	if(arquivo)
	{
		int i;
		for(i = 0; i < quantidade; i++)
			fwrite(&NovasTarefas[i], sizeof(tarefa), 1, arquivo);
	}

	fclose(arquivo);
}

void ExcluirTarefa(int idTarefa)
{
	FILE *arquivo = fopen("agenda.txt", "r+");
	tarefa *tarefas = malloc(sizeof(tarefa));
	tarefa tarefaExcluida;

	int id = 1;

	do{
		if(id == idTarefa)
			fread(&tarefaExcluida, sizeof(tarefa), 1, arquivo);
		
		tarefas = realloc(tarefas, id * sizeof(tarefa));
		fread(&tarefas[id - 1], sizeof(tarefa), 1, arquivo);

		++id;
	}while(!feof(arquivo));

	fclose(arquivo);
	arquivo = fopen("agenda.txt", "w");

	fwrite(tarefas, (id - 2) * sizeof(tarefa), 1, arquivo);
	fclose(arquivo);

	free(tarefas);
}

void LimparTarefas()
{
	FILE *arquivo = fopen("agenda.txt", "w");
	fclose(arquivo);
}

void ExibirTarefa(int idTarefa)
{
	FILE *arquivo = AbrirArquivo("agenda.txt", "r ");

	if(arquivo)
	{
		int id = 1;
		tarefa membro;

		while(!feof(arquivo))
		{
			fread(&membro, sizeof(tarefa), 1, arquivo);

			if(id == idTarefa)
			{
				printf("  |   Titulo: %s\n", membro.titulo);
				
				if(Vizinho(membro.tempo.hora, 0, 23) && Vizinho(membro.tempo.minuto, 0, 59))
				{
					printf("  |   Horario: %02d:%02d\n", membro.tempo.hora, membro.tempo.minuto);
				}

				if(Vizinho(membro.tempo.dia, 1, 31) && Vizinho(membro.tempo.mes, 1, 12))
					printf("  |   Data: %02d/%02d/%d\n", membro.tempo.dia, membro.tempo.mes, membro.tempo.ano);

				if(strcmp(membro.categoria, " "))
					printf("  |   Categoria: %s\n", membro.categoria);
				
				if(strcmp(membro.desc, " "))
					printf("  |   Descricao: %s\n", membro.desc);

				break;
			}

			++id;
		}
	}

	fclose(arquivo);
}

void ExibirTarefas()
{
	FILE *arquivo = AbrirArquivo("agenda.txt", "r ");

	if(arquivo)
	{
		tarefa membro;
		int id = 1;

		while(1)
		{
			fread(&membro, sizeof(tarefa), 1, arquivo);
			if(feof(arquivo))
				break;

			printf(" | %d. %s", id, membro.titulo);

			if(membro.tempo.hora >= 0 && membro.tempo.hora < 24 && membro.tempo.minuto >= 0 && membro.tempo.minuto < 60)
			{
				printf(" - %d:%d", membro.tempo.hora, membro.tempo.minuto);
			}
			printf("\n");

			++id;
		}
	}

	fclose(arquivo);
}