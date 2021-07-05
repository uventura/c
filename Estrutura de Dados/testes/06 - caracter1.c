// Aritmética dos Caracteres

#include <stdio.h>

int emAlfabeto(char simbolo)
{
    if(simbolo >= 'A' && simbolo <= 'Z' || simbolo >= 'a' && simbolo <= 'z')
        return 1;
    return 0;
}

char maiuscula(char letra)
{
    if(letra >= 'a' && letra <= 'z') 
        return 'A' + letra - 'a';
    return letra;
}

int main()
{
    char letra;

    printf("Digite uma letra: ");
    scanf("%c", &letra);

    if(emAlfabeto(letra))
        printf(">> '%c' em maiúsculo é '%c'.\n", letra, maiuscula(letra));
    else
        printf(">> Não pertence ao alfabeto.\n");

    return 0;
}