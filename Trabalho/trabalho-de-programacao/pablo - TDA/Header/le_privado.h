#ifndef LE_PRIVADO_H
#define LE_PRIVADO_H

#include "../Header/lista_interface.h"
#include "../Header/le_interface.h"
#include "../Header/operacoes_interface.h"

struct sasa{
    float vel;
    int segundos;
    int minutos;
    int horas;
    int round;
    int id;
};

struct aba{
    int hora1;
    int minuto1;
    int segundo1;
    int hora2;
    int minuto2;
    int segundo2;
    int hora3;
    int minuto3;
    int segundo3;
    int hora4;
    int minuto4;
    int segundo4;
};


int periodo(informacao_jogadores *,horario*);

lista_t* trata_dados(lista_t *,horario*define,int);

int numero_jogadores(lista_t *);

informacao_jogadores *seleciona_dados(char *);

#endif
