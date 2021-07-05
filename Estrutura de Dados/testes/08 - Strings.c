#include <stdio.h>

// Exibir uma String Recursivamente

void ExibirString(char *txt)
{
    if(txt[0] != '\0')
    {
        printf("%c", txt[0]);
        ExibirString(&txt[1]); // agora a leitura vai começar a partir de 1.
    }

    /*
        Esse código é válido porque txt[0] == txt, o primeiro endereço de txt e
        &txt[1] = txt + 1, portanto, quando ocorrer a chamada de &txt[1], agora
        txt[0] será txt[1], pois as posições são apenas deslocamentos do endereço
        atual. 
    */
}

int main()
{
    ExibirString("Olá, Mundo!\0");
    printf("\n");

    return 0;
}