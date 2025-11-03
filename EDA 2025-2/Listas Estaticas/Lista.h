#define TAMANHO 20

typedef struct Estrutura Lista;

struct Estrutura {
    char dados[TAMANHO];
    int qtd;
};

Lista alocar_lista();

int incluir_inicio(Lista *l, int valor);

char remover_inicio(Lista *l, int valor);

int incluir_final(Lista *l, int valor);

char remover_final(Lista *l, int valor);

int imprimir_inicio(Lista *l);

int imprimir_final(Lista *l);

int imprimir_lista(Lista *l);

int excluir_lista(Lista *l);

int incluir_posicao(Lista *l, int valor, int posicao);

char remover_posicao(Lista *l, int posicao);

char remover_primeira_ocorrencia(Lista *l, int valor);

char remover_ultima_ocorrencia(Lista *l, int valor);


