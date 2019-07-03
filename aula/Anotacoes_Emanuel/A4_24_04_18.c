//---------//
/*
--- Continuação - Arquivos ---
-> Possíveis valores para o terceiro parâmetro
	-> SEEK_SET -- Inicio do arquivo
	-> SEEK_CUR -- Posição atual do ponteiro
	-> SEEK_END -- Final do arquivo
-> Exemplos de fseek
	->fseek(arquivo, 3, SEEK_SET)
	->fseek(arquivo, -9, SEEK_END)
	->fseek(arquivo, -2, SEEK_CUR)
-> Função 'ftell'
-> Chamada: ftell(ponteiro_arquivo)
-> Retorna o valor corrente do ponteiro do arquivo
	-> Valor em bytes em relação ao inicio do arquivo
-> Tarefa de programação
	-> Crie um programa que abre um arquivo texto. Abra o arquivo texto e usando somente as funções fseek e ftell, determine o número de
	 caracteres do arquivo.
	*/

fseek(arquivo, 0, SEEK_END);
ftell(arquivo);
//Usar no labirinto para contar o número de linhas
//t_linhas = ftell(lab) / t_colunas;
/*

-> Recusão é um método ou técnica para resolução de problemas
	-> A resolução de um problems e obtida da decomposição do problema original em subproblemas do mesmo tipo, que são então resolvidos
		-> Cada subproblema é resolvido recursivamente, até que se encontre um suproblema com resposta conhecia, que não necessita recursão
-> Em programação na sua forma mais simples uma função é dita recursiva quando chama chama ela mesma (é definida em termos de si)
	-> Esta forma é conhecida como recursão direta
-> Outra forma de recursão é obtida por exemplo quando uma função 'a' chama a função 'b' e a função 'b' chama a função 'a'
	-> Essa forma é conhecida como recursão indireta
-> Na matemática muitos problemas são descritos recursivamente
-> Um problema recursivo clássico é o fatorial de um número
*/
int fatorial(int n){
	if(n == 0 || n == 1)
		return(1);
	return( n * fatorial(n-1))
}
/*
-> As chamadas recursivas vão para a 'Pilha'
-> A recursão produz um comportamento iterativo (ou de repetição), com algumas diferenças em relação a um laço de repetição (for, while, etc)
	-> A recursão não usa um laços, mas sim uma estrutura de seleção e chamadas de função que resultam em comportamento repetitivo
	-> Funções iterativas geralmente ocupam um espaço constante, ao passo que cada chamada de função recursiva
	->Funções recursivas tendem a ser mais lentas que funções iterativas devido ao overhead de chamadas de função e sua criação na pilha
	-> Para determinados problemas as soluções são mais elegantes, simples e práticas. Podem, porém, usar mais memória
-> Implemente de forma recusiva:
	-> Uma função que recebe dois valores, um de base (b) e outro de expoente (e) e retorne o valor de b^e. Use somente multiplicação
	-> Uma função recursiva para imprimir um vetor na ordem usual
	-> Uma função recursiva para imprimir um vetor, na ordem reversa
	-> Uma função recursiva para verificar se uma palavra é palindrome
*/
#include <stdio.h>
#include <string.h>
int expoente(int, int);
void vetor_normal(int *, int n);
int main(void){
	int a=2, b=5, c[3]={1,2,3};
	printf("%d elevado a %d: %d\n",a, b, expoente(a, b));
	printf("Vetor em ordem: ");
	vetor_normal(c, 3);
	return(0);
}
//Ok
int expoente(int num, int exp){
	if(exp == 1)
		return(num);
	return(num * expoente(num, exp-1));
}
//Ok
//n = numero de elementos
void vetor_normal(int vet[], int n) {
	if(n == 1){
		printf("%d", vet[0]);
		return;
		}

	//vetor_normal(vet, n-1); //Ordem normal
	printf("%d", vet[n-1]);
	vetor_normal(vet, n-1);  //Ordem invertida
}
/*

---  ESTRUTURAS ---
-> A declaração de uma estrutura é obtida da seguinte forma
*/
struct nome{
	tipo nome_campo_1;
	tipo nome_campo_2;
	...
	tipo nome_campo_n;
};
/*
-> Declare uma estrutura chamada time que contenha informações de times de futebol, como nome, ano de fundação, número de títulos brasileiros,
número de títulos da libertadores e um ponteiro para a pŕopria estrutura, que está relacionado ao próximo time. Após isso, declare um vetor para
conter as informações dos 20 times da série A do campeonato brasileiro
*/
#include <stdio.h>
#include <string.h>

struct time{
	char nome[128];
	unsigned int ano_fund;
	unsigned int n_titulos_brasileiros;
	unsigned int n_titulos_libertadores;
	struct time *proximo;
};

int main(void){
	struct time times_a[20];
	//manipulacao
	for(int i=0; i<20; i++){
		printf("Entre com o nome do time: ");
		scanf("%[^\n]%*c", times_a[i]->nome);
		setbuf(stdin, NULL);
		printf("Entre com o ano de formacao: ");
		scanf("%d", &times_a[i].ano);
		setbuf(stdin, NULL);
		printf("Entre com a quantia de titulos brasileiros e da libertadores[ta tl]: ");
		scanf("%d %d", &times_a[i].n_titulos_brasileiros, &times_a[i].n_titulos_libertadores);
		setbuf(stdin, NULL);
	}
	return(0);
}
/*
-> '(*p).nome' é o mesmo que 'p->nome'; apenas quando se trata de ponteiros
-> Quando declaramos uma struct, nada é colocado em memória
-> Quando declaramos uma variável estática com aquele tipo
	-> Seu conteúdo
*/
#include <stdio.h>
#include <stdlib.h>

struct pessoa{
	char nome[100];
	int idade;
};

int main(void){
	struct pessoa *p;
	p = (struct pessoa*) malloc(sizeof(struct pessoa)*10);
	int i;
	for(i=0; i<10; i++){
		scanf("%d", &p[i]->nome);
}
	for(i=0; i<10; i++){
		printf("%d", p[i].idade);
	free(p);
	return(0);
}
}

/*
-> Partes da estrutura ou a estrutura inteira podem ser passsadas como parametros em funções. Lembre-se, passagem padrão é por valor.
-> Para que o conteúdo da estrutura seja realmente modificado
	-> Devemos passar a estrutura por referência
-> Passagem por referência possui menor overhead
	-> Evita a cópia de grandes regiões de memória
-> Declare uma estrutura para armazenar uma fração. Faça fuas funções:
 (i) uma para ler os valores de uma fração passada a função;
(ii) uma para imprimir uma fração. Faça um programa e teste as suas funções
*/
#include <stdio.h>
#include <stdlib.h>


struct fracao{
	int numerador;
	int denominador;
};

void le_fracao(struct fracao *);
void imprime_fracao(struct fracao);


int main(void){
	struct fracao f1;
	le_fracao(&f1);
	imprime_fracao(f1);
	return(0);
}

void le_fracao(struct fracao *f){
	printf("Entre o numerador: ");
	scanf("%d", &f->numerador);
	printf("Entre o denominador: ");
	scanf("%d", &f->denominador);
}

void imprime_fracao(struct fracao f){
	printf("%d/%d\n", f.numerador, f.denominador);
}
