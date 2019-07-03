#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>
int main(void){
  float numero1=7.3,numero2;
  void *fPtr = &numero1;
printf("Valor do objeto apontado por fPtr = %f\n",*((float*)fPtr));
numero2= *((float*)fPtr);
printf("Valor de numero2 = %f\n",(float)numero2);
printf("Enderco de numero1 = %p\n",&numero1);
printf("Endereco armazenado em fPtr = %p\n",fPtr);
return(0);
}
