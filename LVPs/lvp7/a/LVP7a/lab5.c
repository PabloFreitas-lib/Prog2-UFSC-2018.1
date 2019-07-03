#include "lab5.h"

void estacionamento(const char *arquivo, void (*entrada)(carro_t *), void (*saida)(carro_t *)){
    if(arquivo==NULL){
        return;
}
FILE *arq = fopen(arquivo,"r");
carro_t *tesla;
tesla = (carro_t*)malloc(sizeof(carro_t));
pilha_t *principal = pilha_cria(10,sizeof(carro_t),NULL);
pilha_t *aux = pilha_cria(10,sizeof(carro_t),NULL);
char keyboard[4]="\0", aux_placa[8]="\0";
  fscanf(arq,"%s %s",keyboard,aux_placa);
  strcpy(tesla->placa,aux_placa);
         while(strcmp(keyboard,"FIM")!=0){
             if(keyboard[0]=='E'){
                    tesla->manobras=0;
                    entrada(tesla);
                if(pilha_cheia(principal)){
                     saida(tesla);
                }
            pilha_empilha(principal,tesla);
            }else if(keyboard[0]=='S'){
                    if(pilha_vazia(principal)){
                        break;
                    }
                pilha_desempilha(principal,tesla);
                    if(strcmp(tesla->placa,aux_placa)==0){
                        break;
                    }else{
                        tesla->manobras++;
                        pilha_empilha(aux,tesla);
                    }
                        while(strcmp(tesla->placa,aux_placa)!=0){
                            pilha_desempilha(principal,tesla);
                                if(strcmp(tesla->placa,aux_placa)==0){
                                    break;
                                }else{	 	  	  		  	    	   		  	       	 	
                                    tesla->manobras++;
                                    pilha_empilha(aux,tesla);
                                }
                        }
            }
            strcpy(keyboard, "\0");
            strcpy(aux_placa, "\0");
            fscanf(arq,"%s %s",keyboard, aux_placa);
            strcpy(tesla->placa,aux_placa);
        }
fclose(arq);
pilha_destroi(&principal);
pilha_destroi(&aux);
free(tesla);
}