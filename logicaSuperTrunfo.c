#include <stdio.h>
#include <string.h>

// Declaração de funções auxiliares
double calcular_densidade_populacional(int populacao, float area_em_km2);
double calcular_pib_per_capita(int populacao, float pib);
float calcular_super_poder(unsigned long int populacao, int numero_de_pontos_turisticos, float area_em_km2, float pib, double pib_per_capta, double densidade_populacional);

// Declaração de funções de comparação
int comparar_densidade_populacional(double densidade_populacional1, double densidade_populacional2);
int comparar_pib_per_capita(double pib_per_capita1, double pib_per_capita2);
int comparar_numero_de_pontos_turisticos(int numero_de_pontos_turisticos1, int numero_de_pontos_turisticos2);
int comparar_pib(float pib1, float pib2);
int comparar_area(float area1, float area2);
int comparar_populacao(unsigned long int populacao1, unsigned long int populacao2);

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Variáveis da carta 1
    char estado1, codigo_da_carta1[10], nome_da_cidade1[20];
    int numero_de_pontos_turisticos1;
    float area1_em_km2, pib1;
    unsigned long int populacao1;

    // Variáveis da carta 2
    char estado2, codigo_da_carta2[10], nome_da_cidade2[20];
    int numero_de_pontos_turisticos2;
    float area2_em_km2, pib2;
    unsigned long int populacao2;


    // Introdução
    printf("Cadastro de cartas do super trunfo\n");
    printf("------------------------------\n");
    printf("Teremos oito estados no jogo, que serão representados pelas letras de A até H.\n");
    printf("Para cada estado, você deverá informar o nome da cidade, a população, a área, o número de pontos turísticos e o PIB.\n");
    printf("O jogo será composto por 32 cartas, quatro para cada estado.\n");
    printf("O código das cartas será composto pela letra do estado e um número de 01 a 04.\n");
    printf("------------------------------\n");
    
    printf("\nCadastro da primeira carta\n");
    printf("------------------------------\n");
    printf("Informe o estado (letra de A até H): ");
    scanf("%c", &estado1);
    getchar(); // Limpa o buffer de leitura do caractere
    printf("Informe o código da carta: ");
    scanf("%s", codigo_da_carta1);
    getchar(); // Limpa o buffer de leitura da string
    printf("Informe o nome da cidade: ");
    fgets(nome_da_cidade1, 20, stdin);
    printf("Informe a população: ");
    scanf("%d", &populacao1);
    getchar(); // Limpa o buffer de leitura do inteiro
    printf("Informe a área em km2: ");
    scanf("%f", &area1_em_km2);
    getchar(); // Limpa o buffer de leitura do float
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &numero_de_pontos_turisticos1);
    getchar(); // Limpa o buffer de leitura do inteiro
    printf("Informe o PIB (em bilhões): ");
    scanf("%f", &pib1);
    getchar(); // Limpa o buffer de leitura do float

    nome_da_cidade1[strcspn(nome_da_cidade1, "\n")] = '\0'; // Remove o caractere de nova linha do final da string
    printf("------------------------------\n");

    // Cálculo da densidade populacional e do pib per capita
    double densidade_populacional1 = calcular_densidade_populacional(populacao1, area1_em_km2);
    double pib_per_capta1 = calcular_pib_per_capita(populacao1, pib1);

    // Cálculo do super poder
    float super_poder1 = calcular_super_poder(populacao1, numero_de_pontos_turisticos1, area1_em_km2, pib1, pib_per_capta1, densidade_populacional1);


    printf("\nCadastro da segunda carta\n");
    printf("------------------------------\n");
    printf("Informe o estado (letra de A até H): ");
    scanf("%c", &estado2);
    getchar(); // Limpa o buffer de leitura do caractere
    printf("Informe o código da carta: ");
    scanf("%s", codigo_da_carta2);
    getchar(); // Limpa o buffer de leitura da string
    printf("Informe o nome da cidade: ");
    fgets(nome_da_cidade2, 20, stdin);
    printf("Informe a população: ");
    scanf("%d", &populacao2);
    getchar(); // Limpa o buffer de leitura do inteiro
    printf("Informe a área em km2: ");
    scanf("%f", &area2_em_km2);
    getchar(); // Limpa o buffer de leitura do float
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &numero_de_pontos_turisticos2);
    getchar(); // Limpa o buffer de leitura do inteiro
    printf("Informe o PIB (em bilhões): ");
    scanf("%f", &pib2);
    getchar(); // Limpa o buffer de leitura do float
    
    nome_da_cidade2[strcspn(nome_da_cidade2, "\n")] = '\0'; // Remove o caractere de nova linha do final da string
    printf("------------------------------\n");

    // Cálculo da densidade populacional e do pib per capita
    double densidade_populacional2 = calcular_densidade_populacional(populacao2, area2_em_km2);
    double pib_per_capta2 = calcular_pib_per_capita(populacao2, pib2);

        // Cálculo do super poder
    float super_poder2 = calcular_super_poder(populacao2, numero_de_pontos_turisticos2, area2_em_km2, pib2, pib_per_capta2, densidade_populacional2);


    // Impressão da carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código da carta: %s\n", codigo_da_carta1);
    printf("Nome da cidade: %s\n", nome_da_cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km2\n", area1_em_km2);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de pontos turísticos: %d\n", numero_de_pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capta1);
    printf("\n");

    // Impressão da carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código da carta: %s\n", codigo_da_carta2);
    printf("Nome da cidade: %s\n", nome_da_cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km2\n", area2_em_km2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de pontos turísticos: %d\n", numero_de_pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capta2);
    printf("\n");
    
    printf("\n");

    printf("Comparação de cartas (Atributo: População):\n");
    printf("\n");

    printf("Carta 1 - %s : %Ld\n", nome_da_cidade1, populacao1);
    printf("Carta 2 - %s : %Ld\n", nome_da_cidade2, populacao2);

    int resultado = comparar_populacao(populacao1, populacao2);

    if(resultado == 1) {
        printf("Resultado: Carta 1 (%s) venceu!", nome_da_cidade1);
    } else if (resultado == 2) {
        printf("Resultado: Carta 2 (%s) venceu!", nome_da_cidade2);
    } else if(resultado == 0) {
        printf("EMPATE!");
    }

    printf("\n");
    printf("\n");

    return 0;
}


// Funções auxiliares

// Calcular a densidade populacional 
double calcular_densidade_populacional(int populacao, float area_em_km2) {
    
    return (double) populacao / area_em_km2;
}

// Calcular PIB per Capita
double calcular_pib_per_capita(int populacao,  float pib) {

    // PIB em reais
    double pib_em_reais = pib * 1000000000;

    return (double) (pib_em_reais / populacao);
}

// Calcular super poderes
float calcular_super_poder(unsigned long int populacao, int numero_de_pontos_turisticos, float area_em_km2, float pib, double pib_per_capta, double densidade_populacional ) {

    return (float) populacao + numero_de_pontos_turisticos + area_em_km2 + pib + pib_per_capta - densidade_populacional;

}

// Funções de comparação

int comparar_populacao(unsigned long int populacao1, unsigned long int populacao2) {

    if(populacao1 > populacao2) {
        return 1;
    } else if ( populacao2 > populacao1) {
        return 2;
    } else {
        return 0;
    }
}

int comparar_area(float area1, float area2) {

    if(area1 > area2) {
        return 1;
    } else if ( area2 > area1) {
        return 2;
    } else {
        return 0;
    }
}

int comparar_pib(float pib1, float pib2) {

    if(pib1 > pib2) {
        return 1;
    } else if ( pib2 > pib1) {
        return 2;
    } else {
        return 0;
    }
}

int comparar_numero_de_pontos_turisticos(int numero_de_pontos_turisticos1, int numero_de_pontos_turisticos2) {

    if(numero_de_pontos_turisticos1 > numero_de_pontos_turisticos2) {
        return 1;
    } else if ( numero_de_pontos_turisticos2 > numero_de_pontos_turisticos1) {
        return 2;
    } else {
        return 0;
    }
}

int comparar_pib_per_capita(double pib_per_capita1, double pib_per_capita2) {

    if(pib_per_capita1 > pib_per_capita2) {
        return 1;
    } else if ( pib_per_capita2 > pib_per_capita1) {
        return 2;
    } else {
        return 0;
    }
}

int comparar_densidade_populacional(double densidade_populacional1, double densidade_populacional2) {

    if(densidade_populacional1 < densidade_populacional2) {
        return 1;
    } else if ( densidade_populacional2 < densidade_populacional1) {
        return 2;
    } else {
        return 0;
    }
}

