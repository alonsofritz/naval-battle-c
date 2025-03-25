#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 1
#define HABILIDADE 2

// Estrutura para representar coordenadas
typedef struct {
    int x;
    int y;
} Coordenada;

// Funções básicas do tabuleiro (como nos níveis anteriores)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

int posicaoValida(int x, int y) {
    return x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO;
}

// Funções de posicionamento de navios (como no nível Aventureiro)
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int tamanho, int x, int y, int direcao) {
    // Implementação similar ao nível anterior
    // Retorna 1 se posicionou com sucesso, 0 caso contrário
}

// Funções de habilidades especiais
void habilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    int raio = 2; // Tamanho do cone
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if (abs(i) + abs(j) <= raio && posicaoValida(x+i, y+j)) {
                tabuleiro[x+i][y+j] = HABILIDADE;
            }
        }
    }
}

void habilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    int tamanho = 3; // Tamanho da cruz
    for (int i = -tamanho; i <= tamanho; i++) {
        if (posicaoValida(x+i, y)) {
            tabuleiro[x+i][y] = HABILIDADE;
        }
        if (posicaoValida(x, y+i)) {
            tabuleiro[x][y+i] = HABILIDADE;
        }
    }
}

void habilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    int raio = 2;
    for (int i = -raio; i <= raio; i++) {
        for (int j = -raio; j <= raio; j++) {
            if ((abs(i) + abs(j)) <= raio && posicaoValida(x+i, y+j)) {
                tabuleiro[x+i][y+j] = HABILIDADE;
            }
        }
    }
}

// Exibe o tabuleiro com cores (opcional)
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) printf("%2d ", j);
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == HABILIDADE) {
                printf("\033[1;31m"); // Vermelho para habilidades
                printf("%2d ", tabuleiro[i][j]);
                printf("\033[0m");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("\033[1;34m"); // Azul para navios
                printf("%2d ", tabuleiro[i][j]);
                printf("\033[0m");
            } else {
                printf("%2d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

// Menu para selecionar habilidades
void menuHabilidades(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int opcao, x, y;
    
    printf("\n=== HABILIDADES ESPECIAIS ===\n");
    printf("1 - Ataque em Cone\n");
    printf("2 - Ataque em Cruz\n");
    printf("3 - Ataque em Octaedro\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    
    if (opcao == 0) return;
    
    printf("Digite as coordenadas (x y): ");
    scanf("%d %d", &x, &y);
    
    if (!posicaoValida(x, y)) {
        printf("Coordenadas invalidas!\n");
        return;
    }
    
    switch(opcao) {
        case 1:
            habilidadeCone(tabuleiro, x, y);
            printf("Ataque em Cone aplicado em (%d,%d)\n", x, y);
            break;
        case 2:
            habilidadeCruz(tabuleiro, x, y);
            printf("Ataque em Cruz aplicado em (%d,%d)\n", x, y);
            break;
        case 3:
            habilidadeOctaedro(tabuleiro, x, y);
            printf("Ataque em Octaedro aplicado em (%d,%d)\n", x, y);
            break;
        default:
            printf("Opcao invalida!\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    srand(time(NULL));
    
    // Inicialização do jogo
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona alguns navios (como no nível Aventureiro)
    posicionarNavio(tabuleiro, 4, 2, 3, 0); // Horizontal
    posicionarNavio(tabuleiro, 3, 5, 7, 1); // Vertical
    posicionarNavio(tabuleiro, 5, 1, 1, 2); // Diagonal
    
    // Menu principal
    int opcao;
    do {
        exibirTabuleiro(tabuleiro);
        
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Usar Habilidade Especial\n");
        printf("2 - Mostrar Tabuleiro\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                menuHabilidades(tabuleiro);
                break;
            case 2:
                exibirTabuleiro(tabuleiro);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    return 0;
}