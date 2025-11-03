int main(int argc, char const *argv[])
{

    int n, k;

    printf("Informe a quantidade de numeros: ");
    scanf("%d", &n);

    printf("Informe a partir de de que numero: ");
    scanf("%d", &k);

    while (n != 0) {

        int count = 0;

        for (int i=1; i < k;i++) {
            if (k % i == 0) {
                count++;
            }
        }

        if (count == 1) {
            printf("%d ", k);
            n--;
        }
        
        k++;
    }

    return 0;
}
