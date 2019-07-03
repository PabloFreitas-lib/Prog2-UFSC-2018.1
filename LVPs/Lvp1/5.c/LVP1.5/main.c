#include <stdio.h>
#include <string.h>
int main(void){
    int l,c,i,k,j;
    char game[3][3],jogada,resposta[50]="\0";
    
    for(k=0;k<=2;k++){
        for(j=0;j<=2;j++){
            game[k][j]='0';
        }
    }
    
    for(i=1;i<=9;i++){
        scanf("%c %d %d",&jogada,&l,&c);
        setbuf(stdin,NULL);
        game[l-1][c-1]=jogada;
            

        
            if(
                  ((game[0][0]=='X')&&(game[0][1]=='X')&&(game[0][2]=='X'))
                ||((game[1][0]=='X')&&(game[1][1]=='X')&&(game[1][2]=='X'))
                ||((game[2][0]=='X')&&(game[2][1]=='X')&&(game[2][2]=='X'))
                ||((game[0][0]=='X')&&(game[1][0]=='X')&&(game[2][0]=='X'))
                ||((game[0][1]=='X')&&(game[1][1]=='X')&&(game[2][1]=='X'))
                ||((game[0][2]=='X')&&(game[1][2]=='X')&&(game[2][2]=='X'))
                ||((game[0][2]=='X')&&(game[1][1]=='X')&&(game[2][0]=='X'))
                ||((game[0][0]=='X')&&(game[1][1]=='X')&&(game[2][2]=='X'))
                ){
                    sprintf(resposta,"%s","Jogador X ganhou.");
                     printf("%s",resposta);
                break;
            }
            else if(
                  ((game[0][0]=='O')&&(game[0][1]=='O')&&(game[0][2]=='O'))
                ||((game[1][0]=='O')&&(game[1][1]=='O')&&(game[1][2]=='O'))
                ||((game[2][0]=='O')&&(game[2][1]=='O')&&(game[2][2]=='O'))
                ||((game[0][0]=='O')&&(game[1][0]=='O')&&(game[2][0]=='O'))
                ||((game[0][1]=='O')&&(game[1][1]=='O')&&(game[2][1]=='O'))
                ||((game[0][2]=='O')&&(game[1][2]=='O')&&(game[2][2]=='O'))
                ||((game[0][2]=='O')&&(game[1][1]=='O')&&(game[2][0]=='O'))
                ||((game[0][0]=='O')&&(game[1][1]=='O')&&(game[2][2]=='O'))
                ){
                    sprintf(resposta,"%s","Jogador O ganhou.");
                     printf("%s",resposta);
                break;
                }
            
    }
    if(
                !(
                  ((game[0][0]=='X')&&(game[0][1]=='X')&&(game[0][2]=='X'))
                ||((game[1][0]=='X')&&(game[1][1]=='X')&&(game[1][2]=='X'))
                ||((game[2][0]=='X')&&(game[2][1]=='X')&&(game[2][2]=='X'))
                ||((game[0][0]=='X')&&(game[1][0]=='X')&&(game[2][0]=='X'))
                ||((game[0][1]=='X')&&(game[1][1]=='X')&&(game[2][1]=='X'))
                ||((game[0][2]=='X')&&(game[1][2]=='X')&&(game[2][2]=='X'))
                ||((game[0][2]=='X')&&(game[1][1]=='X')&&(game[2][0]=='X'))
                ||((game[0][0]=='X')&&(game[1][1]=='X')&&(game[2][2]=='X'))
                )
                &&
                !(
                  ((game[0][0]=='O')&&(game[0][1]=='O')&&(game[0][2]=='O'))
                ||((game[1][0]=='O')&&(game[1][1]=='O')&&(game[1][2]=='O'))
                ||((game[2][0]=='O')&&(game[2][1]=='O')&&(game[2][2]=='O'))
                ||((game[0][0]=='O')&&(game[1][0]=='O')&&(game[2][0]=='O'))
                ||((game[0][1]=='O')&&(game[1][1]=='O')&&(game[2][1]=='O'))
                ||((game[0][2]=='O')&&(game[1][2]=='O')&&(game[2][2]=='O'))
                ||((game[0][2]=='O')&&(game[1][1]=='O')&&(game[2][0]=='O'))
                ||((game[0][0]=='O')&&(game[1][1]=='O')&&(game[2][2]=='O'))
                    
                )
                
                ){
          sprintf(resposta,"%s","Empate.");
          printf("%s",resposta);
                    }
    
    //printf("%s",resposta);
  //return(0);
}
