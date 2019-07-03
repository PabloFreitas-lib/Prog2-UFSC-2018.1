/*
	Fazer com que elementos guarde ponteiros para um tipo
		tipo_elem **elementos;

	Passem a implementacao de tipo, para ponteiros void
		Ou seja, implementacao generica
		Usem como exemplo o arquivo de lista que ja esta
		no Moodle.

	Melhorem a função de impressao, esta feia:
		[Frente] e1, e2, ..., en [Fim]
*/


#include <stdio.h>
#include <stdlib.h>

typedef int tipo_elem;

typedef struct fila {
	int nelementos;
	int capacidade;
	int inicio;
	int fim;
	tipo_elem *elementos;
} fila_t;

fila_t* fila_cria(int c) {
	fila_t *f = (fila_t*) malloc(sizeof(fila_t));
	if (f == NULL) return NULL;
	f->nelementos = 0;
	f->capacidade = c;
	f->inicio = 0;
	f->fim = 0;
	f->elementos = (tipo_elem*) malloc(sizeof(tipo_elem)*c);
	if(f->elementos == NULL) {
		free(f);
		return NULL;
	}

	return f;
}

int fila_vazia(fila_t *f) {
	if (f == NULL) return -1;
	if (f->nelementos > 0) return 0;
	return 1;
}

int fila_cheia(fila_t *f) {
	if (f == NULL) return -1;
	if (f->nelementos == f->capacidade) return 1;
	return 0;
}

int fila_tamanho(fila_t *f) {
	if (f == NULL) return -1;
	return f->nelementos;
}

int fila_cabeca(fila_t *f, tipo_elem e) {
	if ((f == NULL) || (f->nelementos == 0)) {
		return -1;
	}
	e = f->elementos[f->inicio];
	return 1;
}

int fila_desenfileira(fila_t *f, tipo_elem *e) {
	if (f == NULL || fila_vazia(f)) {
		return 0;
	}
	*e = f->elementos[f->inicio];
	f->inicio = (f->inicio + 1) % f->capacidade;
	f->nelementos--;
	return 1;
}

int fila_enfileira(fila_t *f, tipo_elem e) {
	if (f == NULL || fila_cheia(f)) {
		return 0;
	}
	f->elementos[f->fim] = e;
	//f->fim = (f->fim + 1) % f->capacidade;
	f->fim += 1;
	if (f->fim == f->capacidade) f->fim = 0;
	f->nelementos++;
	return 1;
}

void fila_imprime(fila_t *f) {
	if(f == NULL) {
		printf("Fila non exciste.\n");
	} else {
		if (f->nelementos == 0) {
			printf("Fila esta vazia.\n");
		} else {
			for (int i=0; i < f->nelementos; i++) {
				printf("%d ", f->elementos[(f->inicio+i)%f->capacidade]);
			}
			printf("\n");
		}

	}
}

void fila_destroi(fila_t **f) {
	if (*f == NULL) return;
	if ((*f)->elementos != NULL) free((*f)->elementos);
	free(*f);
	*f = NULL;
}

int main() {
	fila_t *f = fila_cria(5);
	fila_imprime(f);
	fila_enfileira(f,0);
	fila_imprime(f);
	fila_enfileira(f,1);
	fila_imprime(f);
	fila_enfileira(f,2);
	fila_imprime(f);
	fila_enfileira(f,3);
	fila_imprime(f);
	fila_enfileira(f,4);
	fila_imprime(f);

	int valor;
	fila_desenfileira(f,&valor);

	printf("Desenfileirou %d.\n",valor);

	if(!fila_enfileira(f,5)) printf("Fila cheia\n");
	fila_imprime(f);

	fila_destroi(&f);

	return 0;
}
