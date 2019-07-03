/*
 * ordencao.c
 *
 *  Created on: Jun 26, 2018
 *      Author: John
 */

#include "ordenacao_privado.h"

//coloque a implementacao de quicksort e bolha aqui

int quicksort(void *vetor, unsigned int tamanho, unsigned int tamanho_elemento, unsigned int inicio, unsigned int fim, int (*comparar)(const void *a, const void *b)){
         if (vetor==NULL || comparar==NULL )return(0);

          int key;

          if (fim > inicio){
            key = gen_quicksort(vetor,tamanho,tamanho_elemento,inicio,fim,comparar);

				if (key != 0){
					quicksort(vetor,tamanho,tamanho_elemento,inicio,key-1,comparar);
				}

            quicksort(vetor,tamanho,tamanho_elemento,key+1,fim,comparar);
            return(1);
          }
         // printf("Deu erro\n\n");
          return(0);
}
int bolha_lista(lista_t *l,int(*comparar)(const void *a, const void *b)){
    if (l==NULL || lista_vazia(l) || comparar==NULL)return(0);
    if (lista_tamanho(l) == 1) return(1);

    celula_t *aux_esquerda, *aux_direita, *aux;
    aux = lista_cabeca(l);

    	while(aux !=NULL){
          aux_esquerda = lista_cabeca(l); // primeiro termo da lista
          aux_direita = lista_proximo (aux_esquerda); // prox da lista
 // printf("Deu erro\n\n");

              while(aux_direita != NULL){ // para verificar se esta no fim

                   if(comparar(lista_dado(aux_esquerda), lista_dado(aux_direita)) == 1){
                     permuta(l,aux_esquerda,aux_direita);
                      // printf("Deu erro\n\n");
                   }
                   else{
                        // printf("Deu erro\n\n");
                	   aux_esquerda = aux_direita;
                       aux_direita = lista_proximo(aux_direita);
                        // printf("Deu erro\n\n");
                     }
              }

               // printf("Deu erro\n\n");
        aux=lista_proximo(aux);
    }
    return(1);
}


// aux

int gen_quicksort(void *array, unsigned int tam, unsigned int TAM, int begin, int end, int (*comparar)(const void *a, const void *b)){
       if (array==NULL || comparar==NULL) return(0);

       char *key = (char*)calloc(1,TAM);
       char *aux = (char*)calloc(1,TAM);
       int aux_esq,aux_dir;

       if (key==NULL)return(0);
       if (aux==NULL)return(0);

       aux_esq=begin;
       aux_dir=end;
       memcpy(key,(char*)array + TAM*begin, TAM); // memcpy(destino,parametro,tamanho); escolha do pivo pelo inicio

		   while(aux_esq < aux_dir){
				  while(comparar(array + TAM * aux_esq,key) <= 0){
				       // printf("Deu erro\n\n");
						 aux_esq++;
				  }
				  while(comparar(array + TAM * aux_dir,key) == 1){
				       // printf("Deu erro\n\n");
						 aux_dir--;
				  }

				  if(aux_esq < aux_dir){
				       // printf("Deu erro\n\n");
					  memcpy(aux, (char*)array + aux_esq*TAM, TAM); // memcpy(destino,parametro,tamanho);
					  memcpy((char*)array + aux_esq*TAM, (char *)array + aux_dir*TAM, TAM); // memcpy(destino,parametro,tamanho);
					  memcpy((char*)array + aux_dir* TAM, aux, TAM); // memcpy(destino,parametro,tamanho);
				  }
		   }
       memcpy((char *)array + begin*TAM, (char *)array + aux_dir* TAM, TAM);
       memcpy((char *)array + aux_dir*TAM, key, TAM);
       free(key);
       free(aux);
       return (aux_dir);
}
