#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10
#define AGUA 0
#define NAVIO 3


int main (){

    char letras[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numeros[LINHAS] = {1,2,3,4,5,6,7,8,9,10};
    int tabuleiro[LINHAS][COLUNAS];
    int i, j;
    
    //inicializar o tabuleiro vazio:

    for (i = 0; i<10;i++){
        for (j=0;j<10;j++){
            tabuleiro[i][j] = AGUA;
        }
    }

    //posicionar o primeiro navio:
    //definindo com variaveis os vetores q contem as posicoes do navio 1
    int sobreposicao = 0;

    int linhasNavio1[] = {0,0,0};
    int colunasNavio1[] = {2,3,4};

    for(int i = 0; i<3;i++){
        int l = linhasNavio1[i];
        int c = colunasNavio1[i];
        tabuleiro[linhasNavio1[i]][colunasNavio1[i]]=NAVIO;
    }
    printf("Primeiro Navio posicionado\n");

//verificar se há sobreposicao antes de colocar o segundo navio:
    
    int linhasNavio2[] = {5,6,7};
    int colunasNavio2[] = {7,7,7};

    for (int i=0;i<3;i++){
        int l = linhasNavio2[i];
        int c = colunasNavio2[i];
        
        if(tabuleiro[l][c]!=0){
            sobreposicao = 1;
            printf("Sobreposição detectada na posição: %c %d\n", letras[c], numeros[l]);
        }
    }
//se nao houver sobreposicao segue o codigo e posiciona o segundo navio:
    if(sobreposicao==0){
        for(i=0; i<3;i++){
            tabuleiro[linhasNavio2[i]][colunasNavio2[i]]=NAVIO;
        }printf("Segundo navio posicionado!\n");
    }
    
    //TERCEIRO NAVIO DIAGONAL E-D
    
    int linhasNavioD1[] = {0,1,2};
    int colunasNavioD1[] = {0,1,2};

    for (int i=0; i<3;i++){
        int l=linhasNavioD1[i];
        int c=colunasNavioD1[i];

        if (tabuleiro[l][c]!=0){
            sobreposicao = 1;
            printf("Não é possivel posicional o 1º navio na diagonal. Sobreposição em: %c%d\n", letras[c], numeros[l]);
        }
    }    
    if(sobreposicao==0){
        printf("Terceiro navio DIAGONAL posicionado.\n");
        for(int i=0;i<3;i++){
            tabuleiro[linhasNavioD1[i]][colunasNavioD1[i]] = NAVIO;
            
        }
        
    }

    //QUARTO NAVIO DIAGONAL D-E
    
    int linhasNavioD2[] = {9,8,7};
    int colunasNavioD2[] = {0,1,2};

    for (int i=0; i<3;i++){
        int l=linhasNavioD2[i];
        int c=colunasNavioD2[i];

        if (tabuleiro[l][c]!=0){
            sobreposicao = 1;
            printf("Não é possivel posicional o 4º navio na diagonal. Sobreposição em: %c%d\n", letras[c], numeros[l]);
        }
    }    
    if(sobreposicao==0){
        printf("QUARTO navio DIAGONAL posicionado.\n");
        for(int i=0;i<3;i++){
            tabuleiro[linhasNavioD2[i]][colunasNavioD2[i]] = NAVIO;
        }
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
        printf("%2d |", numeros[i]);
        for(j=0;j<10;j++){
            printf(" %d", tabuleiro[i][j]);
        }printf("\n");
    }
    

    return 0;
}