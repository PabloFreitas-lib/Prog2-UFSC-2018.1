#include "digitos.h"

int verifica_ultimos_digitos(int a,int b){
    
    int p=1000000000;

    while(p>b){
        if(a>=p){
            
            if(a==b)
                return(1);
            
            if(a%p==b){
                return(1);
            }else{
                return(0);
            }
            
        }
    p=p/10;
    }
}
int verifica_segmento(int a,int b){
       int  p=1000000000;
    unsigned int ca=9,cb=9;
   
        while(p>a){
            ca--;
            p=p/10;
        }
    
    p=1000000000;
  
        while(p>b){
            cb--;
            p=p/10;
        }
    
            if(ca==cb)
                return(0);
            if (ca>cb)
                return(1);
            if(cb>ca)
                return(1);
       
}

