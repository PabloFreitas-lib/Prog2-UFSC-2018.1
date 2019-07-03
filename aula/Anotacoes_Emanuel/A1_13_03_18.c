-> Ponteiros são variáveis cujos valores são endereços de memória;
-> Um ponteiro contém um endereço de uma variável que contém um valor;
-> Um nome de variável referencia um valor diretamente, um ponteiro referencia um valor indiretamente;
E->Variáveis do tipo int dispoem de 4 bytes, usando apenas 31 bits ao invés de 32, uma vez que 1 bit é usado para o sinal, diferente da unsigned int;
S-> Indireção, ponteiros. Pesquisar.
-> Processadores de 32 bits comportam ponteiros de 4 bytes, bem como os de 64 comportam de 8 bytes;
-> int *countPtr, onde a variável 'countPtr' é um ponteiro para um inteiro;
-> É possível definir um ponteiro para qualquer tipo de variável;
-> Um ponteiro pode ser definido para qualquer coisa, isso é, um ponteiro de 'void';
-> Um ponteiro pode ser iniciado com 'NULL', '0', ou um endereço;
-> Um ponteiro de valor NULL não aponta, teoricamente, para nada;
-> NULL é uma constante definida em <stddef.h> ou <stdlib.h>;
-> Inicializar em '0' é equivalente a inicializar com 'NULL', porém com 'NULL' é mais eficiente;
-> O '&' é um operador unário que retorna o endereço de seu operando;
-> Por exemplo:
   int y = 5;
   int *yPtr;
   yPtr = &y;
   A sequência de instruções atribuem o endereço da variável 'y' ao ponteiro 'yPtr'. Sendo assim, a variável 'yPtr' aponta para 'y';
-> Sempre busque inicializar uma ponteiro, uma vez que do contrario ele estará portando lixo;
-> O operador de endereço só pode ser aplicado a variável e não a constantes ou expressões;
-> O operador '*' retorna o valor do objeto apontado por seu operador (um ponteiro);
   Por exemplo:
   printf("%d", *yPtr);
   A instrução irá imprimir o valor da variável 'y', no caso 5;
-> %p imprime o endereço da variável;
   Por exemplo:
   printf("%p", &y); ou printf("%p", yPtr);
->
