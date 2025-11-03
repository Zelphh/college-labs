#include <stdio.h>

int soma_matriz(int matriz[2][2]) {
    int i, j, sum = 0;    
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            sum += matriz[i][j];
        }
        
    }
    return sum;
}

int main() {
    int matriz[2][2];
    int i, j;

    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            printf("informe o valor de [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
        
    }
    
    printf("Soma da matriz=  %d", soma_matriz(matriz));

    return 0;
}