int main()
{
   
    int n1, n2, buffer;
    int escolha = 0;

    float final;

    printf("Informe o primeiro numero: \n-> ");
    scanf("%d", &n1);

    printf("Informe o segundo numero: \n-> ");
    scanf("%d", &n2);

    while (escolha != 5) {

        printf("\n\n1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("5 - Sair\n\n-> ");

        scanf("%d", &escolha);

        if (escolha == 1) {
            final = n1 + n2;
            printf("\nResultado: %.2f", final);

        } else if (escolha == 2) {
            final = n1 - n2;
            printf("\nResultado: %.2f", final);

        } else if (escolha == 3) {
            final = n1 * n2;
            printf("\nResultado: %.2f", final);

        } else if (escolha == 4) {
            final = n1 / n2;
            printf("\nResultado: %.2f", final);

        } else {
            printf("Escolha inválida! Infome o numero novamente");
            scanf("-> %d", &escolha);
        }
    }

    printf("Programa encerrado com sucesso!");


    return 0;
}
