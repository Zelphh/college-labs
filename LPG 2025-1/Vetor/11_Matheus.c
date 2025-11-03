int main(int argc, char const *argv[]) {
    int array[15];
    int soma = 0;

    for(int i = 0; i < 15; i++) {
        printf("Digite um numero: ");
        scanf("%d", &array[i]);
    }

    for(int i = 1; i < 15; i += 2) {
        soma += array[i];
    }

    printf("Soma dos numeros em posicoes impares: %d\n", soma);
    return 0;
}
