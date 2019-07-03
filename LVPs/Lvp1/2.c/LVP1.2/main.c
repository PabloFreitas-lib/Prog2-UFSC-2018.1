//Aqui vai a solução para o laboratório
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int qtd_msg,i,TAM;
  char ordem[25],codigo_msg[50];
  //Input
  scanf("%d",&qtd_msg);
  printf("Numero de mensagens T:%d\n",qtd_msg);
  for(i=0;i<qtd_msg;i++){
    scanf("%s",&ordem[0]);
    scanf("%s",&codigo_msg[0]);
    int aux = atoi(codigo_msg);
    TAM = strlen(codigo_msg);
    // for i+=2;
    //Output
    //printf("Ordem de atribuicao de letras em numeros:%s\n",ordem);
    //printf("Mensagem codificada:%s\n",codigo_msg[0]);
  }

return(0);
}
