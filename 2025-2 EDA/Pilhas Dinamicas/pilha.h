#ifndef PILHA_H
#define PILHA_H

#include "no.h"

typedef struct Pilha {
    No* topo;
} Pilha;

Pilha* criar_pilha();
void incluir(Pilha* pilha, char letra);
void excluir(Pilha* pilha);
void imprimir_topo(Pilha* pilha);
void imprimir_tudo(Pilha* pilha);
void excluir_tudo(Pilha* pilha);

#endif