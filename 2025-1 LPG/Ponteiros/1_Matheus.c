int main( )
{
    int p[2][2];

    p[0][0] = 1;
    p[0][1] = 2;
    p[1][0] = 3;
    p[1][1] = 4;

   int  x = 1;

    for (int i = 0; i < 2; i++) {
        for (int j=0; j < 2; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    printf("\n ------------- \n\n");

    printf("%d\n", p);
    printf("%d\n", p+1);
    printf("%d\n", p+2);
    
    printf("%d", p[1]);
    


    return 0;
}
