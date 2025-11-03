int main(int argc, char const *argv[]) {

    int array[10];
    int n, encontrado = 0;

    for(int i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &array[i]);
    }

    printf("\nInfome um numero apra procurar no array: ");
    scanf("%d", &n);

    for(int i = 0; i < 10; i++) {
        if(array[i] == n) {
            printf("Numero esta na posicao %d\n", i+1);
            encontrado = 1;
        }
    }

    if(!encontrado) {
        printf("Numero nao encontrado no array\n");
    }

    return 0;
}
