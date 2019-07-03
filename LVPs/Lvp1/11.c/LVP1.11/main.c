#include "zeros.h"
#include "fatorial.h"
int main(void){
    int n;
    scanf("%u",&n);
    printf("%llu\n",fatorial(n));
    return(0);
}
unsigned long long int fatorial(unsigned int n){
    unsigned long long int sum=1;
    int i=1;
    while (i <= n) {
    sum = sum * i;
    i++;                   
  }
    return(sum);
}
//#include "zeros.h"
int numero_zeros(unsigned long long n){
    if(n>=1 && n<=4)
        return(0);
    if(n>4&&n<9)
        return(1);
    if(n>9&&n<15)
        return(2);
    if(n>14&&n<20)
        return(3);
    if(n>20)
        return(4);
}
