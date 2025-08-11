#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 1
#define EFEITOHABILIDADE 5

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

    //DEFINICAO DAS POSICOES ESPECIAIS: CRUZ, CONE  E OCTAEDRO NO TABULEIRO:

    //******CRUZ:
    int cruzX =1, cruzY=8;
    //ponto central da cruz:
    tabuleiro[cruzX][cruzY] = HABILIDADE;
    
    if(cruzY+1<COLUNAS && cruzY - 1 >= 0 && cruzX+1 < LINHAS && cruzX-1 >= 0){
        tabuleiro[cruzX][cruzY+1] = HABILIDADE;
        tabuleiro[cruzX][cruzY-1] = HABILIDADE;
        tabuleiro[cruzX+1][cruzY] = HABILIDADE;
        tabuleiro[cruzX-1][cruzY] = HABILIDADE;
    } else {
        printf("Habilidade especial (CRUZ) definida fora do tabuleiro\n");
    }

    //******CONE
    int topoConeX = 7;
    int topoConeY = 5;

    int direita = 0, esquerda = 0;

    if(topoConeX >= 0 && topoConeX < COLUNAS && topoConeY >= 0 && topoConeY < COLUNAS){
    for (int i = topoConeX; i < topoConeX + 3; i++){   
            
            int inicio = topoConeY - esquerda;
            int fim = topoConeY + direita;
            
            if(inicio >=0 && fim < COLUNAS){
            
            for (int j = inicio; j <= fim; j++){
                if(i >= 0 && i < COLUNAS && j >=0 && j < LINHAS){
                    tabuleiro[i][j] = HABILIDADE;
                }else{
                    printf("Habilidade especial (CONE) definida fora do tabuleiro\n");
                } 
            }
            direita++;
            esquerda++;
            }
        }
    }

    //***********OCTAEDRO
    int linhaInicialOctaedro = 1;       // topo do losango (linha)
    int OctaedroY = 5;           // coluna central do losango
    int linhaCentralOctaedroX = 3;     // base do losango (linha)
    int linhaFinalOctaedro = 5;       // linha final do losango (descida)

    int direitaOctaedro = 0, esquerdaOctaedro = 0;

    // Fase subida (base)
    if(linhaInicialOctaedro >=0 && linhaFinalOctaedro <LINHAS){
    
        for (int i = linhaInicialOctaedro; i <= linhaCentralOctaedroX; i++) {
        int inicioOctaedro = OctaedroY - esquerdaOctaedro;
        int fimOctaedro = OctaedroY + direitaOctaedro;
            if(inicioOctaedro >=0 && fimOctaedro < COLUNAS){
            for (int j = inicioOctaedro; j <= fimOctaedro; j++) {
                tabuleiro[i][j] = HABILIDADE;
            }}else{
                printf("Limites laterais do octaedro fora do tabuleiro\n");
            }
        direitaOctaedro++;
        esquerdaOctaedro++;
    }


    // Fase descida
    direitaOctaedro -= 2;
    esquerdaOctaedro -= 2;

    for (int i = linhaCentralOctaedroX + 1; i <= linhaFinalOctaedro; i++) {
        int inicioOctaedro = OctaedroY - esquerdaOctaedro;
        int fimOctaedro = OctaedroY + direitaOctaedro;
        for (int j = inicioOctaedro; j <= fimOctaedro; j++) {
            tabuleiro[i][j] = HABILIDADE;
        }
        direitaOctaedro--;
        esquerdaOctaedro--;
    }
}else{
        printf("Limites superior e/ou inferior do octaedro fora do tabuleiro\n");
}

    //posicionar o primeiro navio:
    //definindo com variaveis os vetores q contem as posicoes do navio 1
    int sobreposicao1 = 0;

    int linhasNavio1[] = {0,0,0};
    int colunasNavio1[] = {6,7,8};

    for(int i = 0; i<3;i++){
        int l1 = linhasNavio1[i];
        int c1 = colunasNavio1[i];
        
        if(l1<0||LINHAS>10||c1<0||COLUNAS>10){
            printf("Erro! Navio 1 fora do limite do tabuleiro - %c%d\n", letras[c1], numeros[l1]);
            return 1;
        }

        if(tabuleiro[l1][c1]==NAVIO){
            sobreposicao1=1;
            printf("Erro. 1º navio com sobreposicao em %c%d\n", letras[c1], numeros[l1]);
            break;
        }
        if (sobreposicao1==0){
            if(tabuleiro[l1][c1]==0){
                tabuleiro[linhasNavio1[i]][colunasNavio1[i]]=NAVIO;
            }
            if(tabuleiro[l1][c1]==1){
                tabuleiro[linhasNavio1[i]][colunasNavio1[i]]=EFEITOHABILIDADE;
            }
        }
            
    }printf("Primeiro Navio posicionado\n");    

//verificar se há sobreposicao antes de colocar o segundo navio:
    int sobreposicao2 = 0;    

    int linhasNavio2[] = {4,5,6};
    int colunasNavio2[] = {6,6,6};

    for (int i=0;i<3;i++){
        
        int l2 = linhasNavio2[i];
        int c2 = colunasNavio2[i];
        
        if(l2<0||LINHAS>10||c2<0||COLUNAS>10){
            printf("Erro! Navio 2 fora do limite do tabuleiro - %c%d\n", letras[c2], numeros[l2]);
            return 1;
        }

        if(tabuleiro[l2][c2]==NAVIO){
            sobreposicao2 = 1;
            printf("Sobreposição detectada na posição: %c %d\n", letras[c2], numeros[l2]);
        }
    }
//se nao houver sobreposicao segue o codigo e posiciona o segundo navio:
    if(sobreposicao2==0){
        for(int i=0; i<3;i++){
            int l2 = linhasNavio2[i];
            int c2 = colunasNavio2[i];
            
            if(tabuleiro[l2][c2]==0){
                tabuleiro[linhasNavio2[i]][colunasNavio2[i]]=NAVIO;
            }
            if(tabuleiro[l2][c2]==1){
                tabuleiro[linhasNavio2[i]][colunasNavio2[i]]=EFEITOHABILIDADE;
            }
        }printf("Segundo navio posicionado!\n");
    }
    
    //TERCEIRO NAVIO DIAGONAL E-D
    int sobreposicao3=0;


    int linhasNavioD1[] = {0,1,2};
    int colunasNavioD1[] = {3,4,5};

    for (int i=0; i<3;i++){
        int ld1=linhasNavioD1[i];
        int cd1=colunasNavioD1[i];

        if(ld1<0||LINHAS>10||cd1<0||COLUNAS>10){
            printf("Erro! Navio 3 fora do limite do tabuleiro - %c%d\n", letras[cd1], numeros[ld1]);
            return 1;
        }

        if (tabuleiro[ld1][cd1]== NAVIO){
            sobreposicao3 = 1;
            printf("Não é possivel posicional o 1º navio na diagonal. Sobreposição em: %c%d\n", letras[cd1], numeros[ld1]);
        }
    }    
    if(sobreposicao3==0){
        printf("Terceiro navio DIAGONAL posicionado.\n");
        for(int i=0;i<3;i++){
            int ld1=linhasNavioD1[i];
            int cd1=colunasNavioD1[i];

            if(tabuleiro[ld1][cd1]==0){
                tabuleiro[linhasNavioD1[i]][colunasNavioD1[i]]=NAVIO;
            }
            if(tabuleiro[ld1][cd1]==1){
                tabuleiro[linhasNavioD1[i]][colunasNavioD1[i]]=EFEITOHABILIDADE;
            }
            
        }
        
    }

    //QUARTO NAVIO DIAGONAL D-E
    int sobreposicao4=0;


    int linhasNavioD2[] = {9,8,7};
    int colunasNavioD2[] = {7,8,9};

    for (int i=0; i<3;i++){
        int ld2=linhasNavioD2[i];
        int cd2=colunasNavioD2[i];

        if(ld2<0||LINHAS>10||cd2<0||COLUNAS>10){
            printf("Erro! Navio 4 fora do limite do tabuleiro - %c%d\n", letras[cd2], numeros[ld2]);
            return 1;
        }

        if (tabuleiro[ld2][cd2]==NAVIO){
            sobreposicao4 = 1;
            printf("Não é possivel posicional o 4º navio na diagonal. Sobreposição em: %c%d\n", letras[cd2], numeros[ld2]);
        }
    }    
    if(sobreposicao4==0){
        printf("QUARTO navio DIAGONAL posicionado.\n");
        for(int i=0;i<3;i++){
            int ld2=linhasNavioD2[i];
            int cd2=colunasNavioD2[i];

            if(tabuleiro[ld2][cd2]==0){
                tabuleiro[linhasNavioD2[i]][colunasNavioD2[i]]=NAVIO;
            }
            if(tabuleiro[ld2][cd2]==1){
                tabuleiro[linhasNavioD2[i]][colunasNavioD2[i]]=EFEITOHABILIDADE;
            }
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