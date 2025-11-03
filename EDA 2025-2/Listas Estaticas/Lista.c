#include <stdio.h>
#include "Lista.h"

#define TAMANHO 20

Lista alocar_lista(){
    Lista l;
    l.qtd = 0;
    return l;
}

int incluir_inicio(Lista *l, int valor){
    if(l->qtd == TAMANHO){
        printf("Lista cheia\n");
        return 1;
    }
    for(int i = l->qtd; i > 0; i--){
        l->dados[i] = l->dados[i-1];
    }
    l->dados[0] = valor;
    l->qtd++;
    return 0;
}

char remover_inicio(Lista *l, int valor){
    if(l->qtd == 0){
        printf("Lista vazia\n");
        return 1;
    }
    for(int i = 0; i < l->qtd - 1; i++){
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;
    return 0;
}

int incluir_final(Lista *l, int valor){
    if(l->qtd == TAMANHO){
        printf("Lista cheia\n");
        return 1;
    }
    l->dados[l->qtd] = valor;
    l->qtd++;
    return 0;
}

char remover_final(Lista *l, int valor){
    if(l->qtd == 0){
        printf("Lista vazia\n");
        return 1;
    }
    l->qtd--;
    return 0;
}

int imprimir_inicio(Lista *l){
    if(l->qtd == 0){
        printf("Lista vazia\n");
        return 1;
    }
    printf("%c\n", l->dados[0]);
    return 0;
}

int imprimir_final(Lista *l){
    if(l->qtd == 0){
        printf("Lista vazia\n");
        return 1;
    }
    printf("%c\n", l->dados[l->qtd - 1]);
    return 0;
}

int imprimir_lista(Lista *l){
    if(l->qtd == 0){
        printf("Lista vazia\n");
        return 1;
    }
    for(int i = 0; i < l->qtd; i++){
        printf("%c ", l->dados[i]);
    }
    printf("\n");
    return 0;
}

int excluir_lista(Lista *l){
    l->qtd = 0;
    return 0;
}

int incluir_posicao(Lista *l, int valor, int posicao){
    if(l->qtd == TAMANHO){
        printf("Lista cheia\n");
        return 1;
    }
    if(posicao < 0 || posicao > l->qtd){
        printf("Posicao invalida\n");
        return 1;
    }
    for(int i = l->qtd; i > posicao; i--){
        l->dados[i] = l->dados[i-1];
    }
    l->dados[posicao] = valor;
    l->qtd++;
    return 0;
}

char remover_posicao(Lista *l, int posicao){
    if(l->qtd == 0){
        printf("Lista vazia\n");
        return 1;
    }
    if(posicao < 0 || posicao >= l->qtd){
        printf("Posicao invalida\n");
        return 1;
    }
    for(int i = posicao; i < l->qtd - 1; i++){
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;
    return 0;
}

char remover_primeira_ocorrencia(Lista *l, int valor){
    if(l->qtd == 0){
        printf("Lista vazia\n");
        return 1;
    }
    for(int i = 0; i < l->qtd; i++){
        if(l->dados[i] == valor){
            for(int j = i; j < l->qtd - 1; j++){
                l->dados[j] = l->dados[j+1];
            }
            l->qtd--;
            return 0;
        }
    }
    printf("Valor nao encontrado\n");
    return 1;
}

char remover_ultima_ocorrencia(Lista *l, int valor){
    if(l->qtd == 0){
        printf("Lista vazia\n");
        return 1;
    }
    for(int i = l->qtd - 1; i >= 0; i--){
        if(l->dados[i] == valor){
            for(int j = i; j < l->qtd - 1; j++){
                l->dados[j] = l->dados[j+1];
            }
            l->qtd--;
            return 0;
        }
    }
    printf("Valor nao encontrado\n");
    return 1;
}