#ifndef lab5_h
#define lab5_h

#include "pilha_privado.h"

typedef struct carro {
	unsigned int manobras;
	char placa[8];
} carro_t;

void estacionamento(const char *arquivo, void (*entrada)(carro_t *), void (*saida)(carro_t *));

#endif