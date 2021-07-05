#include <stdio.h>

int main()
{
    /*
        Alocação Estática e Dinâmica:
            A alocação estática geralmente possui a característica de criar
        uma reserva de memória fixa na pilha de execução do programa, diferentemente
        de uma alocação dinâmica que somente quando solicitado uma determinada quantidade
        de espaço que irá ocupar, mas não irá ocupar uma memória que faz parte da pilha
        de execução do programa, por isso a utilização de ponteiros para que seja utilizada.

        Para mudar a memória de uma função alocada dinâmicamente:
            (ponteiro de conversão)realloc(variável que recebe o ponteiro, novo tamanho em bytes)

            Vale salientar que, sempre que possível, optamos por trabalhar com vetores criados estati
        camentente. Eles tendem a ser mais eficientes, já que os vetores alocados dinamicamente
        tem uma indireção a mais, primeiro acessa-se o valor do endereço armazenado na variável
        ponteiro para então acessar o elemento do vetor).

            Por esse motivo acima que também é melhor a utilização de matrizes estáticas quando possível.
        Como:
            typedef float matriz4[4][4]; // o mesmo que typedef float matriz[4][4] matriz4;
    */
    return 0;
}