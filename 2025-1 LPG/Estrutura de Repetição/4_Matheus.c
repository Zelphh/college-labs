#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    int num, incremento;
    
    printf("Informe um número: ");
    scanf("%d", &num);
    
    printf("Informe o incremento: ");
    scanf("%d", &incremento);
    
    for (int i=0; i <= num; i += incremento) {
        printf("%d ", i);
    }
    
    return 0;
}
