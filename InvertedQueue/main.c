// This is an inverted queue made for a college college activity.
// Has a function that reverses the queue recursively  

#include <stdio.h>
#include<malloc.h>
#include"fila.h"

int main(void) {
    struct FILA fila1;
    struct FILA fila2;

    iniciarFila(&fila1);

    ADD(&fila1, 1);
    ADD(&fila1, 2);
    ADD(&fila1, 3);
    ADD(&fila1, 4);
    //REMOVE(&fila1);
    ADD(&fila1, 5);
    ADD(&fila1, 6);
    REMOVE(&fila1);
    //ADD(&fila1, 7);

    printf("Fila Normal: ");
    IMPRIMIR(&fila1);

    printf("Fila Invertida: ");
    IMPRIMIR(&fila2);
    
    copiaInvertido(&fila1, &fila2);
    printf("\nInvertendo a Fila... \n\n\n");
    
    printf("Fila Normal: ");
    IMPRIMIR(&fila1);
    
    printf("Fila Invertida: ");
    IMPRIMIR(&fila2);

  return 0;
}