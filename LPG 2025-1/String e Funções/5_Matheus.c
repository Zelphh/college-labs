#include <stdio.h>
#include <string.h>

int verifica_palindromo(char* str, const int tamanho) {
    int i = 0;
    int j = tamanho - 1;

    while (i < j) {
        if(str[i] != str[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    char str[64];

    printf("Infome uma palavra: "); 
    scanf("%s", str);
    
    int tamanho = strlen(str);
    int result = verifica_palindromo(str, tamanho);

    printf("[1] Palindromo [0] Nao palindromo: %d\n", result); 

    return 0;
}