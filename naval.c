#include <stdio.h>

void Colocar_Navio(int tabuleiro[10][10], char linha[10], int numero_tabuleiro, int posicao_tabuleiro, int tipo_navio, char letra_navio, int numero_navio, int direcao_diagonal) {


    switch (tipo_navio) {
        case 1: // Navio horizontal
            if (numero_tabuleiro == numero_navio && letra_navio != 'A' && letra_navio != 'J') {
                if (posicao_tabuleiro >= 0 && posicao_tabuleiro < 10) {
                    if (linha[posicao_tabuleiro] == letra_navio ||
                        (posicao_tabuleiro > 0 && linha[posicao_tabuleiro - 1] == letra_navio) ||
                        (posicao_tabuleiro < 9 && linha[posicao_tabuleiro + 1] == letra_navio)) {
                        tabuleiro[numero_tabuleiro - 1][posicao_tabuleiro] = 3;
                    }
                }
            }
            break;

        case 2: // Navio vertical
            if (letra_navio == linha[posicao_tabuleiro] && numero_navio != 1 && numero_navio != 10) {
                if (numero_tabuleiro == numero_navio || numero_tabuleiro == numero_navio - 1 || numero_tabuleiro == numero_navio + 1) {
                    tabuleiro[numero_tabuleiro - 1][posicao_tabuleiro] = 3;
                }
            }
            break;

        case 3: // Navio diagonal
            if (letra_navio != 'A' && letra_navio != 'J' && numero_navio != 1 && numero_navio != 10) {
                if (numero_tabuleiro == numero_navio && linha[posicao_tabuleiro] == letra_navio) {
                    tabuleiro[numero_tabuleiro - 1][posicao_tabuleiro] = 3;
                } else if (numero_tabuleiro == numero_navio - 1 && posicao_tabuleiro + direcao_diagonal >= 0 && posicao_tabuleiro + direcao_diagonal < 10) {
                    if (linha[posicao_tabuleiro + direcao_diagonal] == letra_navio) {
                        tabuleiro[numero_tabuleiro - 1][posicao_tabuleiro] = 3;
                    }
                } else if (numero_tabuleiro == numero_navio + 1 && posicao_tabuleiro - direcao_diagonal >= 0 && posicao_tabuleiro - direcao_diagonal < 10) {
                    if (linha[posicao_tabuleiro - direcao_diagonal] == letra_navio) {
                        tabuleiro[numero_tabuleiro - 1][posicao_tabuleiro] = 3;
                    }
                }
            }
            break;

        default:
            printf("Tipo de navio inválido!\n");
            break;
    }
}

int main () {
    char linha [10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro [10][10];

    int numero_navio_horizontal = 4 ;
    char letra_navio_horizontal = 'I';

    int numero_navio_vertical = 2 ;
    char letra_navio_vertical = 'B';

    int numero_navio_diagonal = 5 ;
    char letra_navio_diagonal = 'B';

    int numero_navio_diagonal_invertida = 5 ;
    char letra_navio_diagonal__invertida = 'B';

    int direcao_diagonal = -1;

    for (int i = 0; i<=10; i++){
        printf(i==0?"X":"%d",i);
        for (int j = 0; j<10; j++){
            if (j % 10 == 0 && j != 0){
                printf("\n");
            }
            if (i == 0){
                printf(" %c",linha[j]);
            }else{
                tabuleiro[i-1][j] = 0;
                
                // Navio horizontal
                Colocar_Navio(tabuleiro, linha, i, j, 1, letra_navio_horizontal, numero_navio_horizontal, direcao_diagonal);
                // Navio vertical
                Colocar_Navio(tabuleiro, linha, i, j, 2, letra_navio_vertical, numero_navio_vertical, direcao_diagonal);
                // Navio Diagonal
                Colocar_Navio(tabuleiro, linha, i, j, 3, letra_navio_diagonal, numero_navio_diagonal, direcao_diagonal);
                // Navio Diagonal 2 
                Colocar_Navio(tabuleiro, linha, i, j, 3, letra_navio_diagonal__invertida,numero_navio_diagonal_invertida, 1);
                                
                printf(" %d", tabuleiro[i-1][j]);
            }
        }
        printf("\n");
    }


    return 0;
}