int main(int argc, char const *argv[]) {
    int vA[10], vB[10];

    for(int i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &vA[i]);
    }

    printf("\n");

    for(int i = 0; i < 10; i++) {
        vB[i] = vA[9 - i];
        printf("%d ", vB[i]);
    }

    return 0;
}
