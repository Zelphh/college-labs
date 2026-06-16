#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_operacoes_binaria(int v[], int target, int n) {
    int op = 0;
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        op++; 
        if (v[mid] == target) {
            op++;  
            return op;
        }

        op++;  
        if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return op; 
}

int main()
{
    int n = 100;
    int *v = (int *)malloc(n * sizeof(int));

    if (v == NULL) {
        printf("Falha na alocação de memória!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n; 
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    int target = rand() % n;

    printf("Número alvo: %d\n", target);

    v[n-1] = target;
    int operacoes_pior_caso = count_operacoes_binaria(v, target, n);
    printf("Pior caso (último índice): %d operações\n", operacoes_pior_caso);

    v[0] = target;
    int operacoes_melhor_caso = count_operacoes_binaria(v, target, n);
    printf("Melhor caso (primeiro índice): %d operações\n", operacoes_melhor_caso);

    v[n/2] = target;
    int operacoes_caso_medio = count_operacoes_binaria(v, target, n);
    printf("Caso médio (índice do meio): %d operações\n", operacoes_caso_medio);

    free(v);

    return 0;
}