// Leitura de Espaços em Strings

#include <stdio.h>

int main()
{
    char NomeCompleto[100];
    printf("Digite seu nome completo: ");
    scanf("%100[^\n]", NomeCompleto); // Irá ler no máximo 100 caracteres
    // e irá parar quando houver \n, ^ indica uma negação da senteça que segue.
    
    // [aeio] poderá ser lido como, leia somente quando houver aeio.
    // [^\n] poderá ser lido como, não leia quando houver \n

    // Observação: \n é o fim de uma string, geralmente o espaço é considerado como \n, algo vazio
    // logo é ignorado.
    //  Geralmente os espaços são a parte ignorada da sentença.

    printf(">> Olá %s!\n", NomeCompleto);
}