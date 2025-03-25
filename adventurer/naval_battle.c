#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 1

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição é válida
int posicaoValida(int x, int y) {
    return x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO;
}

// Posiciona navio horizontal
int posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int tamanho, int x, int y) {
    // Verifica se cabe no tabuleiro
    if (y + tamanho > TAMANHO_TABULEIRO) return 0;
    
    // Verifica se não há colisão com outros navios
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[x][y + i] != AGUA) return 0;
    }
    
    // Posiciona o navio
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[x][y + i] = NAVIO;
    }
    return 1;
}

// Posiciona navio vertical
int posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int tamanho, int x, int y) {
    if (x + tamanho > TAMANHO_TABULEIRO) return 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[x + i][y] != AGUA) return 0;
    }
    
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[x + i][y] = NAVIO;
    }
    return 1;
}

// Posiciona navio diagonal (direita para baixo)
int posicionarDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int tamanho, int x, int y) {
    if (x + tamanho > TAMANHO_TABULEIRO || y + tamanho > TAMANHO_TABULEIRO) return 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[x + i][y + i] != AGUA) return 0;
    }
    
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[x + i][y + i] = NAVIO;
    }
    return 1;
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %2d", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %2d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posiciona navios aleatoriamente
void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    srand(time(NULL));
    int naviosPosicionados = 0;
    
    while (naviosPosicionados < 4) {
        int x = rand() % TAMANHO_TABULEIRO;
        int y = rand() % TAMANHO_TABULEIRO;
        int direcao = rand() % 3; // 0-horiz, 1-vert, 2-diag
        int tamanho = 3 + rand() % 3; // Navios de 3 a 5 posições
        
        int sucesso = 0;
        
        switch (direcao) {
            case 0:
                sucesso = posicionarHorizontal(tabuleiro, tamanho, x, y);
                break;
            case 1:
                sucesso = posicionarVertical(tabuleiro, tamanho, x, y);
                break;
            case 2:
                sucesso = posicionarDiagonal(tabuleiro, tamanho, x, y);
                break;
        }
        
        if (sucesso) {
            naviosPosicionados++;
            printf("Navio %d: tamanho %d, posicao (%d,%d), direcao %s\n",
                   naviosPosicionados, tamanho, x, y,
                   direcao == 0 ? "horizontal" : (direcao == 1 ? "vertical" : "diagonal"));
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    exibirTabuleiro(tabuleiro);
    
    printf("\nLegenda:\n");
    printf("0 - Agua\n");
    printf("1 - Navio\n");
    
    return 0;
}