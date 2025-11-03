#define LINHAS 2
#define COLUNAS 3

int main(int argc, char const *argv[])
{
    int matriz[LINHAS][COLUNAS];
    int soma = 0;

    for (int i=0; i < LINHAS;i++){
        for (int j=0; j < COLUNAS;j++){
            printf("Infome o elemento [%d][%d]\n->", i+1,j+1);
            scanf("%d", &matriz[i][j]);

            soma += matriz[i][j];
        }
    }

    for (int i=0; i < LINHAS;i++){
        for (int j=0; j < COLUNAS;j++){
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSoma dos elementos: %d", soma);

    return 0;
}
