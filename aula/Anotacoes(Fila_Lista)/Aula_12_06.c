/*
fila_desenfileirar
verificar se ta vazia e apontar a cabeca para o proximo elemento da fila

 IMPLEMENTACAO DE FILA COM VETOR
--Suponha que a Fila seja armazenada em uma vetor, fila[0,...,N-1]
--A parte ocupada do vetor é fila [inicio(cabeca) , ...,fim(cauda)-1]
-- O primeiro elemento da Fila está na posicao ini e o ultimo na posicao fim -1;
-- Os elementos podem não se mover conforme o primeiro elemnto é retirado para ter ganho de desempenho
, entretanto , há perda no uso da memoria;
-- Toda vez que insere o elemento , ou cheio , movimentacao dos dados na fila

enfileira_fila
fila[fimm++]=x;
enfileirar somete se a fila noa estiver cheia
para densenfileirar
x=fila[inicio++]
densenfileirar somente se afila nao estiver vazia

 (NÂO MUITO EFICIENTE /\)

 Para melhorar o processo
 -- O vetor da fila possui duas informcoes :
 -> O elemento armazenado
 -> O indice do proximo elemento da fila
 -- CABECA contem o indice do primeiro elemento da fila
 -- CAUDA contem o indice do ultimo elemento da fila
 --Para inserir um elemento na fila eh preciso saber quem é a cauda e qual o proximo espaco vazio

 */
 typedef int elemento_t; // declaracao no arquivo interface
 typedef struct celula{
   elemento_t dado; // dado armazenado na celula
   int prox;
 }celula_t;

struct fila{
  int cabeca; // indice para a celula da cabeca da fila_desenfileirar
  int cauda; // indicie da celula da caula
  int tamanho;
  int capacidade;
  //...
}
int fila_enfileira(fila_t *f, elemento _t elem){
  if (f==NULL){
    return 0;
  }
  /*
  --achar posicao livre no vetor(pos)
  --coloca elem na posicao livre do VETOR
  --faz o indice da cauda atual ser igual a "pos"
  --faz o indice da cauda ser "pos"
  --incrementa o tamanho da fila
  */
  return(1);
}

int fila_desenfileira(fila_t *f , elemento_t *elem){
  if(f==NULL)
  return 0;
  /*
  --coloca em ELEM o valor armazenado na cabeca da fila
  --atualiza o valor do indice da cabeca
  --faz o indice prox da antiga cabeca ser -1
  --decrementa o tamanho da fila_t
  */
  return 1;
}
/*  FILA circular

--Suponha que os elemetos da fila estejam disposto no vetor fila[0..N-1]de uma das seguintes maneira
-> fila[ini...fim-1]
-> fila[ini..n-1]...fila[0...fim-1]
-> 0<=ini < N e 0<= fim <N
(mas nao pode supor que ini <= fim)
-- A fila esta VAZIA --> (if (o fim == inicio))
--CHEIA -> if( (fim +1 == ini) || (fim +1 == N) && (ini==0))
--A posicao FIM ficara sempre desocupada para que possamos destinguir uma fila cheia e vazia

*/

int fila_enfileira(fila_t *f, tipo_t *elem){
  if (f==NULL || elem==NULL)
  return(0);
  if( (fim +1 == ini) || (fim +1 == N) && (ini==0)) // fila CHEIA
    return 0
    //coloca elem na posicao fim da fila
    //fim++;incrementa o valor de fim em 1
    if(/*fim for igual a capacidade da fila*/)
    fim =0;
}
int fila_desenfileira(fila_t *f,tipo_t *elem){
  if (if (f==NULL || elem==NULL ||((o fim == inicio))) // vazia ou valida
  return(0);
  /*
  --coloca elemento que tiver na posicao inicio em elem
  --incrementa ini em 1*/
  if(inicio == capacidade)
  inicio=0;
  //decrementa o tamanho da fila;
  return 1;
  // inicio = ++ini % CAPACIDADE ;
}

/*
FILA COM PONTEIROS

-- Cada elemento da Fila  uma celula_t
--Cada celula possui um ponteiro para proxima celula e um ponteiro para o tipo de dado armazenado na FILA

*/
typedef struct celula{
  tipo *elemento;
  struct celula *prox;
}celula_t;

struct fila{
  celula_t *cabeca;
  celula_t *cauda;
  int tamanho;
};
//COMO A FILA COM PONTEIROS IMPLENTA AS OPERACOES DE TDA??
/*
-- Cada celula tem um ponteiro para um dado que pode ser de qualquer tipo (void*)
-- Operacoes como imprimir e comparar os elemetnos internamente na Filaa necessitam de ponteiros passados na criacao da Fila
-- USAR o memcpy em fila generica (nao usei ainda)

LISTA

-- Lista é um TDA que organiza os dados sequencialmente na memoria(agruapados atravez de um vetor)
-- piha e filas sao especializacao do conceita de listas onde foram feitas restricoes quanto a insersao e remocao e acessor aos elementos
--Uma lista é simplismente uma sequencia lógica de elemento cuja  a ordenacao, caso exista , é definida na sua aplicacao
-- lisa pode ser acessadas de qualquer lugar
-- Sequencia de zero ou mais itens x1,x2,x3,x4,...,xn, na qual o xi é um determinado tipo e n representa o tamnho linear

--Aplicacoes
*notas de uma turma
*itens em estoque de uma empresa
*vagoes de uma empresa
*lista de emails
*polinomios
*gerenciamneto de memoria do sistema operacional

--Lista sequencial : alocacoa do espaco de memoria para os elementos é contigua e estatica ou dinamica
******PONTEIROS
Existem ponteiro para a cabeca e cauda da lista:
--Simplismente encadeada --> cada celua da lista possui um ponteiro para proxima
--Duplamente encadeada --> cada celula da lista possui ponteiro para  celula anterior e outro ponteiro para a proxima celula
  Obs : Ponteiros de inicio e fim serve para saber quando para em uma lista circular
--Ambas as implementacoes podem ser circulares
--Ainda é possivel realizar a implementacao de uma lista generica, que armazena qualquer tipo de dados

OPERACOES

-criacao,destruicao
-verificar se esta vazia
-impressao
-tamanho
-inserir um elemento apos o i-esimo item
-localizar o i-esimo item para examinar ou alterar o conteudo dos seus componentes
-combinar duas ou mais listas em uma unica lista
-partir duas listas em duas ou mais listas
-fazer uma copia da lista
-ordenar os itens da listas
-pesquisar a ocorrencia de um valor particular

cricacao de LISTA
destruir LISTA

--Se minha lista nao esta vazia , deve destruir cada celula interna ate a lista ficar fazia

--Inserir proximo
* Insere um novo elemento na lista logo apos um elemento conhecido e passado como parametro .
* Caso esse parametro seja invalido , insere o novo elemento na cabeca da lista.
* pre condicoes: lista valida
*/
int lista_insere_proximo(lista_t *t , celula_t *c,elemento_t elem){
pre condicoes
if c invalido
insere elem na abeca da lista e ajusta os ponteiros ou indices de acordo
else
insere elem apos c ajusta os ponteiros ou indices de acordo
incrementa o tamanho da lista
return 1;
}
/*
--Remover o proximo
**remove o elemento apos um elemento conhecido e recebido como parametro .
** caso esse parametro seja invalido , remove o elemento da cabeca da lista.
**Retorna o conteudo do elemento removido em uma variavel elem recebida como parametro.
**pos condicoes: lista com um numero a elementos
*/
int lista_remove_proximo(lista_t *l,celula_t *c,elemento_t *elem){
pre condicoes
if c é invalido retor o conteudo da cabeca d alista em elem
ajusta os ponteiros ou indices de acordo
else
remove o elemeento que estiver apos C e teorna seu conteudo em elemento
ajusta o ponteiros ou indicies de acordo

}
/*
as funcoes de TDA da celula tb sao usadas em fila
por exemplo
void * lista_dado(celula_t *c)
celula_t * lista_proximo(celula_t *c)
celular_t *lista_cabeca(lista_t *l)
celular_t *lista_cauda(lista_t *l)


ela é feita para simplismente encadeada porque eu só sei o proximo elemento da celula
se fosse duplamente encadeada deveria ter o anterior como parametro tb

--Insersao ocore em qualquer lugar da lista
--Tomar cuidado na lista simplismente encadeada o valor de referencia do proximo
--se destruir o primeiro nao tem mais lista

*/

void fun1(celula_t *cabeca){
  if(cabeca==NULL)
  return;
  fun1(cabeca->prox);
  printf("%d ",cabeca->dado);// imprime a lista de ordem reversa
}
//Imprime o conteudo de todas as celulas da lista em ordem reversa

struct celula {
  int dado;
  struct celula *prox;
};
// inverter um lista encadeada
void inverte(struct celula **celula){
  struct celula *prev = NULL;
  struct celula *current = *cabeca;
  struct celula *next;
  while(current!=NULL){
    next = current ->prox;
    current ->prox = prev;
    prev = current;
    current=next;
    *cabeca = prev;
  }
}

// qual a saida d afuncao abaixo qunaod o ponteiro inicio apontar para uma lsita encadeada com os seguintes elementod
// 1->2->3->4->5->6

void fun(struct celula*inicio){
  if(inicio==NULL)
  return;
  printf("%d ",inicio->dado);
  if(inicio->prox !=NULL)
  fun(inicio->prox->prox);
  printf("%d ",inicio->dado);
}
 // 1->3->5->5->3->1
 // precisa ter certeza que o proximo do proximo nao eh nulo

 // a funcao a abaixo recebe uma lsita simsplismente encadeada como argunmento. Ela modifica o ultimo elemento para o inicio. Uma parte do codido esta em branco. Escolha a alternativa que completa a atividade

 typedef struct celula{
   int value;
   struct celula *prox;
 }celula_t;
 celula_t *move_para_frete(celula_t *cabeca){
   celula_t *p,*q;
   if(cabeca==NULL || cabeca->prox ==NULL)
   return cabeca;
   q =NULL;p=cabeca;
   while(p->prox!=NULL){
     q=p;
     p=p->prox;
   }
   q->prox= NULL; p->prox = cabeca; cabeca=p;
   return cabeca;
 }


// LISTA DUPLAMENTE encadeada

/* Como implementar a insersao
1 passo: Criar a celula e atualizar as referencias da celula nova
2 passo: Atualizar a integridade da lista (colocar no encadeamento a celula nova)
3 passo :Atualizar o proximo da referencia que é o novo
4 passo :Atualizar o antorior do proximo do novo

** Total: 4 ponteiros a serem atualizados
** Aumentar o tamanho em +1


Como implementar a remocao
1 passo : atualazar o proximo do meu anterior com o valor do meu proximo  ( rem->anterior->prox = rem->prox)
2 passo : atualizar o anterior do proximo (rem->prox->anterior= rem->anterior) manter a integridade
3 passo : destroi (&rem);
4 passo : reduzir o tamnanho -1;

  A funcao abaixo recebe a celula cabeca de uma lista duplamente encadeada.
 Assuma que uma celula da lista tem um ponteiro chamado prev e um ponteiro para o proximo elemento next.
   Assuma que a lista passada como paramentro seja
   1<> 2 <> 3<> 4<>5<>6
*/
voidfun(celula_t**head){
celula *temp=NULL;
celula*current
tem uma funcao ai em cima que é só trocar
}
/*
LISTA CIRCULAR

-- No lugar dos NULL nas lista , fazer uma "retroalimentacao"
*/

//Lista genericas é só mudar os dados para ponteiro void
//e umas coisas a mais
