#include "aplicacao.h"
#include <stdio.h>

int main(void)
{
	int up,down,up_1,down_1;
	scanf("%d %d",&up,&down);
	scanf("%d %d",&up_1,&down_1);
	racional_t *a, *b, *c;
	a = cria_racional(up, down);
	b = cria_racional(up_1,down_1);
	c = soma_racional(a, b);
	mostra_racional(a);
	printf(" + ");
	mostra_racional(b);
	printf(" = ");
	mostra_racional(c);
	printf("\n");
	printf("PRE: Endereco de a = %p\n", a);
	destroi_racional(&a);
	printf("POS: Endereco de a = %p\n", a);
	destroi_racional(&b);
	destroi_racional(&c);
}
