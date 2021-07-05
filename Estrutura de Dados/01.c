/*
    Estrutura de Dados: é uma forma de lidar com os dados de maneira que torna
mais fácil manipular tipos de dados, ou seja, um método de orga-
nização de dados que surge através de técnicas de programação. 
*/

/*
    Compilando Arquivos com vários arquivos fonte:
        Quando um arquivo é subdividido em vários, como por exemplo, principal.c
    e secundario.c, onde a execução ocorre em principal.c mas depende de secundario.c
    , para formar um arquivo objeto que seja a junção de ambos, será:

        gcc -o executavel secundario.c principal.c

    outra forma é:
        gcc -c secundario.c
        gcc -c principal.c
        gcc -o executavel secundario.c principal.c

    nesse caso é mais útil pois caso somente secundário seja modificado, basta compilar
    somente ele de novo, e então executar o último comando.

    * Observação: -c é uma flag que realiza compilação sem fazer o processo de linking.
*/