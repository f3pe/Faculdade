#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define TAM 10


//Aluno: Felipe Coutinho
//Aluno: Marianna Ferreira Silva
char tabuleiro[TAM][TAM];
int cobraPos[2][5];

int troca(int cl, int ln){
    //atualiza a cobra no tabuleiro
    tabuleiro[ln][cl] = tabuleiro[cobraPos[0][0]][cobraPos[1][0]];
    for(int i = 0; i < 4; i++){
        tabuleiro[cobraPos[0][i]][cobraPos[1][i]] = tabuleiro[cobraPos[0][i+1]][cobraPos[1][i+1]];
    }
    tabuleiro[cobraPos[0][4]][cobraPos[1][4]] = ' ';

    //atualiza o vetor com a posição da cobra
    for (int i = 4; i >= 0; i--){
        if(i > 0){
            for (int j = 0; j < 2; j++){
                cobraPos[j][i] = cobraPos[j][i-1];
            }
        }else{
            cobraPos[0][i] = ln;
            cobraPos[1][i] = cl; 
        }
    }
}
//verifica se é uma posição valida
int verifica(int li, int co){
    if(isalpha(tabuleiro[li][co])){
          return 0;
    }
    return 1;
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
    system("pause");
}
void colocaCobra(int c, int l){
    // coloca a cobra
    tabuleiro[l][c] = 'C';
    cobraPos[0][0] = l;
    cobraPos[1][0] = c;
    for (int i = 0; i < 4; i++){
        if((isspace(tabuleiro[l-1][c])) && (l - 1 > -1)){
            l -= 1;
        }else if((isspace(tabuleiro[l][c-1])) && (c - 1 > -1)){
            c -= 1;
        }else if((isspace(tabuleiro[l+1][c])) && (l + 1 < TAM)){
            l += 1;
        }else if((isspace(tabuleiro[l][c+1])) && (c + 1 < TAM)){
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
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int obs;
    //monta o tabuleiro
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            tabuleiro[i][j] = ' ';
        }
    }

    //recebe a quantidade de obstaculos
    printf("Informe o número de obstaculos: ");
    scanf("%d", &obs);

    //coloca os obstaculos
    for(int i = 0; i < obs; i++){
        int l = rand() % TAM;
        int c = rand() % TAM;
        if(tabuleiro[l][c] == ' '){
            tabuleiro[l][c] = 'x';
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
        if(isalpha(tabuleiro[linha][coluna])){
            sim = 1;
            printf("Essa possição é invalida pois já existe um obstaculo nela\n\nselecione outra\n\n");
        }
    }while(sim);

    colocaCobra(coluna, linha);

    int cont, ref;
    printf("Digite a quantidade de movimentos da cobra: ");
    scanf("%d", &cont);
    ref = cont;

    //decide a direção do movimento da cobra
    int end = 1;
    while((cont > 0) && (end == 1)){
        int n = rand() % 4;
        switch(n){
        case 1:
            if ((tabuleiro[linha+1][coluna] != '*') && (linha + 1 < TAM)){
                linha += 1;
                end = verifica(linha, coluna);
                troca(coluna, linha);
            }else{
                continue;
            }
            break;
        case 2:
            if((tabuleiro[linha-1][coluna] != '*') && (linha - 1 > -1)){
                linha -= 1;
                end = verifica(linha, coluna);
                troca(coluna, linha);
            }else{
                continue;
            }
            break;
        case 3:
            if((tabuleiro[linha][coluna+1] != '*') && (coluna + 1 < TAM)){
                coluna += 1;
                end = verifica(linha, coluna);
                troca(coluna, linha );
            }else{
                continue;
            }
            break;
        default:
            if((tabuleiro[linha][coluna-1] != '*') && (coluna - 1 > -1)){
                coluna -= 1;
                end = verifica(linha, coluna);
                troca(coluna, linha );
            }else{
                continue;
            }
        }
        exibir();
        cont--;
    }
    if (end == 1){
        printf("parabens vc ganhou!!!\n");
    }else{
        printf("vc bateu em um obstaculo\n");
        cont++;
    }
    printf("Foram visitadas %d casas \nE não foram visitadas %d casas\n\n", ref-cont, (100 - (ref-cont)) - obs);

    // Repete o jogo
    char continuar;
    printf("Contirunar?[S/N]: ");
    scanf(" %c", &continuar);
    continuar = tolower(continuar);
    if((continuar == 's')){
        main();
    }
    return 0;
}
