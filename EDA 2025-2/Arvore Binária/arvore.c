#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"


Arvore *alocar(){
    Arvore *arv = (Arvore*) malloc(sizeof(Arvore));
    if(arv != NULL){
        arv->raiz = NULL;
    }
    return arv;
}

No *inserir(No *folha, int valor){
    if(folha == NULL){
        No *novo = (No*) malloc(sizeof(No));
        if(novo != NULL){
            novo->numero = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
            return novo;
        }
        return folha; 
    }

    if(valor < folha->numero){
        folha->esquerda = inserir(folha->esquerda, valor);
    } else if(valor > folha->numero){
        folha->direita = inserir(folha->direita, valor);
    }
    
    return folha;
}

int raiz(Arvore *arv){
    if(arv != NULL && arv->raiz != NULL){
        return arv->raiz->numero;
    }
    return -1; 
}

void folhas(No *folha){
    if(folha == NULL){
        return;
    }
    
    folhas(folha->esquerda);
    if(folha->esquerda == NULL && folha->direita == NULL){
        printf("%d ", folha->numero);
    }
    folhas(folha->direita);
}

void pre(No *folha){
    if(folha != NULL){
        printf("%d ", folha->numero);
        pre(folha->esquerda);
        pre(folha->direita);
    }
}

void em(No *folha){
    if(folha != NULL){
        em(folha->esquerda);
        printf("%d ", folha->numero);
        em(folha->direita);
    }
}

void pos(No *folha){
    if(folha != NULL){
        pos(folha->esquerda);
        pos(folha->direita);
        printf("%d ", folha->numero);
    }
}

void procurar(No *folha, int valor){
    if(folha == NULL){
        return;
    }

    if(valor == folha->numero){
        printf("%d\n", valor);
        return;
    }

    if(valor < folha->numero){
        procurar(folha->esquerda, valor);
    } else {
        procurar(folha->direita, valor);
    }
}

No *apagarFolha(No *folha, int valor){
    if(folha == NULL){
        return NULL;
    }

    if(valor < folha->numero){
        folha->esquerda = apagarFolha(folha->esquerda, valor);
    } else if(valor > folha->numero){
        folha->direita = apagarFolha(folha->direita, valor);
    } else {
        if(folha->esquerda == NULL && folha->direita == NULL){
            free(folha);
            return NULL;
        }
    }
    return folha;
}

int altura(No *folha){
    if(folha == NULL){
        return -1;
    } else {
        int h_esq = altura(folha->esquerda);
        int h_dir = altura(folha->direita);
        if(h_esq > h_dir){
            return h_esq + 1;
        } else {
            return h_dir + 1;
        }
    }
}

No *apagarTudo(No *folha){
    if(folha != NULL){
        folha->esquerda = apagarTudo(folha->esquerda);
        folha->direita = apagarTudo(folha->direita);
        free(folha);
    }
    return NULL;
}

void imprimir(No *folha, int nivel){
    if(folha == NULL){
        puts("");
        for (int i = 0; i < nivel; i++) printf("\t");
        printf("#\n");
    }else{
        imprimir(folha->direita, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("\t");
        printf("%d", folha->numero);
        imprimir(folha->esquerda, nivel + 1);
        
    }
}