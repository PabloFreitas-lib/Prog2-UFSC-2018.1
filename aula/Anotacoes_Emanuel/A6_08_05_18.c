/*
--- Aula: Estruturas, Uniões e Enumerações ---
-> Uma união é um tipo de dado derivado - como uma estrutura. Ela é uma posição de memória que é compartilhada por duas ou mais variáveis diferentes,
 em momentos diferentes.
-> Para diferentes situações em um programa, algumas variáveis podem não ser relevantes, mas outras variáveis o são, de modo que uma união compartilha
 o espaço em vez de desperdição armazenamento em variáveis que não são mais usadas
-> O número de bytes usados para armazenar uma união precisa ser, pelo menos, o suficiente para manter o maior membro
-> Uma união é declarada com a pabara-chave 'union' no mesmo formato de uma estrutura
-> A declaração de union:
*/
union u_type{
	int i;
	char ch;
};
//Apenas o último escrito é o válido
//Indica que 'u_type' é um tipo unicon com os membros 'int i' e 'char ch'
	union u_type cnvt; // cria a variável cnvt
/*
-> Tanto o inteiro 'i' como o caractere 'ch' compartilham a mesma posição de memória (qual o tamanho da união?)
-> Para acessar, usa-se o operador '.' e '->' como em uma estrutura
*/
//Exp 1
#include <stdio.h>
union number{
	int x;
	double y;
};

int main(void){
	union number value;

	value.x = 100;
	printf("%s %s\n %s = %d\n %s = %f\n","Coloca um valor no membro inteiro", "e mostra os dois membros.", "int:", value.x, "double:", value.y);
	value.y = 100.0; //coloca um double na mesma union
	printf("%s %s\n %s = %d\n %s = %f\n", "Coloca um valor no membro de ponto flutuante", "e mostra os dois membros.", "int:",value.x, "double:", value.y);
	return(0);
}

//-----------------------------------//
//Exp 2 - União com estrutura

struct s1{
	int i, w; // tipo int
};

union u1{
	double valor; // tipo double
	struct s1 mv1, mv2; // tipo struct s1
};

union u1 m_uniao; // tipo union
m_uniao.mv1.i = 100; // declarcao de uma variavel m_uniao do tipo union (struct)mv1 . int i

union tipos{
	double valor; // tipo double
	int val_i; // tipo int
};

struct int_double{
	char tipo; // tipo char
	union tipos m_valor; // tipo == union tipos
};

/*
-> C oferece mais de um tipo definido pelo usário, chamado de enumeração
-> Uma enumeração, introduzida pela palavra-chave 'enum', e um conjunto de constantes de enumeração inteiras, representadas por identificadores
-> Os valores em uma 'enum' começam com 0, a menos que haja outras especificações, e são incrementadas por 1
-> Por exemplo, a enumeração
*/
	enum meses{ JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ };
/*
-> Cria uma novo tipo, 'enum meses', em que os identificadores são definicos com os inteiros de 0 a 11, respectivamente
-> É possível mudar a ordem numérica:
	enum meses{ JAN, FEV, MAR, ABR, MAI, JUN, JUL=25, AGO, SET, OUT, NOV, DEZ }; //0,1,2,3,4,5,25,26...
*/
//Exemplo_1
enum meses {JAN , FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ};

int main(void){
	enum meses mes; //Pode conter qualquer um dos 12 meses

	const char *nomeMes[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

	for(mes = JAN; mes <=DEZ; mes++){
		printf("%d - %s\n", mes + 1, nomeMes[mes]);
		}
	return(0);
}
//Exemplo_2
//Enumerações são interessantes para construções no estilo switch:

enum retorno{ OK, ERRO };
retorno funcao(void);

int main(void){
	enum retorno ret;
	ret = funcao();
	switch(ret){
		case OK: ...
		case ERRO: ...
	}
	...
	return(0);
}

// Uma suposição comem, porém errônea, sobre enumerações é que os símbolos podem ser enviados para saída e recebidos da entrada diretamente
enum coin{penny, nickel, dime, quarter, half_dollar, dollar};
enum coin money;
money = dollar;
printf("%s", money); //isso não funciona

//Dollar é simplesmente um nome para um inteiro
//'strcpy(money, "dime"); //também não funciona
/*
-> A palavra-chave 'typedef' oderece um mecanismo de criação de sinônimos para tipos de dados previamente definidos
-> Os nomes dos tipos de estruturas normalmente são definidos a partr de 'typedef' para que se criem nomes de tipos mais curtos
-> Por exemplo, a instrução:
*/
	typedef struct card Card;
/*
-> Define o novo nome de tipo 'Card' como sinônumos para o tipo struct card;
*/
Card variavel;
Card deck[52];
/*
-> A forma geral do typedef é:
	-> typedef tipo novo_nome;
-> Por exemplo, você poderia criar um novo nome para float:
	-> typedef float meu_float;
-> Esse comando diz para o compilador conhecer meu_float como sinônumo de float
	-> meu_float var;
-> 'var' é uma variável float
	-> typedef meu_float meu_segundo_float;
-> Existe uma aplicação útil de typedef: simplificar a declaração de variáveis struct, union ou enum
*/
struct mystruct{
	unsigned int x;
	float f;
};

//Para declarar: struct mystruct s;
//Essa declaração exige o uso de dois identificadores: 'struct' e 'mystruct'
//Usando typedef na declaração de struct:
	typedef struct mystruct{
		unsigned int x;
		float y;
	}mystruct;
//Agora pode-se criar uma estrutura usando o novo tipo mystruct s;
//Pode-se usar sem dar um nome inicial:

typedef struct {
	char tipo;
} int_double;

int_double mvar;
mvar.tipo = ' ';

/*
-> Estruturas
	-> struct nome campos;
	-> struct nome var;
-> Uniões
	-> Membros compartilham o mesmo endereço
-> Enum
	-> enum nome nome1, nome2, ...;
-> typedef
	-> typedef struct nome meu_tipo_t;

--- Aula: Tipos de dados abstratos ---
-> Todo programa manipula tipos de dados
-> Há diferentes implementações possíveis para o mesmo tipo de dado
-> Todas definem o mesmo domínio e não mudam o significado das operações
*/
typedef struct{
	int numerador;
	int denominador;
} fracao_t;

int main(void){
	fracao_t f;
	printf("Digite um numerador: ");
	scanf("%d", &f.numerador);
//XXXXXX.h
#define NUMERADOR 0
#define DENOMINADOR 1

typedef int fracao_t[2];

int main(void){
	fracao_t f;

}
/*
-> São 3 conceitos covertos na disciplina
-> São parecidos mas com significados diferentes
-> Em linguagem de programação o tipo de dado de uma variável, constante ou função define o conjunto de valores que a variável, constante ou
função podem assumir
	-> Ex: uma variável do tipo bool pode assumir valores 'true' ou 'false
-> Programador pode definir novos tipos de dados, usando outros já existentes
	-> Vetores e arrays
	-> Typedef
-> Um tipo estruturado é um exemplo de estrutura de dados
	-> Tipos estruturados são estruturas de dados já pré-definidas na linguagem de programação
	-> O programador pode definir outras estruturas de dados para armazenas as informações que seu programa precisa manipular
	-> Vetores, structs, listas encadeadas, pilhas, filas, árvores, grafos, são exemplos de estruturas de dados típicas utilizadas para armazenar
	informação em memória principal
-> Tipos de dados podem ser vistos como métodos para interpretar o conteúdo da mamória do computador
-> Mas podemos interpretar o conceito de tipo de dado sob outra perspectiva
	-> Não em termos do que um computador pode fazer (interpretar os bits...), mas em termos do que os usuários (programadores) desejam fazer
	(p.ex., somar dois inteiros...)
	-> O programador não se importa muito com a representação no hardware, mas sim com o conceito matemático de inteiro
	-> Um tipo inteiro suporta certas condições
->Também chamado como "Tipo Abstrato de Dados (TDA)"
-> Os tipos e estruturas de dados existem para serem usados pelo programa para acessar informações neles armazenadas, por meio de operações
 apropriadas
-> Do ponto de vista do programador, muitas vezes é conveniente pensar nas estruturas de dados em termos das operações que elas suportam,
 e não da maneira como elas são implementadas
-> Uma estrutura de dados definida nesta forma é chamada de um "Tipo de Dado Abstrato (TDA)"
-> TDA, portanto, estabelece o conceito de tipo de dado divorciado da sua representação
-> Definido como um modelo matemático por meio de um par T(v, o) em que
	-> v é um conjunto de valores
	-> o um conjuntos de operações sobre esses valores
	-> Ex: tipo real
		-> v = R
		-> o = {+, -, *, /, =, <, >, <=, >=}
-> As implementações ou operações realizadas em estruturas de dados estão constantemente em modificação em programas reais. Melhorar:
	-> Velocidade
	-> Eficiência (memória)
	-> Clareza
-> Tais mudanças êm grande ipacto nos programas que utilizam a estrutura de dados. Por exemplo:
	-> Reimplementação de código
	-> Mais suscetível a erros --> custo mais alto
-> Como podemos modificar as implementações sobre as estruturas de dados com o menor impacto possível para os programas?
-> TDA
	-> Encapsular ou esconder a implementação de quem efetivamente usa a estrutura de dados
-> A organização em TDA permite:
	-> Legibilidade (transparência)
	-> Reaproveitamento de código
	-> Facilidade de teste (isolamento)
	-> Programação simplificada de aplicação
-> Pode ser visto como uma caixa-preta que apresenta uma interface de operações sobre determinada(s) estrutura(s) de dados adequadas
a funcionalidade que se pretende implementar
-> Exmplo: caixa eletrônico
-> O TDA oferece uma interace para o usuário com todas as operações sobre as estruturas de dados disponíveis
-> Ao usuário (programa do usuário no nosso caso), não interessa a forma como o TDA é implementado internamente

Exp:
cria_fracao(N, D) -> Pega dois inteiros e retorna a fração (fracao_t) N/D

acessa_numerador(F) -> Pega a fração (fracao_t) e retorna o numerador

acessa_denominador(F) -> Pega a fração (fracao_t) e retorna o denominador
*/

fracao_t soma(fracao_t f1, fracao_t f2){
	int n1 = acessa_numerador(f1);
	int n2 = acessa_numerador(f2);
	int d1 = acessa_denominador(f1);
	int d2 = acessa_denominador(f2);
	return( cria_fracao(n1*d2+n2_d1, d1*d2) );
}
/*
-> Então temos o TDA estruturado em dois aspectos
-> Modelo de dados (a estrutura de dados que armazena as informações)
-> Conjuntos de operações ou funções que atuam sobre o modelo de dados

-> Principais (presentes na interface)
	-> Construtoras: criam o TDA
	-> De acesso: retornam informações sobre os elementos do TDA sem mdificá-los
	-> De manipulação: modificam os elemtos do TDA
	-> Destruidoras: destroem os dados dinamicamente alocados pelo TDA e garantem que os ponteiros estejam seguros

-> Privativas (acessíveis apenas pelas funções do próprio TDA)
	-> Auxiliam na implementação das funções principais e não estão presentes na interface TDA

-> Na interface do TDA, espera-se que sejam descritas todas as informações de utilização do mesmo
	-> Definição de constantes
	-> Definição de tipos de dados
	-> Definições de cada operação/função:
		-> Pré-condições (estado de entrada exigido)
		-> Pós-condições (estado de saída gerado)
		-> Protótipo ou assinatura das funções
->
