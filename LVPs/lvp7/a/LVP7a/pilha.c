#include "pilha_privado.h"

// Coloque aqui a implementacao das funcoes do TDA pilha generico
pilha_t *pilha_cria(int cap, int tam_elemento, void (*imp)(const void *)){
    if((cap < 0) || (tam_elemento <= 0)){// C.E.
    return(NULL);
    }
    pilha_t (*p) = (pilha_t*)malloc(sizeof(pilha_t));
    if( p == NULL){ //C.E.
        return(NULL);
    }
    (p->elementos) =  (pilha_t*)malloc((cap)*(tam_elemento));
    if( (p->elementos) ==NULL){ //C.E.
        free(p);
        return(NULL);
    }
            (p->imprime) = imp; //inicializacao do ponteiro
            (p->capacidade) = cap;
            (p->tamanho_elemento) = tam_elemento;
            (p->topo) = 0;
            return(p);
}
void pilha_destroi(pilha_t **p){
    if(p != NULL && *p != NULL){
        free((*p)->elementos);
        free(*p);
        *p = NULL;
    }else{
        return;
    }
}
int pilha_vazia(pilha_t *p){
    if(p==NULL){        //C.E.
        return (-1);
        }
      if(pilha_tamanho(p)==0){
            return (1);
}else{	 	  	  		  	    	   		  	       	 	
    return(0);
}
}
int pilha_cheia(pilha_t *p){
    if(p==NULL){
       return(-1);
    }
    if(pilha_tamanho(p) == p->capacidade){
            return (1);
         }else{
            return (0);
        }
}
int pilha_tamanho(pilha_t *p){
    if( p == NULL){
        return (-1);
    }
     return(p->topo);
}
int pilha_empilha(pilha_t *p, void *elem){
   if(p!=NULL && elem!=NULL && p->topo<= (p->capacidade)-1){
    char *apoio = (char*)(p->elementos);
        memcpy(apoio+(p->topo)*(p->tamanho_elemento),elem,(p->tamanho_elemento));
        p->topo+=1;
        return(1);
    }else{
    return(0);
    }
}
int pilha_desempilha(pilha_t *p, void *elem){
    if(p!=NULL && elem!=NULL && p->topo>=1){
		char *apoio=(char*)(p->elementos);
		memcpy(elem,apoio+((p->topo)-1)*(p->tamanho_elemento),(p->tamanho_elemento));
		p->topo-=1;
		return(1);
    }else{	 	  	  		  	    	   		  	       	 	
		return(0);
    }
}
int pilha_topo(pilha_t *p, void *elem){
    if(p!=NULL && elem!=NULL&& p->topo >=1){
    char *apoio=(char*)(p->elementos);
		memcpy(elem,apoio+((p->topo)-1)*(p->tamanho_elemento),(p->tamanho_elemento));
		return(1);
    }else{
   return(0);
    }
}
void pilha_imprime(pilha_t *p){
    if(p==NULL){
        return;
    }
    if(p->imprime==NULL){
        return;
    }
    if(pilha_vazia(p) == 1){
        return;
    }
    int i;
    pilha_t *pilha_aux = pilha_cria(p->capacidade,p->tamanho_elemento,NULL);
    void *x=malloc(p->tamanho_elemento);
    for(i=p->topo;i>=1;i--){
        pilha_desempilha(p,x);
        (*p->imprime)(x); //invocacao da função imprime
        pilha_empilha(pilha_aux,x);
    }
    for(i=pilha_aux->topo;i>=1;i--){
        pilha_desempilha(pilha_aux,x);
        pilha_empilha(p,x);
    }
free(x);
pilha_destroi(&pilha_aux);
}	 	  	  		  	    	   		  	       	 	
