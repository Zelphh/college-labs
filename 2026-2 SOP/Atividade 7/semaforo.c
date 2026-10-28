#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define CAP 10
#define NUM_THREADS 4
#define ITERACOES 5

int fila[CAP];
int ini = 0;
int tam = 0;
sem_t mutex;

void enfileira(int v) {
    fila[(ini + tam) % CAP] = v;
    tam++;
}

int desenfileira(void) {
    int v = fila[ini];
    ini = (ini + 1) % CAP;
    tam--;
    return v;
}

void *tarefa(void *arg) {
    int id = *(int *)arg;
    for (int i = 0; i < ITERACOES; i++) {
        sem_wait(&mutex);
        int saiu = desenfileira();
        int entrou = rand() % 100;
        enfileira(entrou);
        printf("thread %d: tira %2d, poe %2d, fila:", id, saiu, entrou);
        for (int j = 0; j < tam; j++)
            printf(" %2d", fila[(ini + j) % CAP]);
        printf("\n");
        sem_post(&mutex);
    }
    return NULL;
}

int main(void) {
    pthread_t th[NUM_THREADS];
    int ids[NUM_THREADS];

    srand(time(NULL));
    for (int i = 0; i < CAP; i++)
        enfileira(rand() % 100);

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i + 1;
        pthread_create(&th[i], NULL, tarefa, &ids[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(th[i], NULL);

    sem_destroy(&mutex);
    return 0;
}