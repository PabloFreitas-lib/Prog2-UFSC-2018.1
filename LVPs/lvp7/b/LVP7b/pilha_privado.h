/*
 * pilha_privado.h
 *
 *  Created on: Jun 23, 2018
 *      Author: John
 */

#ifndef PILHA_PRIVADO_H_
#define PILHA_PRIVADO_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha_interface.h"

struct pilha{
	void *elementos;
	unsigned int tamanho_elemento;
	unsigned int topo;
	unsigned int capacidade;
};
typedef struct pilha pilha_t;

#endif /* PILHA_PRIVADO_H_ */
