int main(int argc, char const *argv[])
{
    int tamanho = 5;

    float media;
    int soma = 0, count = 0;

    int array[tamanho - 1];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite um numero: ");
        scanf("%d", &array[i]);

        soma += array[i];
    }

    media = soma / tamanho;

    printf("\nMedia: %.2f", media);

    printf("\nNumeros acima da media: ");

    for (int i = 0; i < tamanho; i++) {
        if (array[i] > media) {
            printf("%d ", array[i]);
            count++;
        }
    }

    printf("\n\nUm total de %d numeros acima da media", count);

    return 0;
}
