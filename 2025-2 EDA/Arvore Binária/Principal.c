#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){
    int opcao;
    int sair=1;
    int valor;
    
    Arvore *arv1 = alocar();
    
    do{
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                scanf("%d", &valor);
                arv1->raiz = inserir(arv1->raiz, valor);
                break;
            case 2:
                scanf("%d", &valor);
                procurar(arv1->raiz, valor);
                break;
            case 3:
                scanf("%d", &valor);
                arv1->raiz = apagarFolha(arv1->raiz, valor);
                break;
            case 4:
                pre(arv1->raiz);
                printf("\n");
                break;
            case 5:
                em(arv1->raiz);
                printf("\n");
                break;
            case 6:
                pos(arv1->raiz);
                printf("\n");
                break;
            case 7:
                if(arv1->raiz != NULL) {
                    printf("%d\n", raiz(arv1));
                }
                break;
            case 8:
                folhas(arv1->raiz);
                printf("\n");
                break;
            case 9:
                printf("%d\n", altura(arv1->raiz));
                break;
            case 10:
                arv1->raiz = apagarTudo(arv1->raiz);
                break;
            case 11:
                if(arv1->raiz != NULL)  imprimir(arv1->raiz, 0);
                break;
            default:
                sair=0;
                break;
        }
    }while(sair);
    
    arv1->raiz = apagarTudo(arv1->raiz);
    free(arv1);
    
    return 0;   
}