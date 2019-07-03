#include<stdio.h>
int numero;
int aux;
int invert(int n){
    if(n==0){
      return n;
    }else{
     printf("%d", n % 10);
     n/=10;
     return invert(n);
    }
return 0;
 }
int main(void){
   printf("Digite um numero:");
   scanf("%d",&numero);
   invert(numero);
   return 0;
}
