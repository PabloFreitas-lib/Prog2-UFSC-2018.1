#include "lab3.h"
/*resposta de implementacao aqui*/
double desvio(double* valores, unsigned int qtd_numeros){
  if(valores == NULL)
      return(HUGE_VAL);
      int i;
      double sum=0.0;
      for(i=0;i<qtd_numeros;i++){
          sum += pow(valores[i]- media(valores,qtd_numeros),2);
      }
       return(sqrt(som/(qtd_numeros-1)));
}
double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
  if(valores==NULL || qtd_repeticao==NULL){
  return(HUGE_VAL);
  qtd_repeticao=0;
}
int i,j,ctd_final=0,ctd=0;
double sum=0.0,sum_final=0.0,aux=0.0;
for(i=0;i<qtd_numeros;i++){
  aux=valores[i];
  sum=0.0;
  ctd=0;
  for(j=0;j<qtd_numeros;j++){
    if(aux==valores[j+1]){
      ctd++;
      sum+=aux;
    }
    if(i>=1 && ctd>aux){
      ctd_final=ctd;
      sum_final=sum;
    }
  }
}
*qtd_repeticao=ctd_final;
return(sum_final/ctd_final);
}
double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
  if(valores==NULL)
  return(HUGE_VAL);
  if(posicao<0 || posicao >=qtd_numeros)
    return(HUGE_VAL);
    return(valores[posicao]);
}
double amplitude(double* valores, unsigned int qtd_numeros){
  if(valores==NULL)
    return(HUGE_VAL);
  bouble_sort(valores,qtd_numeros);
  return(valores[qtd_numeros]-valores[0]);
}
double mediana(double* valores, unsigned int qtd_numeros){
  if(valores==NULL)
    return(HUGE_VAL);
  bouble_sort(valores,qtd_numeros);
  return(((valores[qtd_numeros/2])+(valores[(qtd_numeros/2)-1]))/2);
}
double media(double* valores, unsigned int qtd_numeros){
  if(valores==NULL)
    return(HUGE_VAL);
  double sum=0;
  for(i=0;i<n;i++){
    sum+=valores[i];
  }
  return(sum/(qtd_numeros));
}
double menor(double* valores, unsigned int qtd_numeros){
  if(valores==NULL)
    return(HUGE_VAL);
  bouble_sort(valores,qtd_numeros);
  return(valores[0]);
}
double maior(double* valores, unsigned int qtd_numeros){
  if(valores==NULL)
  return(HUGE_VAL);
  bouble_sort(valores,qtd_numeros);
  return(valores[qtd_numeros]);
}
void bouble_sort(double *valores,unsigned int qtd_numeros){
  unsigned int n=qtd_numeros;
  double c,aux;
  int i, j;
  for (i = 1; i < n; i++) {
      for (j = 0; j < n - 1; j++) {
            if (valores[j] > valores[j + 1]) {
              //swap (v[j],v[j+1])
              aux = valores[j];
              valores[j] = valores[j + 1];
              valores[j + 1] = aux;
            }
      }
    }
}
FILE *abre_arquivo(const char *arquivo){
  if(arquivo==NULL)
  return(NULL);
      FILE * pf = fopen (arquivo, "r");
      return(pf);
}
int fecha_arquivo(FILE *arq){
  if(arq!=NULL){
    fclose(pf);
    return(0);
  }
  return(1);
}
double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
  FILE *pf = abre_arquivo(arquivo);
  if(qtd_numeros==NULL || arquivo==NULL || pf==NULL){
    qtd_numeros=0;
    return(NULL);
  }
  int i=0;
  /*MALLOC*/ double *rtp = (double *) malloc(sizeof(double)*2);
  while((fscanf(pf,"%lf ",rtp[i])!=EOF) && (fscanf(pf,"%lf",rtp[i+1])!=EOF)){
        i+=2;
        /*REALLOC*/ rtp = (double *) realloc(rtp,sizeof(double)*(i+2));
  }
  *qtd_numeros=i;  //tamanho do vetor
  if(i==0){
      free(rtp);//evitar vazamento de memoria
      return(NULL);
  }
  return(rtp);
}
