#include "numero_grande_privado.h"

//Colocar aqui implementacao do TDA numero grande
numero_grande_t *numero_cria(void (*libera)(void *)){
    numero_grande_t *n = lista_cria(NULL,libera,NULL);
    if(n==NULL)return(NULL);
}
void numero_destroi(numero_grande_t **n){

}
numero_grande_t *numero_lista(numero_grande_t *n){
}
bool numero_sinal(numero_grande_t *n){

}
void numero_muda_sinal(numero_grande_t *n, bool s){

}
int numero_insere_digito(numero_grande_t *n, char *digito){

}
numero_grande_t *numero_soma(numero_grande_t *n1, numero_grande_t *n2){

}
numero_grande_t *numero_multiplica(numero_grande_t *n1, numero_grande_t *n2){

}
numero_grande_t *numero_divide(numero_grande_t *n1, numero_grande_t *n2){

}
