#include <stdio.h>

int verifica_primo(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;        
        }
    }
    return 1;  
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("[1] Primo [0] Noo primo:  %d", verifica_primo(n));

    return 0;
}