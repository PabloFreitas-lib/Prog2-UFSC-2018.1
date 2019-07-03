#include "zeros.h"
int numero_zeros(unsigned long long n){
    if(n==0)
        return(0);
    if(n>=1 && n<=4)
        return(0);
    if(n>4&&n<10)
        return(1);
    if(n>9&&n<15)
        return(2);
    if(n>14&&n<20)
        return(3);
    if(n>20)
        return(4);
}
