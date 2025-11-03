int main(int argc, char const *argv[]) {
    int vA[5], vB[5], vC[5];

    for(int i = 0; i < 5; i++) {
        printf("A[%d]: ", i+1);
        scanf("%d", &vA[i]);
    }

    printf("\n");

    for(int i = 0; i < 5; i++) {
        printf("B[%d]: ", i+1);
        scanf("%d", &vB[i]);
    }

    for(int i = 0; i < 5; i++) {
        vC[i] = vA[i] + vB[i];
    }


    printf("\n");

    for(int i = 0; i < 5; i++) {
        printf("C[%d] = %d\n", i+1, vC[i]);
    }

    return 0;
}
