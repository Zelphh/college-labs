#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    int soma = 0;
    
    for (int i = 0;i <= 100;i++) {
        soma += i;
    } 
    
    printf("%d", soma);
    
    return 0;
}
