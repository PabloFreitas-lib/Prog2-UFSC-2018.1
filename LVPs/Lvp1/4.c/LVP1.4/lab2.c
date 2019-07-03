#include "lab2.h"

/*coloque aqui teu código*/

int quociente(int a ,int b){
    int q;
    q=a/b;
    return(q);
}

int resto(int a ,int b){
    int r;
    r=a%b;
    return(r);
}



char *separa(int numero){
    char *lista;
    lista = (char *) malloc(10 * sizeof(char));
    int i=10000,aux,y=1;
    if(numero<=9){
        sprintf(lista,"%d",numero);
        return(lista);
    }
    while(resto(numero,i)==numero){
        i=i/10;
    }
    while(i!=1){
        if(y){
             aux=quociente(numero,i);
            sprintf(lista,"%d",aux);
        numero=resto(numero,i);
        y=0;
        i=i/10;
        }else{
    
    aux=quociente(numero,i);
    sprintf(lista,"%s %d",lista,aux);
    numero=resto(numero,i);
        }
        
    
    if(numero<=9){
        sprintf(lista,"%s %d",lista,numero);
        return(lista);
    }
        
        i=i/10;
    }
return(lista);
}
