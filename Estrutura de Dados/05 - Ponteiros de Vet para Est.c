// Vetores de Ponteiros para Estruturas

#include <stdio.h>
#include <stdlib.h>

/*
    O espaço ocupado por um vetor de estrutura é muito grande
uma forma de evitar isso é criar um ponteiro de vetor de estruturas
assim cada elemento é um ponteiro, ao invés de ser um dado.
*/

struct pessoa
{
    char nome[121];
    int idade;
    float altura;
};

typedef struct pessoa* PPessoa; // Ponteiro de Pessoa

int main()
{
    int n = 50; // Máximo de pessoas.
    PPessoa P[n];

    printf("Um grupo de %d estruturas ocupam: %ld bytes.\n", n, sizeof(struct pessoa) * n);
    printf("O vetor dos ponteiros da estrutura ocupam: %ld bytes.\n", sizeof(PPessoa) * n);

    // O problema principal é a quantidade de memória que uma variável ocupa durante a execução.
    // Nesse caso é útil utilizar ponteiros pois a quantidade de pessoas é indefinida, logo
    // basta criar um vetor dos ponteiros, pois a seguir, é suficiente alocar dinâmicamete
    // a quantidade de espaço que deseja-se, ao invés de durante toda a execução já ocupar tudo;

    int q;
    printf("Digite a quantidade de pessoas desejadas: ");
    scanf("%d\n", &q);

    int i;
    for(i = 0; i < q; i++)
    {
        P[i] = (PPessoa)malloc(sizeof(struct pessoa)); // assim a quantidade utilizada é ajustável.
        // Será alocado dinâmicamente uma memória para ocupar a estrutura pessoa, e o endereço será retornado

        printf("Pessoa %d: \n", i + 1);
        printf(" Digite o nome da pessoa: ");
        scanf("%[^\n]", P[i]->nome); // Endereço do campo nome para o qual P[i] aponta

        printf(" Digite a sua idade: ");
        scanf("%d", &P[i]->idade);

        printf(" Digite sua altura: ");
        scanf(" %f", &P[i]->altura);
    }

    // AQUI FICA O CÓDIGO DE USO DA VARIÁVEL

    for(i = 0; i < q; i++)
        free(P[i]);
        
    return 0;
}