#include <stdio.h>

// Exibir uma string inversamente, sem utilizar recursividade.
// Para que seja recursiva basta inverter a ordem em 08 na função.

int TamStr(char *txt)
{
    int i;
    for(i = 0; txt[i] != '\0'; i++);

    return i;
}

void InverteStr(char *txt)
{
    int n = TamStr(txt) - 1;

    for(n; n >= 0; --n)
        printf("%c", txt[n]);
}

int main()
{
    InverteStr("corvo\0");
    printf("\n");
    return 0;
}

// Outro Teste Recursivo:

void CopiaRec(char *dest, char *orig)
{
    dest[0] = orig[0];
    if(dest[0] != '\0')
        CopiaRec(&dest[1], &orig[1]);
}