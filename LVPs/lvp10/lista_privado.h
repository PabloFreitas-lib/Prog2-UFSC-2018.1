/*
 * lista_privado.h
 *
 *  Created on: Jun 26, 2018
 *      Author: John
 */

#ifndef LISTA_PRIVADO_H_
#define LISTA_PRIVADO_H_


#include "lista_interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define o tipo lista_t

typedef struct lista lista_t;

//define o tipo celula_t
typedef struct celula celula_t;
 // aux

struct celula {
	void *dado; //dado armazenado na celula. A alocacao de memoria eh responsabilidade do usuario
	struct celula *prox; //proxima celula na lista encadeada
	struct celula *ant;  //celula anterior na lista encadeada
};

struct lista{
	celula_t *cabeca; //ponteiro para a celula cabeca da lista
	celula_t *cauda;  //ponteiro para a celula cauda da lista
	int tamanho;
	void (*destruir)(void *); //ponteiro de funcao usado na funcao de destruir a lista, caso seja valida
	void (*imprime)(const void *); //ponteiro de funcao para imprimir os dados armazenados na lista. Implementacao eh responsabilidade do usuario do TDA
	int (*compara)(const void *, const void *); //ponteiro de funcao para comparar dois dados armazenados na lista. Retorna -1 se o primeiro eh menor que o segundo, 0 se forem iguais, ou 1 se o primeiro for maior que o segundo
};

#endif /* LISTA_PRIVADO_H_ */
	 	  	  		  	    	   		  	       	 	
