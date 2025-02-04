#include <stdio.h>
#include <string.h>

// Estrutura para representar uma cidade
struct Cidade {
    char codigo[4]; // Código da carta (ex: A01, B02)
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

int main() {
    const int NUM_ESTADOS = 8; // Estados de A a H
    const int NUM_CIDADES_POR_ESTADO = 4; // 4 cidades por estado
    struct Cidade cartas[NUM_ESTADOS][NUM_CIDADES_POR_ESTADO]; // Matriz para armazenar as cartas

    printf("Bem-vindo ao cadastro de cartas do Super Trunfo - Países!\n");

    // Cadastro das cartas
    for (int i = 0; i < NUM_ESTADOS; i++) {
        char estado = 'A' + i; // Estado atual (A, B, C, ..., H)
        for (int j = 0; j < NUM_CIDADES_POR_ESTADO; j++) {
            printf("\nCadastrando cidade %c%d:\n", estado, j + 1);

            // Preenche o código da carta
            snprintf(cartas[i][j].codigo, 4, "%c%d", estado, j + 1);

            // Solicita os dados da cidade
            printf("População: ");
            scanf("%d", &cartas[i][j].populacao);

            printf("Área (em km²): ");
            scanf("%f", &cartas[i][j].area);

            printf("PIB (em bilhões de dólares): ");
            scanf("%f", &cartas[i][j].pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &cartas[i][j].pontos_turisticos);
        }
    }

    // Exibição dos dados das cartas
    printf("\nDados das cidades cadastradas:\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES_POR_ESTADO; j++) {
            printf("\nCidade %s:\n", cartas[i][j].codigo);
            printf("  População: %d habitantes\n", cartas[i][j].populacao);
            printf("  Área: %.2f km²\n", cartas[i][j].area);
            printf("  PIB: %.2f bilhões de dólares\n", cartas[i][j].pib);
            printf("  Pontos turísticos: %d\n", cartas[i][j].pontos_turisticos);
        }
    }

    return 0;
}