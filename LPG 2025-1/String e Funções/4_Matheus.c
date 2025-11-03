#include <stdio.h>

int meu_strcat(char* str1, const char* str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
    
}

int main() {
    char str1[64];
    char str2[64];

    int igual;

    printf("Primeira string:  \n"); 
    scanf("%s", str1);

    printf("Segunda string \n");
    scanf("%s", str2);

    igual = meu_strcat(str1, str2);

    printf("[1] Igual [0] Diferent: %d\n", igual); 

    return 0;
}