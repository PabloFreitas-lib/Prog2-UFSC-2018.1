#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>
int main(void){
int *vet1 = (int*)malloc(sizeof(int)*10);
double *vet2 = (double*)malloc(sizeof(double)*10);
void *ptr1 = vet1;

printf("%p\n",(int*)(ptr1+3*sizeof(int)));
void *ptr2=vet2;
printf("%lf",*((double*)(ptr2+3*sizeof(double))));
return(0);
}
