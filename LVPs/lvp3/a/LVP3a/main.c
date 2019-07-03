//Seu programa para resolver o problema (incluindo uma main).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int direcoes(int,int,char (*)[]);
int main(void){
    int i=0,j=0,qtd[50],k=0,auxx=0;
  char aux[11]="\0";
  char board[10][10]; 
    for(i=0;i<10;i++){
         scanf("%[^\n]%*c",aux);
        setbuf(stdin,NULL);
        for(j=0;j<10;j++){
            board[i][j] = aux[j];
        }
    }
    
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(board[i][j]==' '){
           qtd[k] = direcoes(i,j,board);
           k++;
            }
        }
    }
    for (i = 1; i < k; i++) {
        for (j = 0; j < k - 1; j++) {
               if (qtd[j] > qtd[j + 1]) {
                auxx = qtd[j];
                qtd[j] = qtd[j + 1];
                qtd[j + 1] = auxx;
       
                }
        }
    }
    printf("O tabuleiro possui %d regioes, de tamanhos:\n",k);
    for(i=0;i<k;i++){
        if(i==(k-1)){
            printf("%d.",qtd[i]);
            break;
        }
            printf("%d,",qtd[i]);
    }
    printf("\n");
return(0);
}

int direcoes(int a,int b,char tabela[][10]){
    tabela[a][b]='*';
    int ctd=1;
    if(a<=9 && b<=9){
    //superior
        if((tabela[a-1][b]==' ') && (a-1>=0)){
            ctd+=direcoes(a-1,b,tabela);
        }
    //baixo
        if((tabela[a+1][b]==' ') && (a+1<=9)){
            ctd+=direcoes(a+1,b,tabela);
        }
    //esquerda
         if((tabela[a][b-1]==' ') && (b-1>=0)){
             ctd+=direcoes(a,b-1,tabela);
        } 
    //direita
        if((tabela[a][b+1]==' ') && (b+1<=9)){
            ctd+=direcoes(a,b+1,tabela);
        }
    }
return(ctd);
}
