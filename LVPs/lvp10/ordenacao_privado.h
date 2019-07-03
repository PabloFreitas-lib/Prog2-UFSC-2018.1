/*
 * ordenacao_privado.h
 *
 *  Created on: Jun 26, 2018
 *      Author: John
 */

#ifndef ORDENACAO_PRIVADO_H_
#define ORDENACAO_PRIVADO_H_

#include "ordenacao_interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gen_quicksort(void *array, unsigned int tam, unsigned int TAM, int begin, int end, int (*comparar)(const void *a, const void *b));
void permuta(lista_t *l, celula_t *aux_A, celula_t *aux_B); // bolha

//void change(void *aux_1,void* aux_2, unsigned int tam); // para o quicksort

#endif /* ORDENACAO_PRIVADO_H_ */
