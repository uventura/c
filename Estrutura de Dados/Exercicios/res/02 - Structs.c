#include <stdio.h>

int main()
{
    typedef struct
    {
        char nome[100];
        int idade;
        char endereco[100];
    } pessoa;

    pessoa p;

    printf("Informe seus dados: \n");

    printf(" Seu nome >> ");
    scanf("%[^\n]s", p.nome);

    printf(" Sua idade >> ");
    scanf("%d", &p.idade);

    setbuf(stdin, NULL);
    printf(" Seu endereço >> ");
    scanf("%[^\n]s", p.endereco);

    printf("\nOlá %s de %d anos que mora em %s.\n", p.nome, p.idade, p.endereco);

    return 0;
}