typedef struct Registro{
    int numero;
    struct Registro *esquerda;
    struct Registro *direita;
}No;


typedef struct Estrutura{
    No *raiz; 
}Arvore;

Arvore *alocar();

No *inserir(No *folha, int valor);

int raiz(Arvore *arv);

void folhas(No *folha);

void pre(No *folha);

void em(No *folha);

void pos(No *folha);

void procurar(No *folha, int valor);

No *apagarFolha(No *folha, int valor);

int altura(No *folha);

No *apagarTudo(No *folha);

void imprimir(No *folha, int nivel);