// This code can INSERT and REMOVE any value in the list:

// To explain what i did to "RemoveVal()" an expecific value:
// I took the chosen number and moved him in the place of the next number until reached to the end of the list. 
// When the chosen number is in the end, "remove()" is called and remove him.
// "Remove()" always remove the last value of the list.

// To "InsertPos()":
// I use a loop to encounter the first value asked, after that the code has the same behavior of the "RemoveVal()"

#include<stdio.h>
#include<malloc.h>
#include"lista.h"

int main() {
	LISTA lista;
	NODO *LISTA = NULL;

	iniciarLista(&lista);

	inserir(&lista, 21);
	inserir(&lista, 22);
	inserir(&lista, 23);
  inserir(&lista, 24);

  removerVal(&lista, 26);

  //inserirPos(&lista, 4, 22);

  //remover(&lista);

  printLista(&lista);
}