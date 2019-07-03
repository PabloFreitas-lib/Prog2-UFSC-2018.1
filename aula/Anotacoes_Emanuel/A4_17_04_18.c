//----//
/* Aula - Arquivos em C
-> Apresentar como funciona a manipulação de arquivos em C
-> Como abrir arquivos
-> Como ler e escrever em arquivos
-> Acessar arquivos de forma sequêncial e aleatória
-> O armazenamento de dados em variáveis e arrays é temporário -- esses dados são perdidos quando um programa é encerrado
-> Arquivos são usados na conservação permanente de dados
-> Os computadores armazenam arquivos em dispositivos secundários de armazenamento, epsecialmente dispositivos de armazenamento de disco
-> Para facilitar a recuperação dos dados de arquivos, pelo menos de um campo em cada registro é escolhido como chave
-> Por exemplo, em um arquivo que armazena a folha de pagamento de uma empresa, o número do CPF poderia ser usado como chave
-> Há duas maneiras principais de se organizar um arquivo
	-> Arquivo sequencial: normalmente os registros são armazenados em ordem segundo a chave de registros
	-> No exemplo anterior, os empregadores seriam organizados em ordem crescente do número do CPF
	-> Arquivo aleátorio: os registros possuem tamanho fixo
-> C vê cada arquivo como uma sequência de bytes
-> Cada arquivo termina com um marcador de fim de arquivo
-> Quando um arquivo é aberto, um stream (fluxo) é criado e associado àquele objeto
-> Três arquivos e seus respectivos fluxos são abertos automaticamente quando a execução de um programa inicia
	-> o de entrada (stdin)
	-> o de saída padrão (stdout)
	-> o de erro padrão (stderr)
-> Por exemplo o fluxo padrão de entrada permite que um programa leia dados do reclado e o fluxo oadrão de saída permite que um programa imprima
dados na tela
-> Abrir um arquivo retorna um ponteiro para uma estrutura FILE (definida em <stdio.h>), que contém informações isadas para processar o arquivo
-> Essa estrutura tem várias informações sobre o arquivo, incluindo a posição de leitura atual
-> Assim como o 'scanf' e 'printf', existem as versões dessas funções para arquivos: 'fscanf' e 'fprintf'
-> Porém, um arquivos deve ser aberto antes da sua escrita ou leitura, através da função 'fopen'
*/
	FILE * file = fopen("./arq.txt", "r");
	//Fique atento ao caminho usado para abrir o arquivo
/*
-> O primeiro argumento é o nome do arquivo e o segundo é o modo de abertura
	-> Nome relativo: Relacionado a aonde o programa está sendo executado // Exp: ../bin/aqr.txt
	-> Nome absoluto: Desde a base (raiz) até o arquivo // Exp: /home/ufsc/Docs/t2/arq.txt
	-> "r" para leitura
	-> "w" para escrita
	-> "r+" ou "w+" para leitura e escrita
	-> "a" para adicionar em um arquivo existente
-> Caso o arquivo não puder ser aberto, o retorno é NULL
-> 'feof(ponteiro_arquivo)' - retorna positivo caso seja final do arquivo
-> 'fclose(ponteiro_arquivo)' - fecha o arquivo
-> 'fprint(ponteiro_arquivo, "%d %f\n", a, f);' - escreve 'a' (inteiro) e 'f' (float) no arquivo
-> É fundamental fechar o arquivo após o seu uso, com o perifo de perder dados que foram supostamente escritos
-> O exemplo anterior não mostra como arquivo clients.dat ficou gravado, apenas realliza a escrita dos dados no arquivo e depois fecha o arquivo
-> 'fflush(ptr_arq)' - Esvazia os valores da memória e os leva para o arquivo sem necessidade de fecha-lo
-> O ponteiro da posição do arquivo sempre camnha para frente, ao menos que uma função para voltar ao início seja executada
-> 'rewind(ponteiro_arquivo)' - faz com que o ponteiro da posição do arquivo - que indica o número do próximo byte a ser lido ou gravado no arquivo,
 - seja reposicionado para o inicio do arquivo (ou seja, para o byte 0) apontando por ponteiro arquivo
-> A linguagem não impõe estrutura a um arquivo. Assim, noções como um registro de um arquivo não existem como parte da lingugagem C
-> Os registros em um arquivo cirado com a função de saída formatado 'fprintf' não possuem necessariamente o mesmo tamanho
-> Lembre-se que os arquivos são organizados de forma sequencial
-> Se o nome de uma pessoa no nosso exemplo tivesse que ser reescrito com um número diferente de caracteres, o que aconteceria no arquivo?
-> Normalmente os registros d um arquivo de acesso aleatório possuem o mesmo tamanho e podem ser acessados diretamente (e, dessa forma, rapidamente)
sem passar por outros registros
-> Isso faz com que os arquivos de acessoa aleatórios sejam apropriados para sistemas de reservas de vôos, sistemas de bancos,
sistemas de ponto de vendas e outros tipos de sistemas de processamento de transições que exigem acesso rápido a dados específicos
-> Como todos os registros de um arquivo de acesso aleatório normalmente possuem o mesmo conjunto,
a localização exata de um registro relativo ao inicio do arquivo pode ser calculada como uma função da chave de registros
-> Os dados podem ser inseridos em um arquivo de acesso aleatŕoio sem que sejam destruídos outros dados no arquivo
-> Duas funções principais:
	-> 'fwrite' - transfere para um arquivo em número especificado de bytes, iniciando em um determinado local da memória
	-> 'fread' - transfere um número determinado de bytes de um local específico da memória, deficindo pelo ponteiro de posição do arquivo,
	 para uma área da memória, iniciando em um endereço indicado
-> Vamos comparar a escrita de um inteiro com 'fwrite' e 'fprintf'
*/
fprintf(fPtr, "%d", numero);
//Poderia imprimir o mínimo de 1 dígito ou o máximo de 11 digitos (10 digitos mais um sinal, exigindo cada um deles, um byte de armazenamento)
fwrite(&numero, sizeof(int), 1, fPtr);
//Sempre grava 4 bytes da variável 'numero' no arquivo apontado por fPtr
//Dica: Usem as páginas de manuais do Linux sempre que tiverem dúvida sobre uma função: man fwrite
/*
-> A função fread lê um número especificado de bytes de um arquivo de memória. Por exemplo a instrução:
*/ fread(&cliente, sizeof(struct dadosCliente), 1, cfPtr);
/*
-> Lê o número de bytes determinado por 'sizeof(struct dadosCliente)' do arquivos referenciado 'cfPtr' e armazena os dados na estrutura 'cliente'
-> Os bytes são lidos do local no arquivo especificado pelo ponteiro de posição do arquivo
-> A função fread pode ser usada para ler vários elementos com tamanho fixo, de um array, fornecendo um ponteiro para o array no qual os elementos
 serão armazenados e indicando o número de elementos a ser lido
-> Embora 'fread' e 'fwrite' leiam e gravem dados como inteiros em um formato de tamanho fixo, em vez de tamanho variável, os dados que
 eles manipulam são processados no formato de "dados computacionais brutos" (i.e. bytes de dados) e não no formato de leitura humana proporcionado por
  'printf' e 'scanf'
-> Esse tipo de formatação nos arquivos aleatórios também é chamada de arquivos binários

-> Permite reposivionar o ponteiro de um arquivo para uma posição
*/ int fseek(FILE *ptr, int bytes, int origem);
/*
-> Onde 'bytes' é o número de bytes a ser buscado a partir do local origem no arquivo apontado por 'ptr'
-> O argumento origem pode ter um dentre três valores - SEEK_SET, SEEK_CUR ou SEEK_END (todos definidos em <stdio.h> - indicando o local no arquivo
onde a busca começa
-> Ler a posição 235 do arquivo teste
*/
FILE *fp;
char ch;
if((fp = fopen("./teste", "r")) == NULL){
	puts("Não posso abrir o arquivo!");
	exit(1);
}
fseek(fp, 235, SEEK_SET);
ch = getc(fp); // lê um caractere na posição 235
/*
