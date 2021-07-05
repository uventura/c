#include <stdio.h>

int main()
{
    int n;
    printf("Digite o fatorial desejado: ");
    scanf("%d", &n);

    printf(" O fatorial de %d é ", n);
    if(n == 0)
    {
        printf("1");
    }
    else if(n > 0)
    {
        int resultado = 1;
        int i;

        for(i = 0; i < n; i++)
            resultado *= (n - i);

        printf("%d.\n", resultado);
    }
    else
    {
        printf("não definido.\n");
    }
    

    return 0;
}