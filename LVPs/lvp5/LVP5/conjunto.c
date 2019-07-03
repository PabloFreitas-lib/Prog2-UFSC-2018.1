#include "conjunto_privado.h"

conjunto_t *conjunto_cria(void){
    conjunto_t *V =(conjunto_t*) calloc(1,sizeof(conjunto_t));
	if(V==NULL){
	    free(V);
	    return (NULL);
	}
	V->vetor=(elem_t*)calloc(10,sizeof(elem_t));
	if(V->vetor == NULL){
	    free(V->vetor);
	    free(V);
	    return NULL;
	}
	V->capacidade=10;
	V->numero=0;
	return (V);
}

void conjunto_destroi(conjunto_t **a){
	if(a != NULL) {
	    free( (*a)->vetor);
		free(*a);
		*a = NULL;
    }
}

int conjunto_numero_elementos(conjunto_t *a){
    if(a==NULL)
    return 0;
    int size = a->numero;
   return (size);
}
void conjunto_inicializa_vazio(conjunto_t *a){
    if(a==NULL)
    return;
    int size= a->numero;
    for(int i=0;i<size;i++){
        a->vetor[i]=0;
    }
    a->numero=0;
}
void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a==NULL || b==NULL || c==NULL)
    return;
    int i,x;
    conjunto_inicializa_vazio(c);
    conjunto_diferenca(a,b,c);
    for(i=0;i<b->numero;i++){
        x = b->vetor[i];
        conjunto_insere_elemento(x,c);
    }
}
void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a==NULL || b==NULL || c==NULL)
    return;
    conjunto_inicializa_vazio(c);
    int size = a->numero,i,x=0;

    for(i=0;i<size;i++){
        x = a->vetor[i];
            if(conjunto_membro(x,b)){
                conjunto_insere_elemento(x,c);
             }
    }
}
void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(a==NULL || b==NULL || c==NULL)
    return;
    conjunto_inicializa_vazio(c);
    int x=0,i;
    for(i=0;i<a->numero;i++){
        x = a->vetor[i];
            if(!(conjunto_membro(x,b))){
             conjunto_insere_elemento(x,c);
             }
    }
}
int conjunto_membro(elem_t x, conjunto_t *a){
    if(a==NULL)
    return 0;
    int size=a->numero;
    for(int i=0;i<size;i++){
        if(a->vetor[i]==x)
        return 1;
    }
    return 0;
}
int conjunto_insere_elemento(elem_t x, conjunto_t *a){
    if(a==NULL)
    return 0;
    if(conjunto_membro(x, a)==1)
    return(1);
    if(a->numero==a->capacidade){
        a->vetor = (elem_t*)realloc(a->vetor, ((a->capacidade)+1)*sizeof(elem_t));
        a->capacidade++;
    }
    a->vetor[(a->numero)] = x ;
    a->numero++;
    return 1;
}
void conjunto_remove_elemento(elem_t x, conjunto_t *a){
    if(a==NULL)
    return;
    if(conjunto_membro(x, a)==0)
        return;
    elem_t aux;
    for(int i=0;i<a->numero;i++){
    if(a->vetor[i]== x){
        aux=a->vetor[a->numero-1];
        a->vetor[a->numero-1]=0;
        a->vetor[i]=aux;
        a->numero-=1;
    }
    }
}
void conjunto_atribui(conjunto_t *a, conjunto_t *b){
    if(a==NULL || b==NULL)
    return;
    int size = a->numero;
    conjunto_inicializa_vazio(b);
    for(int i=0;i < size;i++){
        conjunto_insere_elemento(a->vetor[i],b);
    }
        return;
}
int conjunto_igual(conjunto_t *a, conjunto_t *b){
    if(a==NULL || b==NULL)
    return 0;
    int sizeA=a->numero,sizeB=b->numero;
    if(sizeA!=sizeB){
        return(0);
    }
    for(int i=0;i<sizeA;i++){
        if(a->vetor[i]!=b->vetor[i])
        return 0;
    }
    return 1;
}
elem_t conjunto_minimo(conjunto_t *a){
    if(a==NULL)
         return ELEM_MAX;
    int size= a->numero,c,i=0;
    c= a->vetor[i];
        for(i=1;i<size;i++){
           if(c>a->vetor[i])
           c=a->vetor[i];
           }
           return(c);
    }
elem_t conjunto_maximo(conjunto_t *a){
        if(a==NULL)
         return ELEM_MIN;
    int size = a->numero,c,i=0;
    c= a->vetor[i];
        for(i=1;i<size;i++){
           if(c<a->vetor[i])
           c=a->vetor[i];
           }
           return(c);
    }

void conjunto_imprime(conjunto_t *a){
if(a!=NULL){
  for(int i=0;i<a->numero;i++){
    printf("%d",a->vetor[i])
  }
}
}
