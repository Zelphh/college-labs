int main(int argc, char const *argv[]) {   
    int array[9];

    for(int i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    for(int i = 10; i > 0; i--) {
        printf("%d ", array[i]);
    }

    return 0;
}
