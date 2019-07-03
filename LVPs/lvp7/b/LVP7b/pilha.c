
#include "pilha_privado.h"
pilha_t *pilha_cria(int cap){
    if(cap < 0){
    return(NULL);
    }
    pilha_t (*p) = (pilha_t*)calloc(1,sizeof(pilha_t));
    if( p == NULL){
        return(NULL);
    }
    (p->elementos) =  (pilha_t*)calloc(cap,sizeof(int));
    if( (p->elementos) ==NULL){
        free(p);
        return(NULL);
        }
            (p->capacidade) = cap;
            (p->tamanho_elemento) = sizeof(int);
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
    if(p==NULL){
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
    if(p==NULL){
      return (-1);
    }
     return(p->topo);
}

int pilha_empilha(pilha_t *p, void *elem){
   if((p!=NULL) && (elem!=NULL) && (p->topo <= (p->capacidade)-1)){
    char *apoio=(char*)(p->elementos);
        memcpy(apoio+(p->topo)*(p->tamanho_elemento),elem,(p->tamanho_elemento));
        p->topo+=1;
        return(1);
    }else{
        return(0);
    }
}

int pilha_desempilha(pilha_t *p, void *elem){
    if((p!=NULL) && (elem!=NULL) && (p->topo>=1)){
		char *apoio = (char*)(p->elementos);
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

}
