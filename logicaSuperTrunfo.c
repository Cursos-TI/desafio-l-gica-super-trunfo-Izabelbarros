#include <stdio.h>   // Para entrada e saída de dados (printf, scanf)
#include <stdlib.h>  // Para funções de propósito geral, como system()
#include <string.h>  // Para manipulação de strings (strcpy)

// Definindo uma estrutura para representar uma carta de cidade
typedef struct {
    char estado[50];         // Nome do estado
    int codigoCarta;         // Código de identificação da carta
    char nomeCidade[100];    // Nome da cidade
    long long populacao;     // População da cidade
    double area;             // Área da cidade em km²
    double pib;              // PIB da cidade em bilhões de reais
    int pontosTuristicos;    // Número de pontos turísticos
    double densidadePopulacional; // Densidade populacional (calculada)
} CartaCidade;

// Função para exibir as informações de uma carta
void exibirCarta(CartaCidade carta) {
    printf("--- Informacoes da Carta: %s ---\n", carta.nomeCidade);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo da Carta: %d\n", carta.codigoCarta);
    printf("Populacao: %lld habitantes\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: R$ %.2f bilhoes\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidadePopulacional);
    printf("---------------------------------------\n\n");
}

int main() {
    CartaCidade carta1, carta2; // Duas variáveis do tipo CartaCidade

    // --- Cadastro da Primeira Carta ---
    printf("--- Cadastro da Primeira Carta de Cidade ---\n");
    printf("Informe o estado da cidade: ");
    scanf(" %[^\n]", carta1.estado); // Lê a string até a quebra de linha
    printf("Informe o codigo da carta: ");
    scanf("%d", &carta1.codigoCarta);
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("Informe a populacao da cidade: ");
    scanf("%lld", &carta1.populacao);
    printf("Informe a area da cidade (em km2): ");
    scanf("%lf", &carta1.area);
    printf("Informe o PIB da cidade (em bilhoes de reais): ");
    scanf("%lf", &carta1.pib);
    printf("Informe o numero de pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    // Calcula a densidade populacional
    if (carta1.area > 0) { // Evita divisão por zero
        carta1.densidadePopulacional = (double)carta1.populacao / carta1.area;
    } else {
        carta1.densidadePopulacional = 0.0;
    }

    printf("\n"); // Adiciona uma linha em branco

    // --- Cadastro da Segunda Carta ---
    printf("--- Cadastro da Segunda Carta de Cidade ---\n");
    printf("Informe o estado da cidade: ");
    scanf(" %[^\n]", carta2.estado);
    printf("Informe o codigo da carta: ");
    scanf("%d", &carta2.codigoCarta);
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("Informe a populacao da cidade: ");
    scanf("%lld", &carta2.populacao);
    printf("Informe a area da cidade (em km2): ");
    scanf("%lf", &carta2.area);
    printf("Informe o PIB da cidade (em bilhoes de reais): ");
    scanf("%lf", &carta2.pib);
    printf("Informe o numero de pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    // Calcula a densidade populacional
    if (carta2.area > 0) { // Evita divisão por zero
        carta2.densidadePopulacional = (double)carta2.populacao / carta2.area;
    } else {
        carta2.densidadePopulacional = 0.0;
    }

    // Exibe as cartas cadastradas
    printf("\n--- Cartas Cadastradas ---\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // --- Comparação das Cartas ---
    // Escolha a propriedade para comparação aqui (descomente uma das opções)
    // Para este exemplo, vamos comparar por População.

    // Compara por População (maior valor vence)
    printf("--- Comparacao Baseada na POPULACAO (Maior Valor Vence) ---\n");
    if (carta1.populacao > carta2.populacao) {
        printf("A carta '%s' venceu (Populacao: %lld)!\n", carta1.nomeCidade, carta1.populacao);
    } else if (carta2.populacao > carta1.populacao) {
        printf("A carta '%s' venceu (Populacao: %lld)!\n", carta2.nomeCidade, carta2.populacao);
    } else {
        printf("Empate na populacao! Ambas as cartas tem %lld habitantes.\n", carta1.populacao);
    }
    printf("\n");

    // Exemplo de comparação por Área (maior valor vence)
    printf("--- Comparacao Baseada na AREA (Maior Valor Vence) ---\n");
    if (carta1.area > carta2.area) {
        printf("A carta '%s' venceu (Area: %.2f km2)!\n", carta1.nomeCidade, carta1.area);
    } else if (carta2.area > carta1.area) {
        printf("A carta '%s' venceu (Area: %.2f km2)!\n", carta2.nomeCidade, carta2.area);
    } else {
        printf("Empate na area! Ambas as cartas tem %.2f km2.\n", carta1.area);
    }
    printf("\n");

    // Exemplo de comparação por PIB (maior valor vence)
    printf("--- Comparacao Baseada no PIB (Maior Valor Vence) ---\n");
    if (carta1.pib > carta2.pib) {
        printf("A carta '%s' venceu (PIB: R$ %.2f bilhoes)!\n", carta1.nomeCidade, carta1.pib);
    } else if (carta2.pib > carta1.pib) {
        printf("A carta '%s' venceu (PIB: R$ %.2f bilhoes)!\n", carta2.nomeCidade, carta2.pib);
    } else {
        printf("Empate no PIB! Ambas as cartas tem R$ %.2f bilhoes.\n", carta1.pib);
    }
    printf("\n");

    // Exemplo de comparação por Pontos Turísticos (maior valor vence)
    printf("--- Comparacao Baseada nos PONTOS TURISTICOS (Maior Valor Vence) ---\n");
    if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
        printf("A carta '%s' venceu (Pontos Turisticos: %d)!\n", carta1.nomeCidade, carta1.pontosTuristicos);
    } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
        printf("A carta '%s' venceu (Pontos Turisticos: %d)!\n", carta2.nomeCidade, carta2.pontosTuristicos);
    } else {
        printf("Empate em pontos turisticos! Ambas as cartas tem %d.\n", carta1.pontosTuristicos);
    }
    printf("\n");

    // Compara por Densidade Populacional (MENOR valor vence)
    printf("--- Comparacao Baseada na DENSIDADE POPULACIONAL (Menor Valor Vence) ---\n");
    if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
        printf("A carta '%s' venceu (Densidade: %.2f hab/km2)!\n", carta1.nomeCidade, carta1.densidadePopulacional);
    } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
        printf("A carta '%s' venceu (Densidade: %.2f hab/km2)!\n", carta2.nomeCidade, carta2.densidadePopulacional);
    } else {
        printf("Empate na densidade populacional! Ambas as cartas tem %.2f hab/km2.\n", carta1.densidadePopulacional);
    }
    printf("\n");

    return 0; // Retorna 0 para indicar sucesso
}