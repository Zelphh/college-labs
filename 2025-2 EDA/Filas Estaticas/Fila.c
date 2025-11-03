#include <stdio.h>
#include "Fila.h"

#define TAMANHO 20

int alocar_fila(Fila *f) {
        f->inicio = 0;
        f->final = -1;
        f->quantidade = 0;
        return 1;
}

int adicionar(Fila *f, char input) {
    if(f->quantidade == TAMANHO) {
        printf("Fila cheia\n");
        return 1;
    }
    f->final += 1;
    f->dados[f->final] = input;
    f->quantidade += 1;
    return 0;
}

char remover(Fila *f) {
    if(f->quantidade == 0) {
        printf("Fila vazia\n");
        return 1;
    }
    char letra = f->dados[f->inicio];
    for (int i = 0; i < f->final; i++) {
        f->dados[i] = f->dados[i + 1];
    }
    f->final--;
    f->quantidade--;
    return letra;
}

int imprimir_inicio(Fila *f) {
    if (f->quantidade == 0) {
        printf("Fila vazia\n");
        return 1;
    }
    printf("%c\n", f->dados[f->inicio]);
    return 0;
}

int imprimir_final(Fila *f) {
    if (f->quantidade == 0) {
        printf("Fila vazia\n");
        return 1;
    }
    printf("%c\n", f->dados[f->final]);
    return 0;
}

int imprimir_fila(Fila *f) {
    if (f->quantidade == 0) {
        printf("Fila vazia\n");
        return 1;  
    }
    for (int i=f->inicio; i <= f->final; i++) {
        printf("%c ", f->dados[i]);
    }
    return 0;
}

int excluir_fila(Fila *f) {
    if (f->quantidade == 0) {
        printf("Fila vazia\n");
        return 1;
    }
    while (f->quantidade > 0) {
        remover(f);
    }
    return 0;
}




