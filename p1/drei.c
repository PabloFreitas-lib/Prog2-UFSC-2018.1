#include <stdio.h>
int main(void){
  void *zPtr; /* zPtr faz referencia ao array z */
//void *aPtr = NULL;
void *sPtr = NULL;
int numero, i;
int z[5] = {1, 2, 3, 4, 5};
sPtr = z;
//++zPtr;
zPtr = z;
numero = *((int *)(zPtr+1*(sizeof(int)))); /* usa o ponteiro para obter o primeiro valor do array */
/* atribui o elemento 2 do array (o valor 3) a numero */ numero = *((int*)(zPtr+2*(sizeof(int))));
/* imprime todo array z */
 for (i =0; i < 5; i++)
printf("%d<--zPtr[%d] \n ", *((int*)(zPtr+i*(sizeof(int)))),i);
/* atribui o valor apontado por sPtr a numero */ numero = *((int*)(sPtr+1*(sizeof(int))));
//++z;
printf("Numero == %d\n",numero);
return(0);
}
