/*
 * main.c
 *
 *  Created on: Jun 23, 2018
 *      Author: John
 */

#include "lista_privado.h"
#include "pilha_privado.h"

int main(void){
	void *aux;
	void *numero = (int*)malloc(sizeof(int*));
    int tamanho;
    lista_t *l = lista_cria(NULL,NULL,NULL);
    if(l==NULL)printf("Não possui memoria para criar a lista\n\n");
    scanf("%d",&tamanho);
    for(int i=0;i<tamanho;i++)lista_insere_proximo(l,l->cabeca,pilha_cria(tamanho));
    celula_t *walk = l->cabeca;
    for(int j = 0;j<tamanho;j++){
    	if(walk!=NULL){
    	numero = *(int*)j;
    	pilha_empilha(lista_dado(walk),numero);
    	walk = walk->prox;
    	}
    }
//-------------------------------------------------------------------------------
  int a,b;
  char name_A[8],name_B[8],aux_A[5],aux_B[5];

  strcpy(name_A,"");
  strcpy(aux_A,"");
  strcpy(name_B,"");
  strcpy(aux_B,"");

  scanf("%s",name_A);// ex: mova
  scanf("%s",aux_A); // 9
  scanf("%s",name_B); // sobre
  scanf("%s",aux_B); // 8

  if(strcmp(name_A,"sair")==0){
    lista_imprime(l);
    return(0);
  }
  a = atoi(aux_A);
  b = atoi(aux_B);
  celula_t *a_set = l->cabeca;
  celula_t *b_set = l->cabeca;

  if(strcmp(name_A,"mova")==0 && strcmp(name_B,"sobre")==0){
	  organiza_lista(l,a,b);
	  for(int i =0 ; i < a; i++)a_set=a_set->prox;
	  for(int i =0 ; i < b; i++)b_set=b_set->prox;
	  lista_remove(l,a_set,&aux);
	  pilha_empilha(b_set->dado,aux);
  }
  if(strcmp(name_A,"mova")==0 && strcmp(name_B,"topo")==0){
	  organiza_lista(l,a,-1);
	  for(int i =0 ; i < a; i++)a_set=a_set->prox;
	  for(int i =0 ; i < b; i++)b_set=b_set->prox;
	  lista_remove(l,a_set,&aux);
	  pilha_empilha(b_set->dado,aux);
  }
  if(strcmp(name_A,"empilhe")==0 && strcmp(name_B,"sobre")==0){
	  organiza_lista(l,-1,b);
	  for(int i =0 ; i < a; i++)a_set=a_set->prox;
	  for(int i =0 ; i < b; i++)b_set=b_set->prox;
	  lista_remove(l,a_set,&aux);
	  pilha_empilha(b_set->dado,aux);
  }
  if(strcmp(name_A,"empilhe")==0 && strcmp(name_B,"topo")==0){
	  for(int i =0 ; i < a; i++)a_set=a_set->prox;
	  for(int i =0 ; i < b; i++)b_set=b_set->prox;
	  lista_remove(l,a_set,&aux);
	  pilha_empilha(b_set->dado,aux);
  }
  while(strcmp(name_A,"sair")!=0){
	  	strcpy(name_A,"");
	    strcpy(aux_A,"");
	    strcpy(name_B,"");
	    strcpy(aux_B,"");

	    scanf("%s",name_A);// ex: mova
	    scanf("%s",aux_A); // 9
	    scanf("%s",name_B); // sobre
	    scanf("%s",aux_B); // 8

	    if(strcmp(name_A,"sair")==0){
	      printf("Sair\n");
	      //Encerra a execução do programa e mostra o estado das pilhas de containers.
	      return(0);
	    }
	    a = atoi(aux_A);
	    b = atoi(aux_B);
	    celula_t *a_set = l->cabeca;
	    celula_t *b_set = l->cabeca;
	    // parametros necessarios eh as posicoes e a lista

	    if(strcmp(name_A,"mova")==0 && strcmp(name_B,"sobre")==0){
	  	  organiza_lista(l,a,b);
	  	  for(int i =0 ; i < a; i++)a_set=a_set->prox;
	  	  for(int i =0 ; i < b; i++)b_set=b_set->prox;
	  	  lista_remove(l,a_set,&aux);
	  	  pilha_empilha(b_set->dado,aux);
	    }
	    if(strcmp(name_A,"mova")==0 && strcmp(name_B,"topo")==0){
	  	  organiza_lista(l,a,-1);
	  	  for(int i =0 ; i < a; i++)a_set=a_set->prox;
	  	  for(int i =0 ; i < b; i++)b_set=b_set->prox;
	  	  lista_remove(l,a_set,&aux);
	  	  pilha_empilha(b_set->dado,aux);
	    }
	    if(strcmp(name_A,"empilhe")==0 && strcmp(name_B,"sobre")==0){
	  	  organiza_lista(l,-1,b);
	  	  for(int i =0 ; i < a; i++)a_set=a_set->prox;
	  	  for(int i =0 ; i < b; i++)b_set=b_set->prox;
	  	  lista_remove(l,a_set,&aux);
	  	  pilha_empilha(b_set->dado,aux);
	    }
	    if(strcmp(name_A,"empilhe")==0 && strcmp(name_B,"topo")==0){
	  	  for(int i =0 ; i < a; i++)a_set=a_set->prox;
	  	  for(int i =0 ; i < b; i++)b_set=b_set->prox;
	  	  lista_remove(l,a_set,&aux);
	  	  pilha_empilha(b_set->dado,aux);
	    }
  }
}
