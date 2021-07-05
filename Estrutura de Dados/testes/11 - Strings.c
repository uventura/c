#include <stdio.h>
#include <stdlib.h>

int TamStr(char *str)
{
    // Retorna o Tamanho de uma String.

    int i;
    for(i = 0; str[i] != '\0'; ++i);

    return i;
}

char *Duplicar(char *str)
{
    // Cria uma Cópia de uma String dinâmicamente.

    int max = TamStr(str);
    char *duplicata = (char *)malloc((max + 1) * sizeof(char));

    duplicata[max] = '\0';
    for(--max; max >= 0; --max)
        duplicata[max] = str[max];

    return duplicata;
    // A função ao chegar ao final libera duplicata e os dados são atribuidos
    // a quem recebe o retorno.
}

int main()
{
    char *palavra = Duplicar("Ola");
    printf("%s\n", palavra);

    return 0;
}