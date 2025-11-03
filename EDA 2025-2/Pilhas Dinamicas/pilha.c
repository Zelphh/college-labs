#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->topo = NULL;
    }
    return pilha;
}

void incluir(Pilha* pilha, char letra) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no != NULL) {
        novo_no->dado = letra;
        novo_no->proximo = pilha->topo;
        pilha->topo = novo_no;
    }
}

void excluir(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    }
    No* temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);
}

void imprimir_topo(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    }
    printf("%c\n", pilha->topo->dado);
}

void imprimir_tudo(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    }
    No* atual = pilha->topo;
    while (atual != NULL) {
        printf("%c\n", atual->dado);
        atual = atual->proximo;
    }
}

void excluir_tudo(Pilha* pilha) {
    No* atual = pilha->topo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    pilha->topo = NULL;
}