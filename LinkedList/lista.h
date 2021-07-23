#ifndef LISTA_H
#define LISTA_H

typedef struct node {
	int valor;
	struct node* prox;
} NODO;

typedef struct {
	NODO* inicio;
	NODO* fim;
} LISTA;

void iniciarLista (LISTA* l);
void reiniciarLista (LISTA* l);
int tamanho(LISTA* l);
void printLista(LISTA* l);
void inserir(LISTA* l, int valor);
void inserirPos(LISTA* l, int posicao, int valor);
void remover(LISTA* l);
void removerVal(LISTA* l, int valor);


#endif /*LISTA_H*/
