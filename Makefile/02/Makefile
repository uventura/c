all: executavel

executavel: main.o cab.o
	@g++ -o executavel main.o cab.o
	# O arquivo executavel foi gerado com sucesso.

cab.o: cab.cpp
	@g++ -o cab.o -c cab.cpp

main.o : main.cpp cab.h
	@g++ -o main.o -c main.cpp

clean:
	@rm -rf *.o

mrproper:
	@rm -rf executavel