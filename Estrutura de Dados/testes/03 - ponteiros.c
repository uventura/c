#include <stdio.h>

void trocar(int *, int *);

int main()
{
    int a = 5, b = 6;

    printf("a = %d e b = %d.\n", a, b);
    
    trocar(&a, &b);
    printf("Ao trocar -> a = %d e b = %d\n", a, b);

    return 0;
}

void trocar(int *pa, int *pb)
{
    int tmp;
    tmp = *pa; // O valor para qual pa aponta será atribuido a tmp;.

    *pa = *pb; // O lugar para onde pa aponta receberá o valor para qual pb aponta.
    *pb = tmp; // O logal para qual pb aponta receberá tmp.
}