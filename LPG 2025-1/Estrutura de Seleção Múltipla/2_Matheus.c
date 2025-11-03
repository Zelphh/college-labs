#include <stdio.h>

int main() {
    char categoria, subcategoria;
    
    printf("Escolha uma categoria:\n");
    printf("\n[F] Filmes");
    printf("\n[S] Séries");
    printf("\n[D] Documentários\n");
    
    printf("\n-> ");
    scanf(" %c", &categoria);
    
    switch (categoria) {
        case 'F':
        case 'f':
            printf("\n[S] Suspense");
            printf("\n[A] Ação\n");
            
            printf("\n-> ");
            scanf(" %c", &subcategoria);
            switch (subcategoria) {
                case 'S':
                case 's':
                    printf("'A órfã'\n");
                    break;
                case 'A':
                case 'a':
                    printf("'Batman: O cavaleiro das trevas'\n");
                    break;
            }
            break;
        
        case 'S':
        case 's':
            printf("\n[D] Drama");
            printf("\n[C] Comédia\n");
            printf("\n-> ");
            scanf(" %c", &subcategoria);
            switch (subcategoria) {
                case 'D':
                case 'd':
                    printf("'Revenge'\n");
                    break;
                case 'C':
                case 'c':
                    printf("'How I met your mother'\n");
                    break;
            }
            break;
        
        case 'D':
        case 'd':
            printf("\n[I] Investigação");
            printf("\n[C] Ciência\n");
            printf("\n-> ");
            scanf(" %c", &subcategoria);
            switch (subcategoria) {
                case 'I':
                case 'i':
                    printf("'Deep web'\n");
                    break;
                case 'C':
                case 'c':
                    printf("'Terra'\n");
                    break;
            }
            break;
    }
    
    return 0;
}
