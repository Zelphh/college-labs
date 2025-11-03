void swap(int *p, int *q) {

    int aux = *p;

    *p = *q;
    *q = aux;
}

int main(int argc, char const *argv[])
{
    int a = 50;
    int b = 100;

    printf("A: 0%d | B: %d\n", a, b);
    swap(&a, &b);
    printf("A: %d | B: 0%d\n", a, b);
    return 0;
}
