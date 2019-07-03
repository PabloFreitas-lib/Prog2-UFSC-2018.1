#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int direcoes(int,int,char **,int,int);
int main(int argc, char *argv[]) {
    //declarar variaveis usadas
    int a,b,n=0,m=0;
    //abrir
 FILE *arq = fopen(argv[0],"r");
 
 // LER e armazenar na matrix labirinto
 char **lab=(char**)malloc(sizeof(char**)*1);
    while(lab[n][m]!=EOF){
        while(!((lab[n][m] = '\n')|| (lab[n][m] = EOF))){
            fscanf(arq,"%c",&lab[n][m]);
            m++;
            //lab = realloc(lab,sizeof(char**)*m);
        }
        n++;
    }
        //tentar os caminhos
        for(a=1;a<n;a++){
            for(b=0;b<m;b++){
            direcoes(a,b,lab,n,m);
            }
        }
        //saida formatada
        for(a=1;a<n;a++){
            for(b=0;b<m;b++){
                if(lab[a][b]=='*')
                lab[a][b]=' ';
         printf("%c",lab[a][b]);
            }
        }
        //fechar arquivo
        fclose(arq);
    return (0);   
}

int direcoes(int a,int b,char **tabela,int n,int m){
    //caso BASE
    if(a<0 || b<0 ||a>=n ||b>=m)
        return (0);
    if(a==(n-2) && b==(m-1))
        return (1);
    if(tabela[a][b]!=' ')
        return (0);
    else
        tabela[a][b]='.';
    //direcoes
    if(direcoes(a-1,b,tabela,n,m) || direcoes(a+1,b,tabela,n,m) || direcoes(a,b-1,tabela,n,m) || direcoes(a,b+1,tabela,n,m)){
        return (1);
}else{
        tabela[a][b]=' ';
    }
        return(0);
    
}
