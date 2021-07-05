#include <stdio.h>

void InverterElemento(int *vetor, int pos)
{
    *(vetor + pos) = -1 * (*(vetor + pos));
    /*
        vetor + pos é o endereço do elemento pos do vetor. Logo:
            *(vetor + pos) -> é o elemento do vetor.
        Atribuição feita a esse elemento é a de que ele recebe o
        produto de -1 com o elemento que está em vetor + pos, ele
        mesmo.
    */
}

int main()
{
    int a[] = {1, 2, 3, 4};

    InverterElemento(a, 0);
    printf("O elemento modificado agora vale %d.\n", a[0]);

    return 0;
}