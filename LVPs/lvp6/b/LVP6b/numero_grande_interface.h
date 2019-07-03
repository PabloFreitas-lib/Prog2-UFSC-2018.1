#ifndef numero_interface_h
#define numero_interface_h

#include "lista_interface.h"


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//define o tipo numero_grande_t
typedef struct numero_grande numero_grande_t;

/*
 * Cria um numero_grande_t e o inicializa como vazio.
 * o argumento "libera" prove uma maneira de liberar dinamicamente os dados alocados
 * Pre: nenhuma
 * Pos: retorna um ponteiro para um numero_grande_t se houver memoria disponivel
 */
numero_grande_t *numero_cria(void (*libera)(void *));

/*
 * Destroi o numero especificado em "n". Nenhuma operacao eh permitida apos a funcao, a nao ser que numero_cria seja chamada novamente.
 * Destroi tudo que estiver dentro do numero
 * Pre: "n" deve ser um numero_grande_t valido criado previamente atraves da funcao numero_cria
 * Pos: os recursos do numero foram liberados com sucesso e "n" torna-se nulo
 */
void numero_destroi(numero_grande_t **n);


/*
 * Retorna um ponteiro para o TDA lista armazenado dentro de "n"
 * Pre: "n" deve ser valido e previamente criado atraves da funcao numero_cria
 * Pos: retorna um ponteiro para o TDA lista que esta dentro de "n"
 */
numero_grande_t *numero_lista(numero_grande_t *n);

/*
 * Retorna o sinal do numero armazenado dentro "n"
 * Pre: "n" deve ser valido e previamente criado atraves da funcao numero_cria
 * Pos: true para positivo, false para negativo
 */
bool numero_sinal(numero_grande_t *n);

/*
 * Muda o sinal do numero armazenado dentro "n" para o sinal recebido em "s"
 * Pre: "n" deve ser valido e previamente criado atraves da funcao numero_cria
 * Pos: "n" para ter o sinal especificado em "s" (true positivo, false negativo)
 */
void numero_muda_sinal(numero_grande_t *n, bool s);


/*
 * Insere o "digito" ao numero_grande_t especificado em "n". A insercao eh realizada sempre ao final do numero
 * (sempre como digito menos significativo do numero existente), deslocando os digitos presentes para a esquerda
 * Pre: "n" deve ser valido e previamente criado atraves da funcao numero_cria e "digito" deve ser um digito valido
 * Pos: retorna 1 caso a insercao for bem sucedida, 0 caso contrario
 */
int numero_insere_digito(numero_grande_t *n, char *digito);

/*
 * Realiza da soma de "n1" com "n2" (n1 + n2) e retorna o resultado em um novo ponteiro numero_grande_t
 * Pre: "n1" e "n2" devem ser validos e previamente criados atraves da funcao numero_cria, deve haver memoria para criar um novo numero_grande_t
 * Observe que ambos podem ser validos, mas podem nao conter digitos. Nesse caso, se o numero nao tiver digito, considere que ele tenha valor 0
 * Pos: retorna um ponteiro para um novo numero_grande_t que tera o resultado da soma de "n1" com "n2" ou NULL caso as pre condicoes nao forem satisfeitas
 */
numero_grande_t *numero_soma(numero_grande_t *n1, numero_grande_t *n2);

/*
 * Realiza a subtracao de "n1" com "n2" (n1 - n2) e retorna o resultado em um novo ponteiro numero_grande_t
 * Pre: "n1" e "n2" devem ser validos e previamente criados atraves da funcao numero_cria, deve haver memoria para criar um novo numero_grande_t
 * Observe que ambos podem ser validos, mas podem nao conter digitos. Nesse caso, se o numero nao tiver digito, considere que ele tenha valor 0
 * Pos: retorna um ponteiro para um novo numero_grande_t que tera o resultado da subtracao de "n1" com "n2" (n1 - n2) ou NULL caso as pre condicoes nao forem satisfeitas
 */
numero_grande_t *numero_subtrai(numero_grande_t *n1, numero_grande_t *n2);

/*
 * Realiza a multiplicacao de "n1" com "n2" (n1 * n2) e retorna o resultado em um novo ponteiro numero_grande_t
 * Pre: "n1" e "n2" devem ser validos e previamente criados atraves da funcao numero_cria, deve haver memoria para criar um novo numero_grande_t
 * Observe que ambos podem ser validos, mas podem nao conter digitos. Nesse caso, se o numero nao tiver digito, considere que ele tenha valor 0
 * Pos: retorna um ponteiro para um novo numero_grande_t que tera o resultado da multipliacao de "n1" com "n2" (n1 - n2) ou NULL caso as pre condicoes nao forem satisfeitas
 */
numero_grande_t *numero_multiplica(numero_grande_t *n1, numero_grande_t *n2);

/*
 * Realiza a divisao de "n1" por "n2" (n1 / n2) e retorna o resultado em um novo ponteiro numero_grande_t (divisao inteira)
 * Pre: "n1" e "n2" devem ser validos e previamente criados atraves da funcao numero_cria, deve haver memoria para criar um novo numero_grande_t
 * Observe que ambos podem ser validos, mas podem nao conter digitos. Nesse caso, se o numero nao tiver digito, considere que ele tenha valor 0
 * Pos: retorna um ponteiro para um novo numero_grande_t que tera o resultado da divisao inteira de "n1" por "n2" (n1 / n2) ou NULL caso as pre condicoes nao forem satisfeitas
 */
numero_grande_t *numero_divide(numero_grande_t *n1, numero_grande_t *n2);

#endif
