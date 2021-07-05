#include <stdio.h>

int main()
{
    
    char s1[] = "Rio de Janeiro"; // O espaço ocupado será de 15 bytes.
    char *s2 = "Rio de Janeiro"; // é apenas um ponteiro para onde está localizado "Rio de Janeiro".
    
    // Para Demonstrar a diferença:
    printf("Tamanhos: s1 -> %ld e s2 -> %ld\n", sizeof(s1), sizeof(s2));

    // Observação: Não é possível alterar s2, somente s1. Portanto s2 é constante, pois
    // ela apenas aponta para uma área constante.
    return 0;
}