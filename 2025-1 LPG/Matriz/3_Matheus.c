#define LINHAS 4
#define COLUNAS 4

int main(int argc, char const *argv[])
{
    int matriz[LINHAS][COLUNAS];
    int soma_linhas_pares = 0, soma_linh2 = 0;
    int maior, menor;

    int diagonal_principal[COLUNAS];

    for (int i=0; i < LINHAS;i++){
        for (int j=0; j < COLUNAS;j++){
            printf("Infome o elemento [%d][%d]\n->", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i=0; i < LINHAS;i++){
        for (int j=0; j < COLUNAS;j++){
            if (i+1 % 2 == 0) {
                soma_linhas_pares += matriz[i][j];
            }

            if (i+1 == 2) {
                soma_linh2 += matriz[i][j];
            }

            if (i == j) {
                diagonal_principal[i] = matriz[i][j];
            }

            if (i==0 && j==0) {
                maior = matriz[i][j];
                menor = matriz[i][j];
            } else {
                if (matriz[i][j] > maior) {maior = matriz[i][j];}
                if (matriz[i][j] < menor) {menor = matriz[i][j];}
            }
        }
    }

    printf("Soma dos elementos nas linhas pares: %d\n", soma_linhas_pares);
    printf("Primeiro valor: %d\n", matriz[0][0]);
    printf("U valor: %d\n", matriz[LINHAS-1][COLUNAS-1]);
    printf("Soma da linha 2: %d\n", soma_linh2);

    printf("Diagonal principal: ");
    for (int i=0;i<COLUNAS;i++) {
        printf("%d ", diagonal_principal[i]);
    }

    printf("\nMaior numero: %d\n", maior);
    printf("Menor numero: %d\n", menor);

    return 0;
}
