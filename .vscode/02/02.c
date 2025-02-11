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
    double densidade_populacional; // Nova propriedade calculada
    double pib_per_capita;        // Nova propriedade calculada
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

    // Calcula as novas propriedades
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
    }
}

int main() {
    vector<Cidade> cartas;
    char opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar nova carta\n");
        printf("2 - Exibir cartas cadastradas\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarCidade(cartas);
                break;
            case '2':
                exibirCartas(cartas);
                break;
            case '3':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != '3');

    return 0;
}