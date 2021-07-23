#include<stdio.h>
#include "pilhaP.h"

void inicializarPilha(PILHA* pilha) {
	pilha->topo = NULL;
  pilha->length = 0;
  pilha->primeiroElem = &pilha->elementos[0];
}

void limpaPilha(PILHA* pilha) {
  pilha->length = 0;
	pilha->topo = NULL;
}

void imprimirPilha(PILHA* pilha) {
	printf("PILHA :)\n");

	for(int i = (length(pilha) - 1); i >= 0; i--)
		printf("|_%d_|\n", pilha->elementos[i].valor);
		
	printf("\n\n");
}

int pop(PILHA* pilha) {
	if(length(pilha) == 0) return 0;

  if (pilha->topo == &pilha->elementos[0]) pilha->topo = NULL;
  else pilha->topo -= 1;

  pilha->length--;

  return 1;
}

int push(PILHA* pilha, DOCUMENTO valor) {
	if(length(pilha) >= TAMANHO_MAXIMO) return 0;

  if (pilha->topo == NULL) pilha->topo = pilha->primeiroElem;
  else pilha->topo += 1;

	*pilha->topo = valor;

	pilha->length++;

	return 1;
}

int length(PILHA* pilha) {
	return pilha->length;
}
