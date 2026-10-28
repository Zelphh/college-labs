#include <stdio.h>
#include <string.h>

int main() {
    char b[1024], n1[256], n2[256];

    // printf("Arquivo de leitura: ");
    // scanf("%s", n1);

    // printf("Arquivo de escrita: ");
    //scanf("%s", n2);

    strcpy(n1, "input.txt");
    strcpy(n2, "output.txt");

    FILE *f1 = fopen(n1, "r");
    FILE *f2 = fopen(n2, "w");

    // printf("Conteudo:\n");
    while (fgets(b, sizeof(b), f1)) {
        // printf("%s", b);
        fputs(b, f2);
    }
    // printf("\n", b);

    fclose(f1);
    fclose(f2);

    return 0;
}