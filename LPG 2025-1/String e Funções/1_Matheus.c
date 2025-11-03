#include <stdio.h>

int meu_strlen(char *str) {
    int count = 0;
    while (1) {
        if (str[count + 1] == '\0') {
            return count + 1;
        }
        count++;
    }
}

int main() {
    char texto[] = "1234567890";
    int length = meu_strlen(texto);
    printf("O tamanho da string eh: %d\n", length);
    return 0;
}

