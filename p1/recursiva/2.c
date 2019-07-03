#include<stdio.h>
#include<stdlib.h>
#include <string.h>
float inversao(float *,int);
int main(void){
  int i;
  float vet[100];
  for(i =1;i<=100;i++){
    vet[i]=i;
  }
  i=100;
  inversao(vet,i);
}
float inversao(float *vet,int j){
  if(j==1){
printf("%.0f",vet[j]);
return(0);
}else{
  printf("%.0f ",vet[j]);
  return(inversao(vet,j-1));
}
}
