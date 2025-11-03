    #include <stdio.h>

    int verifica_par_impar(int x) {
        
        return x % 2 == 0 ? 1 : 0;
    }

    int main(int argc, char const *argv[])
    {
        
        int num;

        printf("Digite um numero: ");
        scanf("%d", &num);

        int result = verifica_par_impar(num);

        printf("[1] Par [0] Impar: %d", result);

        return 0;
    }
