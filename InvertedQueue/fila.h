#ifndef FILA_H
#define FILA_H

typedef struct nodo
{
    int valor;
    struct nodo* prox;
} NODO;

struct FILA
{
    NODO* head;
    NODO* tail;
};

void iniciarFila(struct FILA* f);
void ADD(struct FILA* f, int valor);
void REMOVE(struct FILA* f);
void IMPRIMIR(struct FILA* f);
void copiaInvertido (struct FILA* fila1, struct FILA* fila2);

#endif /*FILAINVERSA_H*/
