#include <stdio.h>

int main () {
    char linha [10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro [10][10];

    int numero_navio_horizontal = 4 ;
    char letra_navio_horizontal = 'I';

    int numero_navio_vertical = 2 ;
    char letra_navio_vertical = 'B';

    int numero_navio_diagonal = 5 ;
    char letra_navio_diagonal = 'B';
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
                if (i == numero_navio_horizontal && letra_navio_horizontal != 'A' && letra_navio_horizontal != 'J') {
                    // Navio horizontal
                    if (j >= 0 && j < 10) {
                        if (linha[j+1] == letra_navio_horizontal || linha[j] == letra_navio_horizontal || linha[j-1] == letra_navio_horizontal)
                        tabuleiro[i-1][j] = 3;
                    }
                }
                // Navio vertical
                if (letra_navio_vertical == linha[j] && numero_navio_vertical != 1 && numero_navio_vertical != 10) {
                    if (i == numero_navio_vertical || i == numero_navio_vertical-1 || i == numero_navio_vertical+1) {
                        tabuleiro[i-1][j] = 3;
                    }
                }
                // Navio Diagonal
                if (letra_navio_diagonal != 'A' && letra_navio_diagonal != 'J' && numero_navio_diagonal != 1 && numero_navio_diagonal != 10) {
                    if (i == numero_navio_diagonal && linha[j] == letra_navio_diagonal) {
                        tabuleiro[i - 1][j] = 3;
                    } else if (i == numero_navio_diagonal - 1 && linha[j + direcao_diagonal] == letra_navio_diagonal) {
                        tabuleiro[i - 1][j] = 3;
                    } else if (i == numero_navio_diagonal + 1 && linha[j - direcao_diagonal] == letra_navio_diagonal) {
                        tabuleiro[i - 1][j] = 3;
                    }
                }

                printf(" %d", tabuleiro[i-1][j]);
            }
        }
        printf("\n");
    }


    return 0;
}