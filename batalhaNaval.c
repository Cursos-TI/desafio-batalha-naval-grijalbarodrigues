#include <stdio.h>

int main (){

    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numeros[10] = {1,2,3,4,5,6,7,8,9,10};
    int tabuleiro[10][10];
    int i, j;
    
    //inicializar o tabuleiro vazio:

    for (i = 0; i<10;i++){
        for (j=0;j<10;j++){
            tabuleiro[i][j] = 0;
        }
    }

    //posicionar o primeiro navio:
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;

    //verificar se há sobreposicao antes de colocar o segundo navio:

    int sobreposicao = 0;

    int linhasNavio2[] = {5,6,7};
    int colunasNavio2[] = {7,7,7};

    for (i=0;i<3;i++){
        int l = linhasNavio2[i];
        int c = colunasNavio2[i];
        
        if(tabuleiro[l][c]!=0){
            sobreposicao = 1;
            printf("Sobreposição detectada na posição: %c %d\n", letras[c], numeros[l]);
        }
    }

    //se nao houver sobreposicao segue o codigo e posiciona o segundo navio:

    if(!sobreposicao){
        for(i=0; i<3;i++){
            tabuleiro[linhasNavio2[i]][colunasNavio2[i]]=3;
        }printf("Sem sobreposição! O segundo navio será posicionado\n");
    }
    
    //printar as letras(colunas) do tabuleiro:
    printf("***BATALHA NAVAL***\n");
    printf("   ");
    for(j=0;j<10;j++){
        printf(" %c", letras[j]);
    }
    printf("\n");

    //imprime as linhas e os campos do tabuleiro
    for (i=0; i<10;i++){
        printf("%d |", numeros[i]);
        for(j=0;j<10;j++){
            printf(" %d", tabuleiro[i][j]);
        }printf("\n");
    }
    

    return 0;
}