#include <stdio.h>

int main()
{
    typedef struct
    {
        char nome[120], curso[50];
        int matricula;
    } aluno;

    aluno alunos[5];
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("Bem Vindo Aluno %d, informe: \n", i + 1);
        printf(" Seu nome: ");
        scanf("%[^\n]s", alunos[i].nome);

        setbuf(stdin, NULL);
        printf(" Seu curso: ");
        scanf("%[^\n]", alunos[i].curso);

        printf(" Sua Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        setbuf(stdin, NULL);
        printf("\n>> Olá aluno %s (%d) de %s!\n\n", alunos[i].nome, alunos[i].matricula, alunos[i].curso);
    }

    return 0;
}