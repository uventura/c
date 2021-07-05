#include <stdio.h>

int main()
{
    typedef struct
    {
        int hora, minutos, segundos;
    } horario;

    typedef struct 
    {  
        int dia, mes, ano;
    } data;

    typedef struct
    {
        horario h;
        data d;
    } compromisso;
    

    return 0;
}