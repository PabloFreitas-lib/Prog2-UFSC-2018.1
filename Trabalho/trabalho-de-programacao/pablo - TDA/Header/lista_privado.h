#ifndef lista_privado_h
#define lista_privado_h
#include "../Header/lista_interface.h"
#include "../Header/le_interface.h"
#include "../Header/operacoes_interface.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

struct celula {
	void *dado; //dado armazenado na celula. A alocacao de memoria eh responsabilidade do usuario
	struct celula *prox; //proxima celula na lista encadeada
	struct celula *ant;  //celula anterior na lista encadeada
};

struct lista {
	celula_t *cabeca; //ponteiro para a celula cabeca da lista
	celula_t *cauda;  //ponteiro para a celula cauda da lista
	int tamanho;
};

int lista_remove(lista_t *l, celula_t *c, void **elem);

int lista_insere_anterior(lista_t *l, celula_t *c, const void *elem);

int lista_insere_proximo(lista_t *l, celula_t *c, void *elem);

#endif
