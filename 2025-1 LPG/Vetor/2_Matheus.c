int main(int argc, char const *argv[])
{
    int tamanho = 5;

    int maior, menor;

    int array[tamanho - 1];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite um numero: ");
        scanf("%d", &array[i]);
    }

    for (int j = 0; j < tamanho; j++) {
        if (j == 0) {
            maior = array[j];
            menor = array[j];
        } else {
            if (array[j] > maior) {
                maior = array[j];
            }
            if (array[j] < menor) {
                menor = array[j];
            }
        }
    }

    printf("\nMaior: %d", maior);
    printf("\nMenor: %d", menor);

    return 0;
}
