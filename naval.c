#include <stdio.h>

void Mostrar_Tabuleiro(int tabuleiro[10][10] ,char linha[10]){
    for (int i = 0; i<=10; i++){
        printf(i==0?"X":"%d",i);
        for (int j = 0; j<10; j++){
            if (j % 10 == 0 && j != 0){
                printf("\n");
            }
            if (i == 0){
                printf(" %c",linha[j]);
            }else{                               
                printf(" %d", tabuleiro[i-1][j]);
            }
        }
        printf("\n");
    }
}

void Habilidades(int tabuleiro[10][10], char linha[10], int habilidade, int posicao_numero, char posicao_letra){
    int letra_numero = 0;
    posicao_numero--;
    for (int i=0 ; i<10 ; i++){
        if (linha[i] == posicao_letra){
            letra_numero = i;
            break;
        }
    }
    switch(habilidade){
        case 1: // Habilidade Cone
            for (int i=0; i<3; i++){
                for (int j=letra_numero>1?-2:-letra_numero; j<(letra_numero<9?3:1); j++){
                    if (i == 0 && (j == -2 || j == 0)){
                        tabuleiro[posicao_numero][letra_numero]=5;
                        break;
                    }
                    else if(i == 1 && (j % 2 || j == 0) && posicao_numero<9){
                        tabuleiro[posicao_numero+1][letra_numero+j]=5;
                    }else if(i == 2 && posicao_numero<8){
                        tabuleiro[posicao_numero+2][letra_numero+j]=5;
                    }
                }
            }
            break;
        case 2: // Habilidade Cruz
            posicao_numero--;
            for (int i=0; i<3; i++){
                for (int j=letra_numero>1?-2:-letra_numero; j<(letra_numero<9?3:1); j++){
                    if (i == 0 || i == 2){
                        if (posicao_numero == 8 && i == 2){
                            break;
                        }
                        tabuleiro[posicao_numero+i][letra_numero]=5;
                        break;
                    }
                    else if(i == 1){
                        tabuleiro[posicao_numero+1][letra_numero+j]=5;
                    }
                }
            }
            break;
        case 3: // Habilidade Octaedro
            posicao_numero--;
            for (int i=0; i<3; i++){
                for (int j=letra_numero>1?-2:-letra_numero; j<(letra_numero<9?3:1); j++){
                    if (i == 0 || i == 2){
                        if (posicao_numero == 8 && i == 2){
                            break;
                        }
                        tabuleiro[posicao_numero+i][letra_numero]=5;
                        break;
                    }
                    else if(i == 1 && (j % 2 || j == 0)){
                        tabuleiro[posicao_numero+1][letra_numero+j]=5;
                    }
                }
        }
            break;
    }
}

void Colocar_Navio(int tabuleiro[10][10], char linha[10], int numero_tabuleiro, int posicao_tabuleiro, int tipo_navio, char letra_navio, int numero_navio, int direcao_diagonal) {

    switch (tipo_navio) {
        case 1: // Navio horizontal
            if (numero_tabuleiro == numero_navio && letra_navio != 'A' && letra_navio != 'J') {
                if (posicao_tabuleiro >= 0 && posicao_tabuleiro < 10) {
                    if (linha[posicao_tabuleiro] == letra_navio ||
                        (posicao_tabuleiro > 0 && linha[posicao_tabuleiro - 1] == letra_navio) ||
                        (posicao_tabuleiro < 9 && linha[posicao_tabuleiro + 1] == letra_navio)) {
                        tabuleiro[numero_tabuleiro - 1][posicao_tabuleiro] = 1;
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

int Verificar_Area(int tabuleiro[10][10], char linha[10], int posicao_numero, char posicao_letra, int tipo_navio){
    int numero_letra = 0;
    int navio_encontrado = 0; 
    posicao_numero--;

    // Definir a Letra como um Valor Numerico
    for (int i = 0; i <10; i++){
        if (linha[i] == posicao_letra){
            numero_letra = i;
            break;
        }
    }
    // Letra Não encontrada
    if (!numero_letra){
        return 0;
    }
    switch (tipo_navio){
        case 1:
            // Navio Horizontal
            printf("Primeiro Posição: %d Segundo Posição: %d Terceiro Posição: %d ", tabuleiro[posicao_numero][numero_letra-1], tabuleiro[posicao_numero][numero_letra], tabuleiro[posicao_numero][numero_letra+1]);
            if (!tabuleiro[posicao_numero][numero_letra-1] && !tabuleiro[posicao_numero][numero_letra] && !tabuleiro[posicao_numero][numero_letra+1]){
                navio_encontrado=1;
            }
            break;
        case 2:
            // Navio Vertical
            printf("Primeiro Posição: %d Segundo Posição: %d Terceiro Posição: %d ", tabuleiro[posicao_numero-1][numero_letra], tabuleiro[posicao_numero][numero_letra], tabuleiro[posicao_numero+1][numero_letra]);
            if (!tabuleiro[posicao_numero-1][numero_letra] && !tabuleiro[posicao_numero][numero_letra] && !tabuleiro[posicao_numero+1][numero_letra]){
                navio_encontrado=1;
            }
            break;
        case 3:
            // Diagonal 
            printf("Primeiro Posição: %d Segundo Posição: %d Terceiro Posição: %d ", tabuleiro[posicao_numero+1][numero_letra-1], tabuleiro[posicao_numero][numero_letra], tabuleiro[posicao_numero-1][numero_letra+1]);
            if (!tabuleiro[posicao_numero+1][numero_letra-1] && !tabuleiro[posicao_numero][numero_letra] && !tabuleiro[posicao_numero-1][numero_letra+1]){
                navio_encontrado=1;
            }
            break;
        case 4:
            // Diagonal Invertido
            printf("Primeiro Posição: %d Segundo Posição: %d Terceiro Posição: %d ", tabuleiro[posicao_numero-1][numero_letra-1], tabuleiro[posicao_numero][numero_letra], tabuleiro[posicao_numero+1][numero_letra+1]);
            if (!tabuleiro[posicao_numero-1][numero_letra-1] && !tabuleiro[posicao_numero][numero_letra] && !tabuleiro[posicao_numero+1][numero_letra+1]){
                navio_encontrado=1;
            }
            break;
        

    }
    
    return !navio_encontrado;
}

int main () {
    // Tabuleiro
    char linha [10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro [10][10];


    // Navios
    int numero_navio_horizontal = 4 ;
    char letra_navio_horizontal = 'I';

    int numero_navio_vertical = 2 ;
    char letra_navio_vertical = 'B';

    int numero_navio_diagonal = 8 ;
    char letra_navio_diagonal = 'B';

    int numero_navio_diagonal_invertida = 5 ;
    char letra_navio_diagonal__invertida = 'E';

    int direcao_diagonal = -1;
    
    // Definir o Tabuleiro de acordo com os Navios já definidos previamente
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

    printf("\n");

    // Verifica a Area do Tabulueiro de Acordo com a Posição em Exemplo 6F
    // Tipo de Navio: 1 Horizontal | 2 Vertical | 3 Diagonal | 4 Diagonal Inversa
    if(Verificar_Area(tabuleiro, linha, 6, 'F', 3)){
        printf("Navio Encontrado\n");
     }else{
        printf("Navio Não Encontrado\n");
     }

    // Habilidades Base em Tipo de Habilidade e Posição Exemplo 3 Octagono 8H
    // Tipo Habilidade 1 Cone | 2 Cruz | 3 Octagono
    Habilidades(tabuleiro, linha, 3, 7, 'A');

    // Mostrar O Tabuleiro
    printf("\n");
    Mostrar_Tabuleiro(tabuleiro, linha);
    return 0;
}