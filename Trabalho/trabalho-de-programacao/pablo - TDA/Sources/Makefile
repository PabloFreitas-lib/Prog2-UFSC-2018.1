all: aplicacao

aplicacao: lista.o operacoes.o seleciona.o main.o le_privado.o lista_privado.o operacoes_privado.o
	gcc -o aplicacao lista.o operacoes.o seleciona.o main.o

lista.o:
	gcc -c lista.c

operacoes.o:
	gcc -c operacoes.c

seleciona.o:
	gcc -c seleciona.c

le_privado.o:
	gcc -c le_privado.c

lista_privado.o:
	gcc -c lista_privado.c

operacoes_privado.o:
	gcc -c operacoes_privado.c
	
main.o:
	gcc -c main.c

clean:
	rm *.o aplicacao
