/*
Classificacao :
--> Por comparacao:
compara os eleentos para colocalos em ordem correta. Nem todos os algoritmos sao baeanos na comparacao, para essa classe, a classificacao nao eh
mais rapida que o tempo O(n lg n)
--> Tempo-linear
Classificacao em tempo proporcional ao numeor de elemntos que estao sendo classicados , ou seja , O(n).
Depende de certas caracteristicas dos dados por isso nem semrpe eh possivel utilizala

-->Estavel X Instavel
Estavel: A ordem relativa dos registros com a mesma chave nao se altera apos a ordenacao
Instavel : Se altera a ordem relativa da ordenacao

--> Metodo Adaptavel
A sequencia de operacoes realizadas depende da entrada
(Um metodo que sempre realiza as mesmas operacoes , independe da entrada , entao ele nao eh Adaptavel)

*/
/*
 * ordenacao.c
 *
 *  Created on: Jun 26, 2018
 *      Author: John
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100
void ordena(int vet[], int size);
int main(void){
  int vetor[TAM],i;
  srand((unsigned)time(NULL));
  for(i = 0; i < TAM; i++){
    vetor[i] = rand() % 100; //gera numeros de 0 a 1000
    printf("vetor[%d] = %d \n",i,vetor[i]);
  }
    printf("\n\n\n");
  ordena(vetor, TAM);
  printf("\n\n\n");
  for(i = 0; i < TAM; i++){
   printf("vetor[%d] = %d \n",i,vetor[i]);
  }
  return(1);
}
void ordena(int vet[],int size){
	int aux,i,j;
	for (i = 1; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
               if (vet[j] > vet[j+1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j+1] = aux;
                }
        }
    }
}
/*
--> Bubblesort
Qual a melhor complexidade no tempo do bubblesort?
melhor: N
pior : Nlog

-->InsertionSort

*/
int issort(void* data, int size,int esize,int(*compare)(const void* key1,const void *key2)){
  char*a = data;
  void*key;
  int i,j;
  if(key=char*)malloc(esize))==NULL)return(-1);
  for(j = 1;j<size;j++){
    memcpy(key,&a[j*esize]),esize);
    i = j -1;
    whle(i >=0 && compare(&a[i*esize],key)>0){
      mempcy(&a[(i+1)*esize],&a[i*esize],esize);
      i--;
    }
    memcpy(&a[(i+1)*esize],&a[i*size])// GAP
  }
}
/*
Melhor caso: O(n) itens ja estao ordenados
Pior caso : odem reversa O(n²)
caso medio : O(n²)

-->>>>>>>fazer o InsertionSort em um lista simplismente encadeada;
-----------------------------------------------------------------------------------------------------------------------------------------------

QUICKSORT
3 passo:
Dividir os dados em duas partes baseados em um valor de divisao
conquistar classicar as duas partes aplicando quicksort recursivamente
combinar nada a fazer, umas vez que as partes estao

a chave para atigingir o desempenho confiavel reside na forma com que esolhemos o valor da divisoa (pivo)

1- entre com um array A de n valores
Inicialize low =2 up = n , key =A[(low+up)/2]
Repita ate o passo 8 enquanto low <=up
Repita o passo 5 enquanto (A[low]>key)
low = low+1
repita o passo 7 enquanto (A[up]<key)
up = up-1
se low <= up
 swap A[low]
  A [low ] = A[up]
  A[up] = swap
  low = low + 1
  up=up-1

Pior caso : O(n²)
Caso medio : O(n lg n)

-->>>>MERGESORT
do tipo divir e conquistar como o QUICKSORT
so que usa mais memoria
O (n ln n)

--> Heapsort

void heapsort (int *vet,int N){
int i , aux;
for(i=(N-1)/2; i>=0;i--){
criar_heap


O (n log n)
}
}
*/


/* PESQUISA

*/
