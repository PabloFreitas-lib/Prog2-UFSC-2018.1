/*
                    ARVORES
--Eh mais util que lista pois para buscar ela eh mais rapida mas a insercao e remocao menos eficiente
--Tenta organizar a insercao remocao e buscar
--Arvores eh um TDA mais geral que o TDA lista encadeada , um tipo especial de grafo
--Em computacao, uma arvove eh um modelo abstrato de estrutura hierarquia
--Trata-se uma estrututra nao linear de nos com relacao de parentesco
--> Arvore T : conjunto finito de elementos,denominados nos, nodos ou vertices,tais que :
-Se T = 0 a arvore é dita vazia
-- Caso contrario T contem um no especial, denominado raiz(Rt)
-- Os demais nos, ou consituem um unico conjunto vazio, ou sao dividios em n conjuntos disjuntos nao vazios


Aplicacoes:
----------------------------------------------------------------
  Codificacoes/decodificacoes
  pesquisa/armazenamento de dados em banco de dados
  janela em um interface grafica do usuario formando hierarquia
  processamento de expressoes matematica
  IA
  hierarquia de processos de um sistema operacional
  arquivo em um sistema operacional
----------------------------------------------------------------
Quando digo que a arvore eh de grau 3 ,cada no pode ter ate 3 nos.
Estudaremos Arvores Binarias
--> Eh um conjunto finito de elemento que esta vazio ou eh particionado em 3 subconjuntos
  -- raiz
  -- subarvore da esquerda
  -- subarvore da direita

--> Nos das extremidades sao nos folhas
--> Uma subarvore esquerda ou direita pode estar vazia(ou ambas) --> No folhas
--> Cada elemento da arvore eh chamada de no(ou nodo) (celula da fila ou lista)

          999
      esq.  dir.

--> Casos de nao ser um arvore Binarias
  -- Um no nao pode ter 2 pais
  -- Nao pode haver os cruzamentos
  -- Um no raiz pode ter no maximo 2 subarvore

                  2(RAIZ PAI de 7 e 5)
            7               5

--> Ter um ideia de ancestralidade (descendentes)
  -- Ou a arvore possui todos as subarvore ou ela eh uma folhas
  -- Todos os nos ou sao folha ou tem as duas subarvores
  -- A profundidade (altura) de uma arvore binaria significa o nivel maximo de qualquer folha na Arvore
  -- Isso equivale ao tamanho do percurso mais distante da raiz ate a folha mais distante

--> Arvore binaria completa de produnidade eh a arvore estritamente binaria em que todas as folhas estejam no nivel D(FINAL)

-->Cada no tem dois ponteiros

-->Nao nulos só conta a das ARVORES

--> Dado uma arvore binaria completa, pode-se calcular o numero total de nos na ARVORES
Ex:arvore com altura 3 tem 7 Nos
nivel 1 --> 1 Nos
Nivel 2 --> 2 Nos
Nivel 3 --> 4 Nos
Ex:Se uma arvore binaria completem tem alruta h entao o numero de nos da arvore é dado;

2^x sendo x a altura


-->Enumerar em questao de largura(horizontalidade)
  --Se a altura da arvore eh D, cada no folha esta no nivel D ou nivel d-1
  --Em outra palvras a diferenca de altura entre as subarvore de qualquer no é no maximo 1
  --Se para cada no da arvore  com um descendente direito no nivel d , todos os descentes esquerdo de n que forem folhas estiverem
   tambem no nivel d
-->Importante para:
  --Sua alocacao em vetores pois quando é cheia nao desperdica espaco
  --HEAPSORT

TIPOS de implementacao

-- vetores(sequencial) MELHOR solucao quanda arvore for completa.se nao for completa um campo usado é necessario para indicar qual posicao tem ou
 nao elemento
-- Ponteiros(encadeaada dinamica) O limite par ao munero de nos eh a memoria disponivel

Comum as duas:
Filho esquerdo
Filho direito
Dado armazenado

Ambas as implementacoes podem ser GENERICAS

--Criacao,destruicao,verificar se esta vazia,impressao, tamanho
--inserir no como filho da direita,ou esquerda
--returnar raiz,ou folha
--retornar o filho da esqueda ou direita
--retornar o dado armazenado do no
--veririfiar se o dado esta ou nao na ARVORE

*/
arvore_t *arvore_cria(void){
  aloca meomoria par um nova armove
  if(memoria ok)
  inicializa como vazia
  retorna arvore_t
}
// destroi subarvore esquerda , depois direita , dps a raiz
void arvore_destroi(arvore_t **a){
  if(a eh valida)
  libera a memoria a
  faz *a apontar para NULL
}

int arvore_tamanho(arvore_t *a){
  if(a!=NULL){
    return(a->tamanho);
  }
  return(-1);
}
int arvore_vazia(node_t *n){}
if(n invalido)
retorna -1
if(n for folha)
return 1
}
tipo arvore_dado(node_t *n){
  if n valido
  return tipo de n
}
// inserir como filho esquerdo
/* insere um novo no como filho de um no conhecido e recebido como paramentro. o no deve ser folha ou ter apenas filho direito. nao insere se
o no recebido ja tiver um filho a esquerda
. se o no recebido ja tiver um filho esquerdo nao coloca

*/
int arvore_insere_esq(arvore_t*a,node_t *n,elemento_t elem){
  if(arvore invalida ou vazia e n valido)
}
int arvore_remove_esq(arvore_t *a,nodo_t *n){
  if(arvore invalida ou vazzia)
  return 0;
}
if(n invalido)
aux eh igual RAIZ
else aux eh igual ao filho esquerdo de "N"
if(aux eh valido)
arvore_remove_esq(a,aux)
arvore_remove_dir(a,aux)
destroi o no apontando por aux decrementa o tamaho da arvore
return 1

// direita eh basicamente  a mesma coisa se o aux for valido passa o direito para o aux


/* arvore com VETORES
no iesimo
Esquerdo 2i+1
Direito 2i+2
Considerando um no i , seu pai é:
piso((i-1)/2)

Percorrer a arvore binaria , visitando o no UMA unica vez
pre-ordem(percuso em profundidade)
in ordem(ordem simetrica)
pos ordem

*/
void arvore_pre_ordem(nodo_t *raiz){
  if(raiz_vazia)
  retorna
  visita no
  percorer em pre-ordem a subarvoe da esquerda
  percorrer em pre-ordem a subarvore da direita
}

pre_ordem(no* raiz){ // primeiro elemento eh sempre raiz 2 1 3 se para quem ta na direita e quem ta esquerda
  if(raiz==NULL)return;
  mosta_nodo(raiz); // visitando
  in_ordem(no_esq (raiz));
  in_ordem(no_dir (raiz));

}
in_ordem(no* raiz){ // ordenados 1 2 3
  if(raiz==NULL)return;
  in_ordem(no_esq (raiz));
  mosta_nodo(raiz); // visitando
  in_ordem(no_dir (raiz));
}
pos_ordem(no* raiz){
  if(raiz==NULL)return;
  in_ordem(no_esq (raiz));
  in_ordem(no_dir (raiz));
  mosta_nodo(raiz); // visitando 1 3 2 MELHOR abordagem para destruir de baixo para cima (nós folhas) raiz eh por utimo
}

//           2
//         1   3
/*
Facukudade ci qye a arvore permite traduzir a uma expressao nas formas pre-fixa,infixa,pos-fixa

Estudar processamento de expressoes
