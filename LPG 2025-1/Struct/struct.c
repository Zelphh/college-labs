#include <string.h>
#include <stdlib.h>

#define TAMANHO 2

typedef struct {
    
    char cpf[12];
    char nome[50];
    int idade;
    char disciplinas[2][6];

} Aluno;

void mostrar_alunos(Aluno *alunos, int tamanho) {

    for (int i=0;i<tamanho;i++) {
        printf("CPF: %s\n", alunos[i].cpf);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);

        for (int j=0;j<2;j++) {
            printf("Disciplina: %s\n", alunos[i].disciplinas[j]);
        }
    }
}

void preencher_disciplinas(char disciplinas[2][6]) {
    for (int i=0;i<2;i++) {
        printf("Disciplina: ");
        scanf("%s", disciplinas[i]);
    }
}


int main(int argc, char const *argv[])
{
    Aluno *alunos = malloc(sizeof(Aluno) * TAMANHO);
    int tamanho = TAMANHO;

    for (int i = 0; i < TAMANHO; i++) {
        printf("Digite: CPF - Nome - Idade\n");

        scanf("%s %s %d", alunos[i].cpf, alunos[i].nome, &alunos[i].idade);
        preencher_disciplinas(alunos[i].disciplinas);
    }

    //alunos = realloc(alunos, sizeof(Aluno) * tamanho + 1); // Adiciona espaço para mais um aluno
    //tamanho++;

    //alunos = realloc(alunos, sizeof(Aluno) * tamanho - 1); // Deleta um espaço de aluno
    //tamanho--;

    mostrar_alunos(alunos, tamanho);

    return 0;
}
