#include <stdio.h>

void meu_strcat(char *destino, const char *origem) {
    int i = 0;
    
    while (destino[i] != '\0') {
        i++;
    }

    int j = 0;
    while (origem[j] != '\0') {
        destino[i] = origem[j];
        i++;
        j++;
    }

    destino[i] = '\0';
}

int main() {
    char destino[100] = "Hello, ";
    char origem[] = "como voce esta?";

    meu_strcat(destino, origem);

    printf("String concatenada: %s\n", destino);
    return 0;
}
