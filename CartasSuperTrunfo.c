#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    int codigo_postal;
    int pontos_turisticos;
    float população;
    float área;
    float PIB;
    char nome[10];
    
    printf("Digite o codigo_postal: \n");
    scanf("%d", &codigo_postal);

    printf("pontos_turisticos: \n");
    scanf("%d", &pontos_turisticos);

    printf("população: \n");
    scanf("%f", &população);

    printf("área: \n");
    scanf("%f", &área);

    printf("PIB: \n");
    scanf("%f", &PIB);
    
    printf("nome: \n");
    scanf("%s", &nome);
    
    return 0;
}
