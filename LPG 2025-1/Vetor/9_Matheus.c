int main(int argc, char const *argv[]) {
    int vA[5], vB[5], vC[10];
    int i, j = 0;

    for(i = 0; i < 5; i++) {
        printf("Digite um numero [A]: ");
        scanf("%d", &vA[i]);
    }

    printf("\n");

    for(i = 0; i < 5; i++) {
        printf("Digite um numero [B]: ");
        scanf("%d", &vB[i]);
    }

    for(i = 0; i < 5; i++) {
        vC[j++] = vA[i];
        vC[j++] = vB[i];
    }

    printf("\n");

    for(i = 0; i < 10; i++) {
        printf("%d ", vC[i]);
    }

    printf("\n");
    return 0;
}
