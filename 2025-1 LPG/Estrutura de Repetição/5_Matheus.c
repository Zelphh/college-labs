#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    int num, maior;
    
    for(int i = 0;i < 10;i++) {
        printf("Informe um número: ");
        scanf("%d", &num);
        
        if (i == 0) {
            maior = num;
        } else {
            maior = num > maior ? num : maior;
        }
    }
    
    printf("Maior número: %d", maior);
    
    return 0;
}
