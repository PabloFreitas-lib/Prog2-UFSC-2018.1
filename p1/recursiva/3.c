#include<stdio.h>
int somatorio(int,int,int);
int main(void){
  printf("%d\n",somatorio(5,1,0));
  return(0);
}
int somatorio(int a,int i,int total){
  if(i==a){
    return(total);
  }
  total= a+(a-i);
  return(somatorio(a+(a-i),i+1,total));
}
