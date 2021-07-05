#include <stdio.h>

int main()
{
    /*
        Unions: diferentemente de uma struct que armazena tipos em seu próprio
        espaço, em uma union tipos iguais ou diferentes pertencem ao mesmo espaço.
            Assim como uma struct, tem a capacidade de lidar com tipos heterogêneos
        que se referem a um mesmo contexto, ou, uma mesma informação.
            A única maior diferença de uma union para uma struct é o fato de que uma
        variável que pertence a uma union não possui seu próprio espaço, sendo então
        dividido entre todos. Geralmente o espaço máximo ocupado por uma union é o
        espaço do tipo que possui a maior quantidade de bytes a serem ocupadas.
            AS unions são usadas quando queremos armazenar valores heterogêneos num
        mesmo espaço de memória.

        * Suas variáveis partilham o mesmo espaço.
        * Somente um campo pode ser acessado por vez.
    */

    union pessoa
    {
        char sexo;
        int idade;
    }; // Por inteiros ocuparem 4bytes e char 1byte, logo, a union ocupa 4bytes.

    // Seus acessos são os iguais a de uma struct.
    union pessoa teste;
    teste.sexo = 'M';
    teste.idade = 48;

    printf("Seu sexo é: %c\n", teste.sexo);
    printf("Sua idade é: %d\n", teste.idade);

    // Não aparece o valor para sexo pois idade está sendo utilizado.
    // nesse caso, quando teste.sexo é chamado, é pegado o primeiro
    // byte da memória que a union que está sendo chamado.

    return 0;
}