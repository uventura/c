#include <stdio.h>

float media(float *valores, int n)
{
    int res;

    int i;
    for(i = 0; i < n; i++)
        res += valores[i];
    
    return res / n;
}

int main()
{
    typedef struct
    {
        int matricula;
        char nome[120];
        float nota[3];
    } aluno;

    int n = 2; // Números de Alunos Analisados

    aluno alunos[n];
    float medias[n];
    int idMaior = 0, idMenor = 0; // Maiores e Menores notas de Primeira Prova
    int idMediaMaior = 0, idMediaMenor = 0;
    int res[n];

    int i, j;
    for(i = 0; i < n; i++)
    {
        printf("Bem vindo aluno %d, informe: \n", i + 1);
        printf(" Sua matricula: ");
        scanf("%d", &alunos[i].matricula);

        setbuf(stdin, NULL);
        printf(" Seu Nome: ");
        scanf("%[^\n]s", alunos[i].nome);

        setbuf(stdin, NULL);
        for(j = 0; j < 3; j++)
        {
            printf("  Nota de sua %dº prova: ", j + 1);
            scanf("%f", &alunos[i].nota[j]);
        }

        medias[i] = media(alunos[i].nota, 3);
        
        if(alunos[i].nota[0] > alunos[idMaior].nota[0])
            idMaior = i;
        else if(alunos[i].nota[0] < alunos[idMenor].nota[0])
            idMenor = i;

        if(medias[i] > medias[idMediaMaior])
            idMediaMaior = i;
        else if(medias[i] < medias[idMediaMenor])
            idMediaMenor = i;
    }

    // O resto é apenas mensagens a serem apresentadas.

    printf("Aluno com maior nota de primeira prova: %d\n", idMaior);
    printf("Aluno com menor nota de primeira prova: %d\n", idMenor);

    printf("Aluno com maior média geral: %d\n", idMediaMaior);
    printf("Aluno com menor média geral: %d\n", idMediaMenor);

    return 0;
}