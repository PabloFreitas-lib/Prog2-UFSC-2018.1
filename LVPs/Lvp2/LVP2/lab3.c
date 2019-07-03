#include "lab3.h"
double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
   if(valores == NULL)
       return(HUGE_VAL);
       if(qtd_repeticao==NULL)
       return(HUGE_VAL);

       int i,j,aux=0,contador;
       double sum,c,auz=0;

       for(i=0;i<qtd_numeros;i++){
           c=valores[i];
           sum =0.0;
           contador=0;
           for(j=0;j < qtd_numeros;j++){
               if(c == valores[j+1] ){
               contador++;
               sum+=c;
               }
               if(i>=1 && contador>aux){
               aux=contador;
               auz=sum;
               }
           }
       }
       *qtd_repeticao=aux;
       return(auz/aux);
    }


double desvio(double* valores, unsigned int qtd_numeros){
   if(valores == NULL)
       return(HUGE_VAL);
       int i;
       double som=0;
       for(i=0;i<qtd_numeros;i++){
           som += pow(valores[i]- media(valores,qtd_numeros),2);
       }
        return(sqrt(som/(qtd_numeros -1)));
}
double mediana(double* valores, unsigned int qtd_numeros){
   if(valores == NULL)
       return(HUGE_VAL);
       unsigned int n=qtd_numeros;
       double c,aux;
       int i, j;

    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
               if (valores[j] > valores[j + 1]) {
                aux          = valores[j];
                valores[j]     = valores[j + 1];
                valores[j + 1] = aux;

                }
        }
    }
    n=qtd_numeros/2;
    c=valores[n]+valores[n-1];
    return(c/2);
}
double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
   if(valores == NULL)
       return(HUGE_VAL);
       if(posicao < 0 || posicao >=qtd_numeros)
       return(HUGE_VAL);
       return(valores[posicao]);
}
double amplitude(double* valores, unsigned int qtd_numeros){
   if(valores == NULL)
       return(HUGE_VAL);
return(maior(valores,qtd_numeros) - menor(valores,qtd_numeros));
}

double media(double* valores, unsigned int qtd_numeros){
   if(valores == NULL)
       return(HUGE_VAL);
      double sum=0;
      int i=0;
       for(i=0;i<qtd_numeros;i++){
       sum+=valores[i];
       }
        return(sum/qtd_numeros);
}

double menor(double* valores, unsigned int qtd_numeros){
   if(valores == NULL)
       return(HUGE_VAL);
int i=0;
       double c;
       c=valores[i];
       for(i=0;i<qtd_numeros;i++){
        if(!(c<valores[i]))
        c=valores[i];
}
return(c);
}

double maior(double* valores, unsigned int qtd_numeros){
   if(valores == NULL)
       return(HUGE_VAL);
       int i=0;
       double c;
       c=valores[i];
       for(i=0;i<qtd_numeros;i++){
        if(!(c>valores[i]))
        c=valores[i];
}
return(c);
}
// AUXILIARES

FILE *abre_arquivo(const char *arquivo){
    if(arquivo == NULL){
        return(NULL);
    }
    FILE *arq = fopen(arquivo,"r");
    return(arq);
}

int fecha_arquivo(FILE *arq){
     if(arq != NULL){
     fclose(arq);
        return(0);
     }
        return(1);
}

double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
    if (qtd_numeros == NULL)
        return(NULL);
        if(arquivo==NULL)
        return(NULL);
    FILE *arq = abre_arquivo(arquivo);
    if(arq==NULL){
        qtd_numeros=0;
         return(NULL);
    }
        int i=0;
        double *resposta = (double*) malloc(sizeof(double)*2); //double *resposta = (double*) calloc(2,sizeof(double));
          while((fscanf(arq,"%lf ",&resposta[i]) !=EOF) && (fscanf(arq,"%lf",&resposta[i+1]) !=EOF)){
            i+=2;
            resposta = realloc(resposta,sizeof(double)*(i+2));
          }
          *qtd_numeros=i;
          if(i==0){
            free(resposta);
            return(NULL);
        }
return(resposta);
}
