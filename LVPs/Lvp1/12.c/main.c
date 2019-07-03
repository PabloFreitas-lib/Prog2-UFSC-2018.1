#include <stdio.h>
int main(void){
    
int t,j,i;
scanf("%d",&t);
if(t<=0 || t>10)
    return(0);
printf("x");
for(j=1;j<=t;j++){
        printf(" %d",j);
    }
    printf("\n");
    
    for(i=1;i<=10;i++){
        printf("%d ",i);
        for(j=1;j<=t;j++){
            if(j==t){
              printf("%d",i*j);
              break;
            }
            printf("%d ",i*j);
        }
        printf("\n");
    }
return(0);
}
