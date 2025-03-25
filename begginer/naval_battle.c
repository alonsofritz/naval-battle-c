#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int tamanho, int x, int y) {
    for (int i = 0; i < tamanho; i++) {
        if (y + i < TAMANHO_TABULEIRO) {
            tabuleiro[x][y + i] = 1; // 1 representa parte de um navio
        }
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int tamanho, int x, int y) {
    for (int i = 0; i < tamanho; i++) {
        if (x + i < TAMANHO_TABULEIRO) {
            tabuleiro[x + i][y] = 1; // 1 representa parte de um navio
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para exibir as coordenadas dos navios
void exibirCoordenadasNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nCoordenadas dos Navios:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 1) {
                printf("Navio na posicao: (%d, %d)\n", i, j);
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com 0s
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona um navio horizontal de tamanho 3 na posição (2,3)
    posicionarNavioHorizontal(tabuleiro, 3, 2, 3);
    
    // Posiciona um navio vertical de tamanho 4 na posição (5,7)
    posicionarNavioVertical(tabuleiro, 4, 5, 7);
    
    // Exibe o tabuleiro completo
    exibirTabuleiro(tabuleiro);
    
    // Exibe as coordenadas dos navios
    exibirCoordenadasNavios(tabuleiro);
    
    return 0;
}
