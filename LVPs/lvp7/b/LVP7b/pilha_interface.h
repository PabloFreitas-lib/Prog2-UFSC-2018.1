#ifndef PILHA_INTERFACE_H_
#define PILHA_INTERFACE_H_


 typedef struct pilha pilha_t;



 pilha_t *pilha_cria(int cap);

 void pilha_destroi(pilha_t **p);

 int pilha_vazia(pilha_t *p);

 int pilha_cheia(pilha_t *p);

 int pilha_tamanho(pilha_t *p);

 int pilha_empilha(pilha_t *p, void *elem);

 int pilha_desempilha(pilha_t *p, void *elem);

 int pilha_topo(pilha_t *p, void *elem);

 void pilha_imprime(pilha_t *p);

 int insere_elemento(int x, pilha_t *a);

 int membro(int x,pilha_t *a);

 void remove_elemento(int x,pilha_t *a);



#endif /* PILHA_INTERFACE_H_ */
