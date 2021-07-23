#include<stdio.h>
#include<malloc.h>
#include "fila.h"

void iniciarFila(struct FILA* f){
    f->head = NULL;
    f->tail = NULL;
}

void ADD(struct FILA* f, int valor){
    NODO* novo = (NODO*) malloc(sizeof(NODO));

    novo->valor = valor;
    novo->prox = NULL;
    
    if (f->head == NULL) f->head = novo;
    else f-> tail->prox = novo;

    f->tail = novo;
}

void REMOVE(struct FILA* f){
    if (f->head != NULL){
        NODO* apagar = f->head;

        f->head = apagar->prox;
        free(apagar);
        
        if (f->head == NULL)
            f->tail = NULL;
    }
}

void IMPRIMIR(struct FILA* f){
    NODO* imprimir = f->head;

    printf("Minha FILA >:c\n");
    printf("[Head] ___ \n");
    while (imprimir != NULL){
        printf("      |_%d_|\n", imprimir->valor);
        imprimir = imprimir->prox;
    }
    printf("\n");
}

void copiaInvertido (struct FILA* fila1, struct FILA* fila2) {
    if(fila1->head != NULL){
        NODO* filaAux = fila1->head;
        
        int aux = filaAux->valor;
        filaAux = fila1->head;
  
        fila1->head = fila1->head->prox;
        
        copiaInvertido(fila1, fila2);
        fila1->head = filaAux;
        ADD(fila2, aux);
    }
}
