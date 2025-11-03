int main(int argc, char const *argv[]) {

    int array[20];
    int pares = 0;

    for(int i = 0; i < 20; i++) {
        printf("Digite um numero: ");
        scanf("%d", &array[i]);
        if(array[i] % 2 == 0) {
            pares++;
        }
    }
    printf("Quantidade de numeros pares: %d\n", pares);
    return 0;
}
