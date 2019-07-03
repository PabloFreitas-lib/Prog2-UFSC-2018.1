/*Estruturas - continuação
-> Existem duas maneiras de passar argumentos a uma função, denominadas chamada 'por valor' e chama 'por referência'
-> Todos os argumentos em C são passados por valor
-> Muitas funções exigem a capacidade de modificar uma ou mais variáveis na função chamadora ou passar um ponteiro para um objeto com grande quantidade
 de dados, para evitar /.../
-> Para essas finalidades, C oferece recursos para uma simulação de chamada por referência
-> Em C, você usa ponteiros e operadores de indireção para simular uma chamada por referência
-> Ao chamar uma função com argumentos que devem modificados, os endereços dos argumentos são passados
-> Isso normalmente é feito ao se aplicar o operador (&) à variável
-> Uma função que recebe um endereço como argumento precisa definir um parâmetro de ponteiro para receber esse endereço
-> O compilador não diferncia uma função que recebe um ponteiro de uma função que recebe um array unidimensional
-> Exp:
	int func(int b[])
	int func(int *b)
-> Siginificam a mesma coisa. O compilador converte o parâmetro b[] para a notação de ponteiro automaticamente
-> Um ponteiro para ponteiro é como se você anotasse o endereço de um papel que tem o endereço da casa do seu amigo
-> Declaração
	Tipo **nome_da_variável;
-> No C podemos declarar ponteiros para ponteiros para ponteiros, ou então, ponteiros para ponteiros para ponteiros e assim por diante
-> Basta aumentar o número de * na declaração
-> Para acessar o valor desejado apontado por um ponteiro para ponteiro, o operador asterisco deve ser aplicado duas vezes
-> __a    __*b   __**c
  |1| <- |2| <- |3|
  --     --     --
	a=5;
	**c=55; -- 'a' passa a ser 55
	endereço de a = *c
	endereço de a = conteúdo de b
*/
#include <stdio.h>
int main(void){
	float fpi = 3.1415, *pf, **ppf;
	pf = &fpi;  // pf armazena o endereço de fpi
	ppf = &pf; // ppf armazena o endereço de pf
	printf("%f\n", **ppf); // Imprime o valor de fpi
	printf("%f\n", *pf);  // Imprime o valor de fpi
	return(0);
}
/*
-> Um ponteiro para função contém o endereço da função na memória
-> Vimos que o nome de um array é, na realidade, o endereço na memória do primeiro elemento do array
-> De modo semelhante, um nome de função é o endereço inicial na memória do código que realiza a tarefa da função
-> Os ponteiros para funções podem ser passados para funções, retornados de funções, armazenados em arrays, atribuídos a outros ponteiros para funções
*/
//Declaração
int (*func_ptr)(void)
//func_ptr é um ponteiro para uma função que retorna um inteiro e não recebe parâmetros
//Como usar
int funcao(void){...}
int main(void){
	int (*func_ptr)(void); //Declaração
	func_ptr = funcao; //Inicializando o ponteiro
	(*func_ptr)(); //invoca a funcão
}
// O nome da função armazena o endereço da função
/*
-> Os ponteiros para função são comumente usados nos sistemas controlados por menu de texto
-> Um usuário precisa selecionar uma opção a partir de um menu (possivelmente 1 a 5), digitando o número do item do menu
-> Cada opção é atendida por uma função diferente
-> void (*f[3])( int ) = { function1, function2, function3 }
          |       |       ________________________________
          |       |           |
          |       |           |->Funções armazenadas
          |       |->Tipo das funções armazenadas
          |-> Ponteiro/array de 3 espaços para funções

-> (*f[ choice ])(choice);   Choice varia de 0 a 2;
     |-> Chama a função para o local selecionado do array [choice] /.../ choice como argumento da função chamada (choice)
*/
#include <stdio.h>


void function1( int a);
void function2( int b);
void function3( int c);

int main(void){
	void (*f[3])( int ) = { function1, function2, function3 }
	int choice;
	printf("Insira um numero de 0 a 2. Digite 3 para sair");
	scanf("%d", &choice);

	while(choice >= 0 && choice <3) {

	(*f[ choice ])(choice);
	printf("Insira um numero de 0 a 2. Digite 3 para sair");
	scanf("%d", &choice);
	}
	printf("Programa terminado");
	return(0);
}
//Fazer funções
/*
-> gdbgui - Depuração
-> O que "pf" representa?
	int (*pf)();
	pf é um ponteiro de uma função que retorna um int
-> Ponteiros para funções podem ser passados como argumentos para outras funções e a função apontada pode ser invocada a partir de seu ponteiro
-> Escreva um programa em C que possua uma função que compare dois inteiros. Essa função retorna -1 caso o primeiro seja menor que o segundo, 0 se forem
 iguais ou 1 se o primeiro for maior que o segundo
-> O programa então deve criar um ponteiro para essa função, chamá-lá através do ponteiro para comparar dois inteiros recebidos pela linha de comando
 e imprimir o valor de retorno.
*/
#include <stdio.h>

int compara(int a, int b);
int main(void){
	int a, b;
	int (*fPtr)(int, int);
	fPtr = compara;
	scanf("%d %d", &a, &b);
	printf("%d\n", (*fPtr)(a, b));
	return(0);
}

int compara(int a, int b){
	if( a > b )
		return(1);
	if( a == b )
		return(0);
	if( b > a )
		return(-1);
}
/*
/-----/Aula - Alocação dinâmica de memória
-> Toda variável declarada em um programa ocupa um espaço de memória
-> Exemplo: como os dados a seguir são organizados na memória
	int a;
	int *ptr;
	a = 10;
	ptr = &a;
	*ptr = *ptr * 100;
-> Criar e manter dados dinâmicos exige uma alocação dinâmica de memória - a capacidade que um programa tem de obter mais espaços de memória durante
 a execução para manter novos dados e para liberar espaço do qual não se precisa mais
-> O limite para locação dinâmica de memória pode ser tão grande quanto a quantidade de memória física disponivel no computador, ou a quantidade
 de memória virtual dísponivel em um sistema de memorita virtual
	-> Também é dependente do numero de aplicações e do sistema operacional
-> As funções 'malloc' e 'free', e o operaodr 'sizeof' são essenciais para a alocação dinâmica
-> malloc - quando se precisa de mais espaço/memória
-> free - devolve a memória ocupada
-> sizeof - calcula o tamanho dos tipos em bytes
-> O operador 'sizeof' retorna o tamanho de um tipo
*/
int a = sizeof(int); // 'a' tem o valor de 4, pois inteiro tem 4 bytes
//------------------------------------------------------------------//
struct minha_estrutura{
	int x;
	int y[11];
}
int a = sizeof(minha_estrutura); // 'a' tem valor de 48, pois 'minha_estrutura' tem 12 inteiros
/*
-> A função 'malloc' usa o número de bytes a serem alocados como argumento, e retorna um ponteiro do tipo 'void *' (ponteiro para void)
 para a memória alocada
-> Um ponteiro 'void *' pode ser atribuído a uma variável de qualquer tipo de ponteiro
-> A função 'malloc' geralmente é usada com o operador 'sizeof'
-> Por exemplo, a instrução
	int *newPtr = malloc( sizeof ( int ) * 4 );
-> Avalia sizeof(int) * 4 para determinar o tamanho em bytes de um vetor de inteiros de 4 posições, aloca uma nova área na memória desse mesmo
número de bytes e armazena um ponteiro para a memória alocana em newPtr
-> A memória alocada não é inicializada
-> Se não houver memória disponivel, malloc retorna NULL
-> Deve-se então sempre testar o retorno de 'malloc' para garantir que a memória foi alocada corretamente
-> Ainda pode-se usar as funções 'calloc' e 'realloc' também da "stdlib.h"
-> A função 'free' libera memória - ou seja, a memória é retornada ao sistema, de modo que possa ser realocada no futuro
-> Para liberar memória dinamicamente alocada pela chamada malloc anterior, use a instrução "free( newPtr )"
-> Ou seja, a função free recebe um ponteiro para uma região de memória que foi previamente alocada pela função malloc
*/
#include <stdio.h>
#include <stdlib.h> // necessário para usar malloc
int main(void){
	int *p, a, i;
	a = 10;
	p = malloc( a * sizeof(int) );  // aloca 10 números inteiros
	if(!p){
		printf("Memória insuficiente\n");
		exit(1);
	}
	for(i=0; i<a; i++)
		p[i] = i * i;
	free(p); // sempre desalocar a memória alocada!
}
/*
-> Saiba sempre para onde o ponteiro está apontada
	-> Nunca use um ponteiro que não foi inicializado
-> Não irá acontecer nenhum erro de compilação se o ponteiro for usado sem ser inicializado
