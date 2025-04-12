#include <stdio.h>

int main(){

    //Matriz

    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    //Posicoes centrais das habilidades
    int centrocone_i = 2, centrocone_j = 5;
    int centrocruz_i = 5, centrocruz_j = 2;
    int centrooctaedro_i = 8, centrooctaedro_j = 6;
    

    //Posicionador
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (cone[i][j] != 0){ //Garante que apenas o numero que representa a skill va para o tabuleiro
                int linhai = centrocone_i + i - 2; //centraliza a habilidade no tabuleiro
                int colunaj = centrocone_j + j - 2;
                if (linhai >= 0 && linhai < 10 && colunaj >= 0 && colunaj < 10) { //verifica se esta dentro do tabuleiro
                    tabuleiro[linhai][colunaj] = cone[i][j];//sobrepoe a matriz de habilidade no tabuleiro
                }
            }
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (cruz[i][j] != 0){
                int linhai = centrocruz_i + i - 2;
                int colunaj = centrocruz_j + j - 2;
                if (linhai >= 0 && linhai < 10 && colunaj >= 0 && colunaj < 10){
                    tabuleiro[linhai][colunaj] = cruz[i][j];
                }
            }
        }
    }


    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (octaedro[i][j] != 0){
                int linhai = centrooctaedro_i + i - 2;
                int colunaj = centrooctaedro_j + j - 2;
                if (linhai >= 0 && linhai < 10 && colunaj >= 0 && colunaj < 10){
                    tabuleiro[linhai][colunaj] = octaedro[i][j];
                }
            }
        }
    }





   //Navios

    for (int naviov = 2; naviov < 5; naviov++){ //controla a linha
        tabuleiro[naviov][9] = 3; //seleciona a coluna e da o valor do navio
    }

    for (int navioh = 5; navioh < 8; navioh++){
        tabuleiro[4][navioh] = 3;
    }

    for (int diagop = 0; diagop < 3; diagop++){
        tabuleiro[diagop+1][diagop+1] = 3; //Controla a diagonal padrao
    }

    for (int diagos = 6; diagos < 9; diagos++){
        tabuleiro[diagos][10 - 1 - diagos] = 3;// Subtrai a linha por 9 para conseguir a coluna (6, 3)
    }


 

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }



    return 0;
}