#include "digitos.h"

int verifica_ultimos_digitos(int a,int b){
    char sA[30],sB[30];

  sprintf(sA,"%d",a);sprintf(sB,"%d",b);

        if(strstr(sA,sB)==NULL){
                return(0);
        }else{
                return(1);
        }

}
int verifica_segmento(int a,int b){
    char sA[30],sB[30];
    sprintf(sA,"%d",a);sprintf(sB,"%d",b);
if(a>=b){
    if(strstr(sA,sB)==NULL){
        return(0);
    }else{
        return(1);
    }
    }
    
if(b>=a)
    if(strstr(sB,sA)==NULL){
        return(0);
    }else{
        return(1);
    }    
       
}


            
