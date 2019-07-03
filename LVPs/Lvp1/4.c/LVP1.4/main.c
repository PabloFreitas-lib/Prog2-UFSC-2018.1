#include "lab2.h"

int main(void){
    int numero;
    scanf("%d",&numero);
    
    printf("%s",separa(numero));    
   return(0); 
}

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
    int i=10000,aux,cont=5;
    if(numero<=9){
        sprintf(lista,"%d O",numero);
        return(lista);
    }
    while(resto(numero,i)==numero){
        i=i/10;
        cont--;
    }
    while(cont!=0){
    aux=quociente(numero,i);
    sprintf(lista,"%s %d L",lista,aux);
    numero=resto(numero,i);
    if((numero<=9)&&(numero>0)){
        sprintf(lista," %d K",numero);
        return(lista);
    }
    if(quociente(numero,i)==0){
            sprintf(lista,"%s %d A",lista,quociente(numero,i));
        }
        i=i/10;
        cont--;
    }
return(lista);
    }
