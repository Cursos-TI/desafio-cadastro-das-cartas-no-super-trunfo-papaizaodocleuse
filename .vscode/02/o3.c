#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct Cidade {
    char codigo[4]; // Código da carta (ex: A01)
    long long populacao;
    double area;
    long long pib;
    int pontos_turisticos;
    double densidade_populacional; // Propriedade calculada
    double pib_per_capita;        // Propriedade calculada
    double super_poder;           // Soma de todas as propriedades
};

void calcularPropriedades(Cidade& cidade) {
    // Calcula a densidade populacional (população / área)
    if (cidade.area > 0) {
        cidade.densidade_populacional = cidade.populacao / cidade.area;
    } else {
        cidade.densidade_populacional = 0; // Evita divisão por zero
    }

    // Calcula o PIB per capita (PIB / população)
    if (cidade.populacao > 0) {
        cidade.pib_per_capita = static_cast<double>(cidade.pib) / cidade.populacao;
    } else {
        cidade.pib_per_capita = 0; // Evita divisão por zero
    }

    // Calcula o "Super Poder" (soma de todas as propriedades)
    cidade.super_poder = cidade.populacao + cidade.area + cidade.pib + cidade.pontos_turisticos +
                         cidade.densidade_populacional + cidade.pib_per_capita;
}

void cadastrarCidade(vector<Cidade>& cartas) {
    Cidade novaCidade;
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", novaCidade.codigo);
    printf("Digite a população da cidade: ");
    scanf("%lld", &novaCidade.populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%lf", &novaCidade.area);
    printf("Digite o PIB da cidade: ");
    scanf("%lld", &novaCidade.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &novaCidade.pontos_turisticos);

    // Calcula as propriedades
    calcularPropriedades(novaCidade);

    cartas.push_back(novaCidade);
}

void exibirCartas(const vector<Cidade>& cartas) {
    for (const auto& cidade : cartas) {
        printf("\nCódigo: %s\n", cidade.codigo);
        printf("População: %lld\n", cidade.populacao);
        printf("Área: %.2lf km²\n", cidade.area);
        printf("PIB: %lld\n", cidade.pib);
        printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
        printf("Densidade Populacional: %.2lf hab/km²\n", cidade.densidade_populacional);
        printf("PIB per capita: %.2lf\n", cidade.pib_per_capita);
        printf("Super Poder: %.2lf\n", cidade.super_poder);
    }
}

void compararCartas(const Cidade& carta1, const Cidade& carta2) {
    printf("\nComparando %s e %s:\n", carta1.codigo, carta2.codigo);

    // Comparação de densidade populacional (menor valor vence)
    printf("Densidade Populacional: ");
    if (carta1.densidade_populacional < carta2.densidade_populacional) {
        printf("%s vence!\n", carta1.codigo);
    } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
        printf("%s vence!\n", carta2.codigo);
    } else {
        printf("Empate!\n");
    }

    // Comparação de população (maior valor vence)
    printf("População: ");
    if (carta1.populacao > carta2.populacao) {
        printf("%s vence!\n", carta1.codigo);
    } else if (carta1.populacao < carta2.populacao) {
        printf("%s vence!\n", carta2.codigo);
    } else {
        printf("Empate!\n");
    }

    // Comparação de área (maior valor vence)
    printf("Área: ");
    if (carta1.area > carta2.area) {
        printf("%s vence!\n", carta1.codigo);
    } else if (carta1.area < carta2.area) {
        printf("%s vence!\n", carta2.codigo);
    } else {
        printf("Empate!\n");
    }

    // Comparação de PIB (maior valor vence)
    printf("PIB: ");
    if (carta1.pib > carta2.pib) {
        printf("%s vence!\n", carta1.codigo);
    } else if (carta1.pib < carta2.pib) {
        printf("%s vence!\n", carta2.codigo);
    } else {
        printf("Empate!\n");
    }

    // Comparação de pontos turísticos (maior valor vence)
    printf("Pontos Turísticos: ");
    if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
        printf("%s vence!\n", carta1.codigo);
    } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
        printf("%s vence!\n", carta2.codigo);
    } else {
        printf("Empate!\n");
    }

    // Comparação de PIB per capita (maior valor vence)
    printf("PIB per capita: ");
    if (carta1.pib_per_capita > carta2.pib_per_capita) {
        printf("%s vence!\n", carta1.codigo);
    } else if (carta1.pib_per_capita < carta2.pib_per_capita) {
        printf("%s vence!\n", carta2.codigo);
    } else {
        printf("Empate!\n");
    }

    // Comparação de Super Poder (maior valor vence)
    printf("Super Poder: ");
    if (carta1.super_poder > carta2.super_poder) {
        printf("%s vence!\n", carta1.codigo);
    } else if (carta1.super_poder < carta2.super_poder) {
        printf("%s vence!\n", carta2.codigo);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    vector<Cidade> cartas;
    char opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar nova carta\n");
        printf("2 - Exibir cartas cadastradas\n");
        printf("3 - Comparar duas cartas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarCidade(cartas);
                break;
            case '2':
                exibirCartas(cartas);
                break;
            case '3': {
                if (cartas.size() < 2) {
                    printf("É necessário cadastrar pelo menos duas cartas para comparar.\n");
                    break;
                }
                int indice1, indice2;
                printf("Digite o índice da primeira carta (0 a %zu): ", cartas.size() - 1);
                scanf("%d", &indice1);
                printf("Digite o índice da segunda carta (0 a %zu): ", cartas.size() - 1);
                scanf("%d", &indice2);

                if (indice1 < 0 || indice1 >= cartas.size() || indice2 < 0 || indice2 >= cartas.size()) {
                    printf("Índices inválidos!\n");
                    break;
                }

                compararCartas(cartas[indice1], cartas[indice2]);
                break;
            }
            case '4':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != '4');

    return 0;
}