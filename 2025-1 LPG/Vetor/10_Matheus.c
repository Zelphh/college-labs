int main(int argc, char const *argv[]) {
    int array[20];
    int numero, count = 0;

    for(int i = 0; i < 20; i++) {
        printf("Digite um numero: ");
        scanf("%d", &array[i]);
    }

    printf("\nDigite um numero para ver quantas vezes ele apareceu no array: ");
    scanf("%d", &numero);

    for(int i = 0; i < 20; i++) {
        if(array[i] == numero) {
            count++;
        }
    }

    printf("\nEsse numero apareceu %d vezes\n", count);
    return 0;
}
