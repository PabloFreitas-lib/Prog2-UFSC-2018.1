#ifndef lista_interface_h
#define lista_interface_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct lista lista_t;
typedef struct celula celula_t;
typedef struct baba estrutura;
typedef struct sasa informacao_jogadores;
typedef struct aba horario;

lista_t *lista_cria(void);

void lista_destroi(celula_t *c);

int lista_vazia(lista_t *l);

int lista_tamanho(lista_t *l);

celula_t *lista_cabeca(lista_t *l);

celula_t *lista_cauda(lista_t *l);

void *lista_dado(celula_t *c);

celula_t *lista_proximo(celula_t *c);

celula_t *lista_anterior(celula_t *c);

int lista_eh_cabeca(lista_t *l, celula_t *c);

int lista_eh_cauda(lista_t *l, celula_t *c);

#endif
