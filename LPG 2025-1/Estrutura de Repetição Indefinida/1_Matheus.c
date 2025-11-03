#include <stdio.h>

int main()
{
    
    int n1, n2;

    printf("Digite um número: ");
    scanf("%d", &n1);

    printf("Digite outro número: ");
    scanf("%d", &n2);
;
    while (n1 != n2) {

        printf("Número A: %d\n", n1);
        printf("Número B: %d\n", n2);

        if (n1 < n2) {
            n1++;
        } else {
            n1--;
        }
    }

    printf("\nNúmero A: %d\n", n1);
    printf("Número B: %d\n", n2);

    return 0;
}
