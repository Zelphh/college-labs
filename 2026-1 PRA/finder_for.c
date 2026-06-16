#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_operacoes(int v[], int target, int n) {
    int op = 0;
    for (int i = 0; i < n; i++) {
        op++;
        if (v[i] == target) {
            op++;
            return op; 
        }
        op++;
    }
    return op;
}

int main()
{
    int n = 1000;
    int *v = (int *)malloc(n * sizeof(int));

    if (v == NULL) {
        printf("Falha na alocação de memória!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % n; 
    }

    int target = rand() % n;

    printf("Número alvo: %d\n", target);

    v[n-1] = target;
    int operacoes_pior_caso = count_operacoes(v, target, n);
    printf("Pior caso (último índice): %d operações\n", operacoes_pior_caso);

    v[0] = target;
    int operacoes_melhor_caso = count_operacoes(v, target, n);
    printf("Melhor caso (primeiro índice): %d operações\n", operacoes_melhor_caso);

    v[n/2] = target;
    int operacoes_caso_medio = count_operacoes(v, target, n);
    printf("Caso médio (índice do meio): %d operações\n", operacoes_caso_medio);

    free(v);

    return 0;
}