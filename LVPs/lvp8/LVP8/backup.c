#include "fila_privado.h"
//coloque aqui a implementacao das operacoes do TDA fila generico
fila_t *fila_cria(void (*imp)(const void *), void (*libera)(void *), int (*comparar)(const void *, const void *)){
    fila_t *f =(fila_t*)malloc(sizeof(fila_t));
    if(f==NULL){
        free(f);
        return(NULL);
    }
    f->cabeca=NULL;
    f->cauda=NULL;
    f->destruir=libera;
    f->imprime=imp;
    f->compara=comparar;
    f->tamanho = 0;
    return(f);
}

void fila_destroi(fila_t **f){
    if(*f!=NULL){
        void *aux;
        while(fila_vazia(*f)!=1){
            fila_desenfileira(*f,&aux);
            if((*f)->destruir)
                (*f)->destruir(aux);
        }
        free(*f);
        *f=NULL;
    }
}

int fila_vazia(fila_t *f){
    if(f==NULL){
        return(-1);
    }
    if(f->cabeca==NULL){ // f->tamanho == 0
        return(1);
    }
    return(0);
}

int fila_tamanho(fila_t *f){
    if(f==NULL)
        return(-1);
    return(f->tamanho);
}

int fila_enfileira(fila_t *f, void *elem){
    if(f!=NULL && elem !=NULL){
       celula_t *aux = (celula_t*)malloc(sizeof(celula_t));
         if(aux==NULL)
            return(0);
    aux->dado = elem; // copiar os dados para o auxiliar
    aux->prox = NULL; //  cauda NULL
        if(fila_vazia(f)){     // Se o final é igual ao comeco entao a fila esta vazia
            f->cabeca = aux;
             f->cauda = aux;
             f->tamanho++;
            return(1);
        }
        else{
            f->cauda->prox = aux;
            f->cauda = aux;
            f->tamanho++;
            return(1);
        }
    }
    return(0);
}

int fila_enfileira_ordenado(fila_t *f, void *elem){
    if(f!=NULL && elem !=NULL){
        celula_t *aux=f->cabeca;
        celula_t *keep_elem=(celula_t*)malloc(sizeof(celula_t));
        keep_elem->dado = elem;
        if(fila_vazia(f)){  // enfileirar sendo que cauda e cabeca devem ser iguais
            keep_elem->prox = NULL;
            f->cabeca=keep_elem;
            f->cauda=keep_elem;
             f->tamanho++;
            return(1);
        }
        if(!f->compara){// enfileirar na cauda normalmente
            keep_elem->prox = NULL;
            f->cauda->prox = keep_elem;
            f->cauda = keep_elem;
            f->tamanho++;
            return(1);
        }
        if((f->compara)(elem,aux->dado)==-1){ // elem < aux->dado
            keep_elem->prox=f->cabeca; // nova cabeca
            f->cabeca =keep_elem; // ligando nova cabeca com a antiga
            f->tamanho++;
            return(1);
        }
        while(aux->prox!=NULL){
            if((f->compara)(aux->prox->dado,elem)==1 || (f->compara)(elem,aux->dado)==0){// elem < f->cabeca->dado
                // elem deve ser minha nova cabeca e manter toda a ordem anterior
                keep_elem->prox=aux->prox; // 3 apontando para o 4 fila : 1 2 4 5 elem 3
                aux->prox= keep_elem; // 2 apontado para o 3
                f->tamanho++;
                return(1);
            }
            if((f->compara)(elem,aux->prox->dado)==1){
                aux=aux->prox;
            }
        }
            keep_elem->prox = NULL;
            f->cauda->prox = keep_elem;
            f->cauda = keep_elem;
            f->tamanho++;
            return(1);
    }
     return(0);
}

int fila_desenfileira(fila_t *f, void **elem){
    if(f==NULL && *elem ==NULL){
        return(0);
    }
    if(fila_vazia(f)){
        return(0);
    }
    celula_t *aux = f->cabeca;
    *elem = f->cabeca->dado; // retorna o primeiro da fila
    f->cabeca = f->cabeca->prox; // nova cabeca

        if(fila_vazia(f)){ // se a fila ficou vazia pos remocao
            f->cauda = NULL;
            f->tamanho=0;
            free(aux);
            return(1);
        }
    f->tamanho--;
        free(aux);
    return(1);
}

int fila_cabeca(fila_t *f, void **elem){
    if((f==NULL) || (elem==NULL)){
        return(0);
    }
    if(fila_vazia(f)){
        return(0);
    }
    *elem= f->cabeca->dado;
        return(1);
}

int fila_cauda(fila_t *f, void **elem){
    if((f==NULL) || (elem==NULL)){
        return(0);
    }
    if(fila_vazia(f)){
        return(0);
    }
   *elem = f->cauda->dado;
    return(1);
}

void fila_imprime(fila_t *f){
        if(f==NULL || f->imprime==NULL){
            return;
        }
        if( fila_vazia(f)){
            return;
        }
       celula_t * aux =f->cabeca;
       while(aux!=NULL){
           (f->imprime)(aux->dado);
           aux=aux->prox;
       }
}
