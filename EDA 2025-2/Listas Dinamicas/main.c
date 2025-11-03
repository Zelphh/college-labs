#include <stdio.h>
#include "Lista.h"

int main() {

    int opcao;
    char input;
    int posicao;

    Lista lista = alocar_lista();

    do {
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                scanf(" %c", &input);
                incluir_inicio(&lista, input);
                break;
            case 2:
                remover_inicio(&lista, input) ;
                break;
            case 3:
                scanf(" %c", &input);
                incluir_final(&lista, input);
                break;
            case 4:
                remover_final(&lista, input);
                break;
            case 5:
                imprimir_inicio(&lista);
                break;
            case 6:
                imprimir_final(&lista);
                break;
            case 7:
                imprimir_lista(&lista);
                break;
            case 8:
                excluir_lista(&lista);
                break;
            case 9:
                scanf(" %d", &posicao);
                scanf(" %c", &input);
                incluir_posicao(&lista, input, posicao);
                break;
            case 10:
                scanf(" %d", &posicao);
                remover_posicao(&lista, posicao);
                break;
            case 11:
                scanf(" %c", &input);
                remover_primeira_ocorrencia(&lista, input);
                break;
            case 12:
                scanf(" %c", &input);
                remover_ultima_ocorrencia(&lista, input);
                break;
            default:
                break;
        }

    } while (opcao >= 1 && opcao <= 13);

    return 0;
}