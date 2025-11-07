#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --------- Constantes Globais -------------
#define MAX_TERRITORIOS 5
#define TAM_STRING 30

// 1. Definição da Estrutura (struct) para o Território
typedef struct {
    char nome[TAM_STRING];
    char cor_do_exercito[TAM_STRING];
    int quant_tropas;
} Territorio;


int main() {
    // 2. Declaração do Array de Estruturas
    Territorio grupo[MAX_TERRITORIOS];
    int i;

    printf("BEM VINDO AO JOGO WAR EM LINGUAGEM C - ESTÁCIO - 2oSem2025\n\n");
    printf("--- VAMOS COMEÇAR CADASTRANDO OS %d TERRITÓRIOS DO JOGO ---\n\n", MAX_TERRITORIOS);

    // 3. Loop para o Cadastro dos grupos
    for (i = 0; i < MAX_TERRITORIOS; i++) {
                        
        // Nome do grupo
        printf("\nInforme o nome do %dº Território: ", i + 1);
        // %49s para não ultrapassar o tamanho de 50 caracteres
        // & comercial não é necessário para arrays de char (strings)
        scanf("%49s", grupo[i].nome);
        
        // Cor do exército
        printf("Informe a Cor do Exército do %dº Território: ", i + 1);
        scanf("%49s", grupo[i].cor_do_exercito);
        
        // Quantidade de tropas
        printf("Informe a Quantidade de Tropas do %dº Território: ", i + 1);
        // Note o & comercial para variáveis do tipo int
        scanf("%d", &grupo[i].quant_tropas);
        
        while(getchar() != '\n'); 
    }

    // 4. Print dos Territórios Cadastrados
    printf("\n--- Territórios Cadastrados ---\n");
    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("  Nome: %s\n", grupo[i].nome);
        printf("  Cor do Exército: %s\n", grupo[i].cor_do_exercito);
        printf("  Quant de Tropas: %d\n", grupo[i].quant_tropas);
    }

    return 0;
}