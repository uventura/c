#include <stdio.h>

int main()
{
    /*
        Enumerate: permite atribuir nomes para
    constantes inteiras que pertencem a um conjunto
    que será o de enumerate.
    */

    enum bool{
        False, // Irá receber 0 já que não foi definido o seu valor
        True // Por seu anterior ser 0, seu valor será o seguido dele, 1.
    };

    typedef enum bool Bool;

    Bool aberto; // aberto poderá os valores que estão contidos no enumerate.
    aberto = True;

    return 0;
}