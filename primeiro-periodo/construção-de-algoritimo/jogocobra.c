#include <stdio.h>
#include <stdlib.h>
#define TAM 10


char tabuleiro[TAM][TAM];
int cobraPos[2][5];

int troca(int cl, int ln){

    tabuleiro[ln][cl] = tabuleiro[cobraPos[0][0]][cobraPos[1][0]];
    for(int i = 0; i < 4; i++){
        tabuleiro[cobraPos[0][i]][cobraPos[1][i]] = tabuleiro[cobraPos[0][i+1]][cobraPos[1][i+1]];
    }
    tabuleiro[cobraPos[0][4]][cobraPos[1][4]] = ' ';
}
void exibir(){
    system("cls");
    //exibe a matriz na tela
    for(int i = 0; i < TAM; i++){
        printf("|");
        for(int j = 0; j < TAM; j++){
            printf("%c|",tabuleiro[i][j]);
        }
        printf("\n");
    }
}
void colocaCobra(int c, int l){
    // coloca a cobra
    tabuleiro[l][c] = 'c';
    cobraPos[0][0] = l;
    cobraPos[1][0] = c;
    for (int i = 0; i < 4; i++){
        if((tabuleiro[l-1][c] == ' ') && (l - 1 > -1) && (l - 1 < 10)){
            l -= 1;
        }else if((tabuleiro[l][c-1] == ' ') && (c - 1 > -1) && (c - 1 < 10)){
            c -= 1;
        }else if((tabuleiro[l+1][c] == ' ') && (l + 1 > -1) && (l + 1 < 10)){
            l += 1;
        }else if((tabuleiro[l][c+1] == ' ') && (c + 1 > -1) && (c + 1 < 10)){
            c += 1;
        }
        if (i == 3){
            tabuleiro[l][c] = '.';
            cobraPos[0][4] = l;
            cobraPos[1][4] = c;
            continue;
        }
        tabuleiro[l][c] = '*';
        cobraPos[0][i+1] = l;
        cobraPos[1][i+1] = c;
    }

    exibir();
    system("pause");
}

int main()
{
    int obs;
    //monta o tabuleiro
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            tabuleiro[i][j] = ' ';
        }
    }

    //recebe a quantidade de obstaculos
    printf("Informe o numero de obstaculos: ");
    scanf("%d", &obs);

    //variavel que guarda possição invalida
    int block[2][obs];

    //coloca os obstaculos
    for(int i = 0; i < obs; i++){
        int l = rand() % TAM;
        int c = rand() % TAM;
        if(tabuleiro[l][c] == ' '){
            tabuleiro[l][c] = 'x';
            block[0][i] = l;
            block[1][i] = c;
        }
        else{
            i--;
        }
    }

    exibir();

    //coleta a possição inicial da cobra
    int sim = 0;
    int linha, coluna;
    do{
        sim = 0;
        printf("\nEscolha uma possição para a cobra: \n");
        printf("Linha: ");
        scanf("%d", &linha);
        printf("Coluna: ");
        scanf("%d", &coluna);
        for(int i = 0; i < obs; i++){
            if((block[0][i] == linha) && (block[1][i] == coluna)){
                sim = 1;
                printf("Essa possição é invalida pois já existe um obstaculo nela\n\nselecione outra\n\n");
                break;
            }
        }
    }while(sim);
    colocaCobra(coluna, linha);

    int n = rand() % 4;

    switch(n){
    case 0:
        linha += 1;
        troca(coluna, linha);
        break;
    case 1:
        linha -= 1;
        troca(coluna, linha);
        break;
    case 2:
        coluna += 1;
        troca(coluna, linha );
        break;
    case 3:
        coluna -= 1;
        troca(coluna, linha );
        break;
    }
    exibir();




    return 0;
}
