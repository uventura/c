# Esta é a maneira de escrever comentários

all: teste # Nome do Makefile gerado.

teste: main.o teste.o # o arquivo gerado depende deste dois programas objetos.
	gcc -o teste teste.o main.o # O programa gerado será deste, que deriva de teste.o e main.o, os dois serão ligados
	# Este é o arquivo final, ele é quem diz que o arquivo final irá juntar tanto main.o quanto teste.o

teste.o: teste.c
	gcc -o teste.o -c teste.c  -W -Wall -ansi -pedantic
	# teste.o é um arquivo objeto que depende de teste.c, portanto ele derverá ser compilado

main.o: main.c teste.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic
	# main.o é um arquivo objeto que depende de main.c e teste.h, por tanto ocorrerá a junção
	# dos dois, e o comando gcc utilizado é justamente para gerar este arquivo objeto

clean:
	rm -rf *.o
	# Limpar os arquivos objetos que foram gerados.

mrproper: clean
	rm -rf teste # Apaga os Binários gerados

# O que no final ocorreu foram os seguintes fatos:
	# 1° Gerar um arquivo de execução sendo que devem ser considerado as suas dependências.
	# 2° Verificar as dependências dos arquivos que o arquivo de execução depende.
	# 3° Compilar e definir a compilação de cada um dos arquivos objetos.

# O tipo de compilação que geralmente seria feita é dada por:
	# gcc main.c -o programa teste.c