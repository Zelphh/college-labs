#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha* pilha = criar_pilha();
    int opcao;
    char letra;

    while (1) {
        scanf("%d", &opcao);

        if (opcao < 1 || opcao > 5) {
            break;
        }

        switch (opcao) {
            case 1:
                scanf(" %c", &letra);
                incluir(pilha, letra);
                break;
            case 2:
                excluir(pilha);
                break;
            case 3:
                imprimir_topo(pilha);
                break;
            case 4:
                imprimir_tudo(pilha);
                break;
            case 5:
                excluir_tudo(pilha);
                break;
        }
    }
    
    excluir_tudo(pilha);
    free(pilha);

    return 0;
}