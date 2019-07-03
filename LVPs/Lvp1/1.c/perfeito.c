#include "perfeito.h"

int numero_perfeito(int np){
    
    int sum=0,i;

        for(i=1;i<np;i++){
            if(np%i==0){
                sum+=i;
            }
        }
        
    if(np==sum)
        return(1);
    else
        return(0);
}
    
    
    
void encontra_perfeito(int min,int max,char *vp){
    int np;
    char aux[10000]="\0";
    
            for(np=min;np<=max;np++){
                if(numero_perfeito(np)){
                    
                        if(aux[0]=='\0'){
                         sprintf(aux,"%d",np);
                         }else{
                         sprintf(aux,"%s,%d",aux,np);
                        }
            
                }
            }
    strcpy(vp,aux);
}
