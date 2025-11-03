#define LINHAS 3
#define COLUNAS 3

int main(int argc, char const *argv[])
{
    int matriz[LINHAS][COLUNAS];
    int escolha;

    for (int i=0; i < LINHAS;i++){
        for (int j=0; j < COLUNAS;j++){
            printf("Infome o elemento [%d][%d] \n-> ", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Selecione uma linha da matriz: \n-> ");
    scanf("%d", &escolha);

    for (int i=0; i < LINHAS;i++){
        for (int j=0; j < COLUNAS;j++){
            if (i = escolha-1) {
                printf("[%d] ", matriz[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
