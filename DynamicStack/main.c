// This a dynamic stack.
// 

#include<stdio.h>
#include "pilhaP.h"

int main () {
	PILHA minhaPilha;

	inicializarPilha(&minhaPilha);
	
  DOCUMENTO doc1;
  doc1.valor = 2;
  DOCUMENTO doc2;
  doc2.valor = 4;
  DOCUMENTO doc3;
  doc3.valor = 6;

	push(&minhaPilha, doc1);
	push(&minhaPilha, doc2);
	push(&minhaPilha, doc3);
	
	//imprimirPilha(&minhaPilha);

	pop(&minhaPilha);
  pop(&minhaPilha);
	
	//imprimirPilha(&minhaPilha);
	
	imprimirPilha(&minhaPilha);
	
}
