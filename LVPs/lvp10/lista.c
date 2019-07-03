/*
 * lista.c
 *
 *  Created on: Jun 23, 2018
 *      Author: John
 */
#include "lista_privado.h"

typedef struct lista lista_t;

//define o tipo celula_t
typedef struct celula celula_t;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lista_t *lista_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *)){
    lista_t *l = (lista_t*)malloc(sizeof(lista_t));
    if(l==NULL)return(NULL);
    l->cabeca = NULL;
	l->cauda = NULL;
	l->tamanho = 0;
	l->destruir = libera;
	l->imprime = imp;
	l->compara = comparar;
    return(l);
}

//  Para uma lista onde os dados nao devem ser liberados, libera deve ser NULL (was ist das?)
void lista_destroi(lista_t **l){
      if(l!=NULL){
        void *aux;
        while(lista_vazia(*l)!=1){
            lista_remove(*l,(*l)->cabeca,&aux);
               if((*l)->destruir)
                 (*l)->destruir(aux);
          }	 	  	  		  	    	   		  	       	 	
        free(*l);
         *l=NULL;
     }
}

int lista_vazia(lista_t *l){
    if(l!=NULL){
        if(l->tamanho==0){
            return(1);
        }else{
            return(0);
        }
    }
    return(-1);
}

int lista_tamanho(lista_t *l){
    if(l!=NULL){
        return(l->tamanho);
    }else{
        return(-1);
    }
}

celula_t *lista_cabeca(lista_t *l){
    if(l!=NULL)return(l->cabeca);
    return(NULL);
}

celula_t *lista_cauda(lista_t *l){
    if(l!=NULL)return(l->cauda);
    return(NULL);
}

void *lista_dado(celula_t *c){
    if(c!=NULL)return(c->dado);
    return(NULL);
}	 	  	  		  	    	   		  	       	 	


celula_t *lista_proximo(celula_t *c){
    if(c!=NULL)return(c->prox);
    return(NULL);
}


celula_t *lista_anterior(celula_t *c){
    if(c!=NULL)return(c->ant);
    return(NULL);
}

int lista_eh_cabeca(lista_t *l, celula_t *c){
    if(l!=NULL && c!=NULL){
        if(l->cabeca==c)return(1);
    }
    return(0);
}

int lista_eh_cauda(lista_t *l, celula_t *c){
    if(l!=NULL && c!=NULL){
        if(l->cauda==c)return(1);
    }
    return(0);
}


int lista_insere_proximo(lista_t *l, celula_t *c, const void *elem){
    if(l!=NULL && elem!=NULL){
        celula_t *aux=(celula_t*)malloc(sizeof(celula_t));

        aux->dado = (void*)elem;
        if(lista_vazia(l)){
            l->cabeca=aux;
            l->cauda=aux;
            l->cabeca->ant=NULL;
            l->cabeca->prox=NULL;
            l->tamanho++;
            return(1);
        }else if(c==NULL){	 	  	  		  	    	   		  	       	 	
            // inserir na cabeca
        aux->prox=l->cabeca;
        l->cabeca->ant= aux;
        aux->ant=NULL;
        l->cabeca=aux;
        l->tamanho++;
        return(1);
        }else if(c==l->cauda){
            // logo depois da cauda
            aux->prox = NULL; // como vai ser o ultimo entao o prox  null
            l->cauda->prox=aux;
            aux->ant=l->cauda;
            l->cauda=aux;
            l->tamanho++;
            return(1);
        }else{
        // logo depois da cabeca ou meio
            aux->prox = c->prox;//-->
            c->prox->ant = aux; // <--
            aux->ant=c; // <--
            c->prox=aux; // -->
            l->tamanho++;
            return(1);
        }
    return(0);
    }
    return 0;
}

int lista_insere_anterior(lista_t *l, celula_t *c, const void *elem){
if(l!=NULL && elem!=NULL){
        celula_t *aux=(celula_t*)malloc(sizeof(celula_t));
        aux->dado = (void*)elem;
        if(lista_vazia(l)){
            aux->prox = NULL;
            aux->ant = NULL;
            l->cabeca = aux;
            l->cauda = aux;
            l->tamanho++;
            return(1);
        }else if(c==NULL){	 	  	  		  	    	   		  	       	 	
            // coloca na cabeca
            aux->prox=l->cabeca;
            l->cabeca->ant = aux;
            aux->ant=NULL;
            l->cabeca=aux;
            l->tamanho++;
            return(1);
        }else if(c==l->cabeca){
            // coloca na cabeca dnv
            aux->prox=l->cabeca;
            l->cabeca->ant = aux;
            aux->ant=NULL;
            l->cabeca=aux;
            l->tamanho++;
            return(1);
        }else{
            // coloca no meio
            c->ant->prox = aux;
            aux->ant=c->ant;
            aux->prox=c;
            c->ant=aux;
            l->tamanho++;
            return(1);
        }
}
    return(0);
}

int lista_insere_posicao(lista_t *l, const unsigned int posicao, const void *elem){
    if(l!=NULL && elem!=NULL){
            celula_t *aux = (celula_t*)malloc(sizeof(celula_t));
            aux->dado = (void*)elem;
            if(lista_vazia(l)){
                aux->ant = NULL;
                aux->prox=NULL;
                l->cabeca = aux;
                l->cauda = aux;
                l->tamanho++;
                return(1);
            }else if(posicao>l->tamanho){	 	  	  		  	    	   		  	       	 	
                free(aux);
                return(lista_insere_proximo(l,l->cauda,elem));
            }else if(posicao==0){// colocar na cabeca;
            free(aux);
                return(lista_insere_anterior(l,l->cabeca,elem));
            }else if(posicao==l->tamanho){
                free(aux);
               return(lista_insere_proximo(l,l->cauda,elem));
            }
            celula_t *p = l->cabeca;
            for(int i=0;i < posicao;i++)p = p->prox; // setar posicao
            free(aux);
            return(lista_insere_anterior(l,p,elem));
    }
    return(0);
}

int lista_remove(lista_t *l, celula_t *c, void **elem){
    if(l!=NULL && c!=NULL && elem!=NULL){
        if(lista_vazia(l))return(0);
        *elem = c->dado;
        celula_t *aux = l->cabeca;
        if(l->tamanho==1){
            aux=l->cabeca;
            l->cabeca=NULL;
            l->cauda=NULL;
            l->tamanho--;
            free(aux);
            return(1);
        }
        if(c==aux){ // removendo da cabeca
            l->cabeca=c->prox;
            l->cabeca->ant = NULL;
            free(aux);
            l->tamanho--;
            return(1);
        }	 	  	  		  	    	   		  	       	 	
        aux = l->cauda;
        if(aux==c){// removendo da cauda
            l->cauda = c->ant; // nova cauda
            l->cauda->prox = NULL; // sempre assim
            free(aux);
            l->tamanho--;
            return(1);
        }
        aux= c;
        c->prox->ant = aux->ant;// <--
        c->ant->prox= aux->prox; // -->
        free(aux);
        l->tamanho--;
        return(1);
    }
    return(0);
}

void lista_imprime(lista_t *l){
 if(l==NULL || l->imprime==NULL)return;
        if( lista_vazia(l))return;
            celula_t * aux = l->cabeca;
       while(aux!=NULL){
           (l->imprime)(aux->dado);
           aux=aux->prox;
       }
}
int lista_insere_ordenado(lista_t *l, const void *elem){
 if(l!=NULL && elem!=NULL){
        celula_t *aux = (celula_t*)malloc(sizeof(celula_t));
        aux->dado=(void*)elem;
        celula_t *sup = l->cabeca;
        if(lista_vazia(l)){ // primeiro elemento colocado da lista
            aux->prox=NULL;
            aux->ant=NULL;
            l->cabeca=aux;
            l->cauda=aux;
            l->tamanho++;
            return(1);
        }else if(!(l->compara)){ // coloca na cauda
        free(aux);
                return(lista_insere_proximo(l,l->cauda,elem));
         }else if((l->compara)(elem,sup->dado)==-1){ // coloca cabeca
             free(aux);
                return(lista_insere_anterior(l,l->cabeca,elem));
        }else{	 	  	  		  	    	   		  	       	 	
         while(sup->prox!=NULL){
            if((l->compara)(sup->prox->dado,elem)==1 || (l->compara)(elem,sup->prox->dado)==0){
                free(aux);
            return(lista_insere_proximo(l,sup,elem));
            }else if((l->compara)(elem,sup->prox->dado)==1)sup=sup->prox;
         }
         free(aux);
                return(lista_insere_proximo(l,l->cauda,elem));
        }
}
return(0);
}

celula_t *lista_busca_recursiva(lista_t *l, const void *elem, celula_t *c){
    if(l!=NULL && elem!=NULL && c!=NULL){
    if(lista_vazia(l))return(NULL);
        if(c->dado!=elem){
            return(lista_busca_recursiva(l,elem,c->prox));
        }else{
        return(c);
    }
    }
    return(NULL);
}

lista_t *lista_separa(lista_t *l, const void *elem){
    if(l!=NULL && elem!=NULL){
        celula_t *sup=l->cabeca;
        void *d;
        lista_t *l_zwei = lista_cria(l->imprime,l->destruir,l->compara);
        if(l_zwei==NULL)return(NULL);
        if(lista_vazia(l) || l->tamanho==1){
        return(NULL);
        }
        int ctd=0,tam=l->tamanho;
        while(sup->dado!=elem){	 	  	  		  	    	   		  	       	 	
            sup=sup->prox;
            ctd++;
        }
        if(ctd==l->tamanho)return(NULL);
        for(int i=1 ;i< tam-ctd;i++){
        lista_remove(l,sup->prox,&d);
        lista_insere_posicao(l_zwei,i,d);
        }
        return(l_zwei);
    }
    return(NULL);
}

lista_t *lista_concatena_e_destroi(lista_t **l1, lista_t **l2){
    if(*l1==NULL || *l2==NULL || l1==NULL || l2==NULL)return(NULL);
    if(lista_vazia(*l1) && lista_vazia(*l2)){
        lista_t *lf = lista_cria(NULL,NULL,NULL);
        lista_destroi(l1);
        lista_destroi(l2);
        return(lf);
    }
    if(lista_vazia(*l1)){
        lista_t *lf = lista_cria((*l2)->imprime,(*l2)->destruir,(*l2)->compara);
        if(lf==NULL){
            lista_destroi(l1);
            lista_destroi(l2);
            return(NULL);
        }
        void *d;
        int tam_2 = lista_tamanho(*l2);
        for(int i =0;i< tam_2;i++){
        lista_remove(*l2,lista_cabeca(*l2),&d);
        lista_insere_posicao(lf,i,d);
        }
        lista_destroi(l1);
        lista_destroi(l2);
        return(lf);
    }	 	  	  		  	    	   		  	       	 	
    else if(lista_vazia(*l2)){
        lista_t *lf = lista_cria((*l1)->imprime,(*l1)->destruir,(*l1)->compara);
        if(lf==NULL){
            lista_destroi(l1);
            lista_destroi(l2);
            return(NULL);
        }
        void *d;
        int tam_1 = lista_tamanho(*l1);
        for(int i =0;i < tam_1;i++){
        lista_remove(*l1,lista_cabeca(*l1),&d);
        lista_insere_posicao(lf,i,d);
        }
        lista_destroi(l1);
        lista_destroi(l2);
        return(lf);
    }else{
        lista_t *lf = lista_cria((*l1)->imprime,(*l1)->destruir,(*l1)->compara);
        if(lf==NULL){
            lista_destroi(l1);
            lista_destroi(l2);
            return(NULL);
        }
        void *d;
        int tam_1=lista_tamanho(*l1),tam_2 = lista_tamanho(*l2);
        for(int i =0;i<tam_1;i++){
        lista_remove(*l1,lista_cabeca(*l1),&d);
        lista_insere_posicao(lf,i,d);
        }
        int aux = lista_tamanho(lf);
        for(int j =aux;j < tam_2+tam_1;j++){
        lista_remove(*l2,lista_cabeca(*l2),&d);
        lista_insere_posicao(lf,j,d);
        }
        lista_destroi(l1);
        lista_destroi(l2);
        return(lf);
    }	 	  	  		  	    	   		  	       	 	
}
// AUX

void permuta(lista_t *l,celula_t *aux_A,celula_t *aux_B){
    if(lista_vazia(l) || l->tamanho <= 1 || aux_A == NULL || aux_B == NULL)return;

    void *aux = aux_A->dado;
    aux_A->dado = aux_B->dado;
    aux_B->dado = aux;
}
