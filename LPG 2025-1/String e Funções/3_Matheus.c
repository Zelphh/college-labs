#include <stdio.h>

void meu_strcpy(char *destino, char *origem) {

    int i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';

}

int main(int argc, char const *argv[])
{

    char str[] = "Andarilho";
    char destino[64];

    meu_strcpy(destino, str);

    printf("String copiada: %s\n", destino);

    return 0;
}
