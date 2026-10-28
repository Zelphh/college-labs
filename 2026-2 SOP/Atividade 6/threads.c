#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n;

void *contaCrescente(void *arg) {
    for (int i = 1; i <= n; i++) {
        printf("[Crescente] %d\n", i);
    }
    return NULL;
}

void *contaDecrescente(void *arg) {
    for (int i = n; i >= 1; i--) {
        printf("[Decrescente] %d\n", i);
    }
    return NULL;
}

int main(void) {
    pthread_t t1, t2;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    pthread_create(&t1, NULL, contaCrescente, NULL);
    pthread_create(&t2, NULL, contaDecrescente, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Contagens finalizadas.\n");

    return 0;
}