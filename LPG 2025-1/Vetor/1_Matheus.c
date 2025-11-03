#include <stdio.h>

int main(int argc, char const *argv[])
{
    int tamanho = 5;
    float soma = 0;
    float media;

    float array[tamanho - 1];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite um numero: ");
        scanf("%f", &array[i]);
        soma += array[i];
    }

    media = soma / tamanho;

    printf("\nMedia: %.2f", media);

    return 0;
}
