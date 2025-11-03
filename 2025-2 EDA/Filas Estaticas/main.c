#include <stdio.h>
#include "Fila.h"

#define TAMANHO 20

int main() {

    int opcao;
    char input;
    char buuffer;

    Fila fila;
    alocar_fila(&fila);

    do {
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                scanf(" %c", &input);
                adicionar(&fila, input);

                break;
            case 2:
                printf("%c\n", remover(&fila));
                break;
            case 3:
                imprimir_inicio(&fila);
                break;
            case 4:
                imprimir_final(&fila);
                break;
            case 5:
                imprimir_fila(&fila);
                break;
            case 6:
                excluir_fila(&fila);
                break;
            default:
                break;
        }

    } while (opcao >= 1 && opcao <= 6);

    return 0;
}