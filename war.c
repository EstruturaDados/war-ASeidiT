#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------- Constantes Globais -------------
#define MAX_TERRITORIOS 5
#define TAM_STRING 30

// --------- Definição da estrutura (struct) --------
struct Territorio {
    char nome[TAM_STRING];
    char cor_do_exercito[TAM_STRING];
    int quant_de_tropas;
}

// ------- Função principal (main) ---
;int main(){
    
    struct Territorio grupo[MAX_TERRITORIOS];
    int total_territorios = 0;
    int opcao;

    // ------ Laço Principal do Menu ------
    
        // -------- Exibe o menu de opções -----
        printf("=======================================\n");
        printf("CADASTRO DE TERRITÓRIOS\n");
        printf("=======================================\n");
        printf("ESCOLHA UMA OPÇÃO:\n");
        printf("1 - Cadastrar novo território\n");
        printf("2 - Listar todos os territórios\n");
        printf("0 - Sair\n");
        printf("=======================================\n");

        // --- Lê a opção do jogador ---
        scanf("%d", &opcao);
 
        // ----- Processamento da opção -----
        switch (opcao) {
        case 1: // Cadastro de novo território
            printf("--- Cadastro de Novo Território ---\n\n");

            if (total_territorios < MAX_TERRITORIOS) {
                printf("Digite o nome do território:\n");
                fgets(grupo[total_territorios].nome, TAM_STRING, stdin);

                printf("Digite a cor do exército:\n");
                fgets(grupo[total_territorios].cor_do_exercito, TAM_STRING, stdin);

                printf("Informe a quantidade de tropas:\n");
                scanf("%d", &grupo[total_territorios].quant_de_tropas);

                total_territorios++;

                printf("Território cadastrado com sucesso!\n");
            } else {
                printf("Número máximo de territórios cadastrados!\n");
            }

            printf("\nPressione Enter para continuar...");
            getchar(); // --- Pausa para o jogador ler a mensagem antes de voltar ao menu ---                        
            break;
        
        case 2: // ------- Listagem de territórios --------
            printf("Lista de territórios cadastrados:\n\n");

            if (total_territorios == 0)
            {
                printf("Nenhum território cadastrado!\n");
                getchar();
                
            } else {
                for (int i = 0; i < total_territorios; i++)
                {
                    printf("------------------------------\n");
                    printf("Nome: %s\n", grupo[i].nome);
                    printf("Cor do exército: %s\n", grupo[i].cor_do_exercito);
                    printf("Quantidade de tropas: %d\n", grupo[i].quant_de_tropas);
                }
                printf("------------------------------\n");                
            }
            
            printf("\nPressione Enter para continuar...");
            getchar(); // --- Pausa para o jogador ler a mensagem antes de voltar ao menu ---                        
            break;
        
        case 0: // ------ SAIR -------
            printf("Saindo do sistema...\n");
            break;
        
        default: // ------ Opção inválida -------
            printf("\nOpção inválida! Tente novamente...\n");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        }


return 0;
};