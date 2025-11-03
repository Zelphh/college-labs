#include <stdio.h>

// Função que verifica se dois vetores são iguais
int verifica_vetores_iguais(int v1[], int v2[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (v1[i] != v2[i]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int tamanho;
    
    printf("Informe o tamanho dos vetores: ");
    scanf("%d", &tamanho);

    int v1[tamanho], v2[tamanho];

    printf("Informe os numeros do vetor 1:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &v1[i]);
    }

    printf("Digite os numeros do vetor 2:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &v2[i]);
    }

    printf("[1] Iguais [0] Diferentes: %d", verifica_vetores_iguais(v1, v2, tamanho));

    return 0;
}
