#define TAMANHO 20

typedef struct Estrutura Fila;
    
struct Estrutura {
    int dados[TAMANHO];
    int inicio;
    int final;
    int quantidade;
};

int alocar_fila(Fila *f);

int adicionar(Fila *f, char input);

char remover(Fila *f);

int imprimir_inicio(Fila *f);

int imprimir_final(Fila *f);

int imprimir_fila(Fila *f);

int excluir_fila(Fila *f);