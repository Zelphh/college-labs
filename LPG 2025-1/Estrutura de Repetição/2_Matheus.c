#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    int num;
    int count_par = 0;
    int count_impar = 0;
    
    for(int i = 0;i < 10;i++) {
        printf("Informe um número\n");
        scanf("%d", &num);
        
        if (num % 2 == 0) 
            count_par++;
        else
            count_impar++;
    }
    
    printf("Quantidade de números pares: %d\n", count_par);
    printf("Quantidade de números impares: %d\n", count_impar);
    
    return 0;
}
