#ifndef PILHAP_H
#define PILHAP_H

#define TAMANHO_MAXIMO 10

typedef struct {
  int valor;
} DOCUMENTO;

typedef struct {
	DOCUMENTO elementos[TAMANHO_MAXIMO];
	DOCUMENTO* topo;
  DOCUMENTO* primeiroElem;
  int length;
} PILHA;

void inicializarPilha(PILHA* pilha);
void limpaPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);
int push(PILHA* pilha, DOCUMENTO valor);
int pop(PILHA* pilha);
int length(PILHA* pilha);


#endif /*PILHAP_H*/
