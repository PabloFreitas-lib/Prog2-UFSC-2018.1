#ifndef OPERACOES_INTERFACE_H
#define OPERACOES_INTERFACE_H


typedef struct lista lista_t;
typedef struct celula celula_t;
typedef struct baba estrutura;
typedef struct sasa informacao_jogadores;
typedef struct aba horario;


estrutura* alloca_estrutura(void);

int mostra_horas(estrutura*aux);

int mostra_minutos(estrutura*aux);

int mostra_segundos(estrutura*aux);

int run_forest_run(celula_t *, int);

float velo_media(celula_t *);

float velo_media_round(celula_t *,int);

float velo_maxima(celula_t *);

float distancia(celula_t *);

estrutura * tempo_efetivo(celula_t *,int);

estrutura* tempo_efetivo_total(celula_t *);

#endif
