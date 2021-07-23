#include<stdio.h>
#include<malloc.h>
#include "lista.h"

void iniciarLista (LISTA* l) {
	l->inicio = NULL;
	l->fim = NULL;
}

void reiniciarLista (LISTA* l) {
	NODO* aux = l->inicio;
	
  while (aux != NULL) {
		NODO* apagar = aux;		
		aux = aux->prox;
		
		free(apagar);
	}
	
	iniciarLista(l);
}

int tamanho(LISTA* l) {
	NODO* aux = l->inicio;
	int tam = 0;
	
	while (aux != NULL) {
		tam++;
		aux = aux->prox;
	}
	
	return tam;
}

void printLista(LISTA* l) {
	NODO* imprimir = l->inicio;

    printf("LISTA >:c\n");
    printf("[INICIO] ");

    while (imprimir != NULL){
        printf("|_%d_|", imprimir->valor);
        imprimir = imprimir->prox;
    }

    printf("\n");
}

void inserir(LISTA* l, int valor) {
	NODO* novo = (NODO*) malloc(sizeof(NODO));
	
	novo->valor = valor;
	novo->prox = NULL;
	
	if(l->inicio == NULL) l->inicio = novo;
	else l->fim->prox = novo;
	
	l->fim = novo;
}

void inserirPos(LISTA* l, int posicao, int valor){
  NODO* aux = l->inicio;
  
  int contarTamanho;
  contarTamanho = tamanho(l);
	
  if(l->inicio == NULL) printf("LISTA VAZIA!\n");
  else if (contarTamanho < posicao || posicao <= 0) printf("ESPAÇO INSUFICIENTE OU POSIÇÃO INVÁLIDA!\n");
  else{
    for(int i = 1 ; i < posicao ; i++){
      aux = aux->prox; 
    }

    aux->valor = valor;
  } 
}

void remover(LISTA* l) {
  NODO* aux = l->inicio;
	
  if (l->inicio == NULL) return;

  if (l->inicio->prox == NULL) {
    free(l->inicio);

    l->inicio = NULL;
    l->fim = NULL;

  } else {
    while (aux != NULL) {
      if (aux->prox->prox == NULL) {
        free(aux->prox);
        aux->prox = NULL;
        l->fim = aux;
      }

		  aux = aux->prox;
	  }
  }

}
 
void removerVal(LISTA* l, int valor){
  NODO* aux = l->inicio;      
  NODO* auxFinal = NULL;
	
  int sinal = 0;

  if(l->inicio == NULL){
    printf("LISTA VAZIA!\n");
    return;
  }
 
  while(aux != NULL){
    if(aux->valor != valor) aux = aux->prox;
    else{
      auxFinal = aux;
      aux = NULL;
      
      sinal = 1;
    }
  }
  
  aux = auxFinal;

  if(sinal != 1) printf("VALOR NÃO ENCONTRADO!\n");
    else{
      while(aux->prox != NULL){
        aux->valor = aux->prox->valor;
        aux->prox->valor = auxFinal->valor;  
         
        aux = aux->prox;
    }
    remover(l);
  }
}