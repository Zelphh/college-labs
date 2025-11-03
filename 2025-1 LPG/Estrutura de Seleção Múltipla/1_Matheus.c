#include <stdio.h>

int main() {
    int estado;

    printf("[ 1 ] Acre\n[ 2 ] Alagoas\n[ 3 ] Amazonas\n[ 4 ] Bahia\n[ 5 ] Ceará\n");
    printf("[ 6 ] Distrito Federal\n[ 7 ] Espirito Santo\n[ 8 ] Goiás\n[ 9 ] Maranhão\n[ 10 ] Mato Grosso\n");
    printf("[ 11 ] Mato Grosso do Sul\n[ 12 ] Minas Gerais\n[ 13 ] Pará\n[ 14 ] Paraíba\n[ 15 ] Paraná\n");
    printf("[ 16 ] Pernambuco\n[ 17 ] Piauí\n[ 18 ] Rio de Janeiro\n[ 19 ] Rio Grande do Norte\n[ 20 ] Rio Grande do Sul\n");
    printf("[ 21 ] Rondônia\n[ 22 ] Roraima\n[ 23 ] Santa Catarina\n[ 24 ] São Paulo\n[ 25 ] Sergipe\n[ 26 ] Tocantins\n");
    printf("\nSelecione o estado-> ");
    
    scanf("%d", &estado);

    // Usa o switch para identificar a região do estado
    switch (estado) {
        case 1:
        case 3:
        case 13:
        case 21:
        case 22:
            printf("Região: Norte\n");
            break;
        case 2:
        case 4:
        case 5:
        case 14:
        case 16:
        case 17:
        case 25:
            printf("Região: Nordeste\n");
            break;
        case 6:
        case 8:
        case 10:
        case 11:
            printf("Região: Centro-Oeste\n");
            break;
        case 7:
        case 12:
        case 18:
        case 19:
        case 24:
            printf("Região: Sudeste\n");
            break;
        case 9:
        case 15:
        case 20:
        case 23:
            printf("Região: Sul\n");
            break;

    return 0;
    }
}