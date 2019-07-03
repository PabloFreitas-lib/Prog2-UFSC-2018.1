/*
Operacao de busca em uma arvore

VErifica se um determinado valor esta ou nao em uma arvore binaria de busca
PRE : a arvore deve existir
POS : Retorna 1 se o valor recebido estiver na arvore, 0 caso o contrario
OBs :

*/

int arvore_busca(arvore_t *a,nodo_t *raiz,elemento_t valor){
if(a==NULL)return(0);
if(igual a valor da raiz)return 1
if (valor menor que  valor da raiz)
busca segue pela subarvore da esquerda
if(valor eh maior que a raiz)
busca segue pela direita
}

/*
INSERCAO

INSERE UM ELMENTO EM UM NOVO NO DE UMA abb
nAO INSERE CASO O VALOR JA estiver na arvore
pre : a arvore deve existir o elemento dever ser valido e nao deve estar na arvore_t
pos:
obs: a insercao sempre se da como no folha , nao existindo deslocamento;
*/
int arvore_insere(arvore_t *a, node_t *raiz,elemento_t elem){
if(a==NULL)return(-1);
if(arvore_vazia(a))n->raiz = raiz;
return(0);

if elem igual ao valor da raiz return;
if(elem eh menor que o valor da raiz)
  if(existir filho)
    isersao vai para a subarvore da esquerda
    else
    insere elem como filho esquerdo da raiz
  if(elem meaior que o valor da raiz)
    if(existir filho direito)
      insersao segue pela subarvore da direita
    else
    insere elemento como filho da esquerda da raiz
  incrementa o tamanho da arvore_t return 1;
}
}

/*
Remocao possui 3 casos
Caso 1 :
o no eh folha o no pode ser retirado sem nenhum problema
caso 2:
 o no possui apenas uma subarvore
 o no da subarvore (ou da esquerda ou direita)pode subistituir o no revmovido
 Caso 3 :
 o no cuja cahve seja menor da subarvore da direita pode subistituir o no removidao ou alternativamente
  o de maior valor da subarvore da esquerda pode subistituiro o no a ser removido
*/

int arvore_remove(arvore_t*a,node_t *raiz,elemento_t elem){
if(arvore invalida ou elemento invalido)return 0;
if(arvore vaiza)return (0);
if(raiz eh invalida)return-1;
if (elem tem o emso valor de raiz)
remove o no raiz da arvore
ajusta os ponteiros conforme os 3 casos da Remocao
if(elem eh menor que o valor da raiz)
remocao segue pela subarvore da esquerda
if(elem eh amior que o valor da raiz)
remocao segue pela subarvore da direita

decrementa o tmaanho da arcore
return 1;
}
/*

Criar uma arvore ordenada
*/
arvore_t *arvore_cria_balanceada(elemento_t *elementos){
1) oredene os elementos recebido em ordem crescente
2)O resgistro do meio eh inserino na ABB arvore_vazia
3)tome a metade esquerda do vetor repita o passo 2 para a subarvore da esquerda
4) idem para a metdade da direita e subarvore direita
5)repita o processo ate nao poder dividir mais
6)reotrna a arvore arvore_cria_balanceada;

}

/*
