#include <stdio.h>

void verifica()
{
    static int var = 0; /* variáveis estáticas vão para áreas que não ocorrem mudanças
    , quando esta função é chamada por uma segunda vez, ao invés de ocorrer a redeclaração
    da variável, será recuperado seu estado anterior.
        Uma forma de analisar é que statica é também uma reserva de memória, que sempre veri
    fica se no espaço estático da memória essa variável já foi reservada, se verdadeiro, irá
    resgatar o valor e ignorar a atribuição, caso falso, irá criar essa reserva e criando a
    atribuição na memória.
        É muito útil para descobrir estados anteriores de variáveis.
    */

    int i;
    for(i = 0; i < 8; i++)
        var++;

    printf("O valor de var é %d.\n", var);
}

int main()
{
    verifica();
    verifica();

    return 0;
}