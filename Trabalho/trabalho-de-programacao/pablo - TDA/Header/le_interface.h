#ifndef LE_INTERFACE_H
#define LE_INTERFACE_H
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

lista_t* listas_listas(lista_t *, horario*);

lista_t *le_bruto(char *);

horario* definir_horario(void);

void destroi_primario(lista_t **);

void destroi_secundario(lista_t **);

informacao_jogadores* alloca_info(void);

int mostra_id(informacao_jogadores* aux);

#endif
