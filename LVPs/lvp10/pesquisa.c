/*
 * pesquisa.c
 *
 *  Created on: Jun 26, 2018
 *      Author: John
 */
#include "pesquisa_privado.h"
//coloque a implementacao da funcao pesquisa_binaria aqui
int pesquisa_binaria(void *vetor, void *dado, int tamanho, int tamanho_elemento, int (*comparar) (const void *a, const void *b)){
    if ((vetor==NULL) || (dado==NULL) || (comparar==NULL))return(-1);

    char *array= (char*)vetor;
    int begin = 0,end = tamanho -1,ponto_medio = 0;

    while (begin <= end){
        ponto_medio = (begin+end)/2;
        if(comparar((char*)vetor + ponto_medio *
        ,dado)==0){
        	return (ponto_medio);
        }
        else if (comparar((char*)vetor + ponto_medio * tamanho_elemento, dado) == -1){
        	begin = ponto_medio+1;
        }
        else{
        	end = ponto_medio-1;
        }
    }
   // printf("deu Erro na pesquisa Binaria\n\n\n");
    return(-1);
}
