#include <stdio.h>

// Declaração de funções auxiliares
double calcular_densidade_populacional(unsigned long int populacao, float area_em_km2);
double calcular_pib_per_capita(unsigned long int populacao, float pib);
float calcular_super_poder(unsigned long int populacao, int numero_de_pontos_turisticos, float area_em_km2, float pib, double pib_per_capita, double densidade_populacional);

// Declaração de funções de comparação
int comparar_densidade_populacional(double densidade_populacional1, double densidade_populacional2);
int comparar_pib_per_capita(double pib_per_capita1, double pib_per_capita2);
int comparar_numero_de_pontos_turisticos(int numero_de_pontos_turisticos1, int numero_de_pontos_turisticos2);
int comparar_pib(float pib1, float pib2);
int comparar_area(float area1, float area2);
int comparar_populacao(unsigned long int populacao1, unsigned long int populacao2);

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas

/*
    A função main, é a principal, no momento suas responsabilidades são:

    - Armazenar os dados de cada carta
    - Mostrar as regras
    - Mostrar cada carta
    - Mostrar menu para seleção de atributo
    - Realiza as comparações e exibe o resultado

*/ 
int main() {
    // Dados da carta 1
    char estado1 = 'A';
    char codigo_da_carta1[10] = "A01";
    char nome_da_cidade1[20] = "São Paulo";
    int numero_de_pontos_turisticos1 = 50;
    float area1_em_km2 = 1521.00;
    float pib1 = 3103.33;
    unsigned long int populacao1 = 12300000;

    // Dados da carta 2
    char estado2 = 'B';
    char codigo_da_carta2[10] = "B01";
    char nome_da_cidade2[20] = "Rio de Janeiro";
    int numero_de_pontos_turisticos2 = 30;
    float area2_em_km2 = 1200.00;
    float pib2 = 1103.50;
    unsigned long int populacao2 = 6000000;

    // Variáveis importantes (geral)
    int opcao;
    int resultado;

    // Introdução
    printf("Regras do super trunfo\n");
    printf("------------------------------\n");
    printf("Você deve selecionar um atributo de sua carta, o valor desse atributo será comparado com o mesmo atributo da carta do adversário.\n");
    printf("1. O maior valor vence.\n");
    printf("ATENÇÃO - No caso do atributo 'Densidade Populacional' o menor valor irá vencer.\n");
    printf("------------------------------\n");
    
    // Cálculo da densidade populacional e do pib per capita (cidade 1)
    double densidade_populacional1 = calcular_densidade_populacional(populacao1, area1_em_km2);
    double pib_per_capita1 = calcular_pib_per_capita(populacao1, pib1);

    // Cálculo do super poder(cidade 1)
    float super_poder1 = calcular_super_poder(populacao1, numero_de_pontos_turisticos1, area1_em_km2, pib1, pib_per_capita1, densidade_populacional1);

    // Cálculo da densidade populacional e do pib per capita (cidade 2)
    double densidade_populacional2 = calcular_densidade_populacional(populacao2, area2_em_km2);
    double pib_per_capita2 = calcular_pib_per_capita(populacao2, pib2);

    // Cálculo do super poder (cidade 2)
    float super_poder2 = calcular_super_poder(populacao2, numero_de_pontos_turisticos2, area2_em_km2, pib2, pib_per_capita2, densidade_populacional2);

    // Impressão da carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código da carta: %s\n", codigo_da_carta1);
    printf("Nome da cidade: %s\n", nome_da_cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km2\n", area1_em_km2);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de pontos turísticos: %d\n", numero_de_pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("\n");

    // Impressão da carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código da carta: %s\n", codigo_da_carta2);
    printf("Nome da cidade: %s\n", nome_da_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km2\n", area2_em_km2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de pontos turísticos: %d\n", numero_de_pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("\n");
    
    printf("\n");

    printf("Vamos jogar!!\n");
    printf("Escolha o atributo com o qual deseja jogar: \n");
    printf("------------------------------\n");
    printf("\n");
    printf("(1) - População\n");
    printf("(2) - Área\n");
    printf("(3) - PIB\n");
    printf("(4) - Número de pontos turísticos\n");
    printf("(5) - Densidade populacional\n");
    printf("\n");
    printf("------------------------------\n");
    
    printf("->");
    scanf("%d", &opcao);    

    printf("\n");

    switch (opcao){
        case 1:
            printf("Atributo escolhido: População\n");            
            printf("Carta 1 - %s : %lu\n", nome_da_cidade1, populacao1);
            printf("Carta 2 - %s : %lu\n", nome_da_cidade2, populacao2);
                    
            resultado = comparar_populacao(populacao1, populacao2);

            if(resultado == 1) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
            } else if (resultado == 2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
            } else if(resultado == 0) {
                printf("EMPATE!\n");
            }
            break;
        case 2:
            printf("Atributo escolhido: Área\n");            
            printf("Carta 1 - %s : %.2f\n", nome_da_cidade1, area1_em_km2);
            printf("Carta 2 - %s : %.2f\n", nome_da_cidade2, area2_em_km2);
                    
            resultado = comparar_area(area1_em_km2, area2_em_km2);

            if(resultado == 1) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
            } else if (resultado == 2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
            } else if(resultado == 0) {
                printf("EMPATE!\n");
            }
            break;
        case 3:
            printf("Atributo escolhido: PIB\n");            
            printf("Carta 1 - %s : %.2f\n", nome_da_cidade1, pib1);
            printf("Carta 2 - %s : %.2f\n", nome_da_cidade2, pib2);
                    
            resultado = comparar_pib(pib1, pib2);

            if(resultado == 1) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
            } else if (resultado == 2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
            } else if(resultado == 0) {
                printf("EMPATE!\n");
            }
            break;
        case 4:
            printf("Atributo escolhido: Número de pontos turísticos\n");            
            printf("Carta 1 - %s : %d\n", nome_da_cidade1, numero_de_pontos_turisticos1);
            printf("Carta 2 - %s : %d\n", nome_da_cidade2, numero_de_pontos_turisticos2);
                    
            resultado = comparar_numero_de_pontos_turisticos(numero_de_pontos_turisticos1, numero_de_pontos_turisticos2);

            if(resultado == 1) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
            } else if (resultado == 2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
            } else if(resultado == 0) {
                printf("EMPATE!\n");
            }
            break;
        case 5:
            printf("Atributo escolhido: Densidade populacional\n");            
            printf("Carta 1 - %s : %.2f\n", nome_da_cidade1, densidade_populacional1);
            printf("Carta 2 - %s : %.2f\n", nome_da_cidade2, densidade_populacional2);
                    
            resultado = comparar_densidade_populacional(densidade_populacional1, densidade_populacional2);

            if(resultado == 1) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
            } else if (resultado == 2) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
            } else if(resultado == 0) {
                printf("EMPATE!\n");
            }
            break;
        default:
            printf("Opção desconhecida! Escolha apenas uma opção dentre as presentes no menu\n");
            break;
    }

    printf("\n");
    printf("\n");

    return 0;
}


// Funções auxiliares

// Calcular a densidade populacional 
double calcular_densidade_populacional(unsigned long int populacao, float area_em_km2) {
    
    return (double) populacao / area_em_km2;
}

// Calcular PIB per Capita
double calcular_pib_per_capita(unsigned long int populacao,  float pib) {

    // PIB em reais
    double pib_em_reais = pib * 1000000000;

    return (double) (pib_em_reais / populacao);
}

// Calcular super poderes
float calcular_super_poder(unsigned long int populacao, int numero_de_pontos_turisticos, float area_em_km2, float pib, double pib_per_capita, double densidade_populacional ) {

    return (float) populacao + numero_de_pontos_turisticos + area_em_km2 + pib + pib_per_capita - densidade_populacional;

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
