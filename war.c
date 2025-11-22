#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------- Constantes Globais -------------
#define MAX_TERRITORIOS 5
#define TAM_STRING 30

// --------- Definição da estrutura (struct) --------
struct territorio {
    char nome[TAM_STRING];
    char cor_do_exercito[TAM_STRING];
    int quant_de_tropas;
};

//Limpar o buffer de entrada
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ------- Função principal (main) ---
int main(){
    struct territorio grupo[MAX_TERRITORIOS];
    int total_territorios = 0;
    int opcao;

    // ------ Laço Principal do Menu ------
    do {
        // -------- Exibe o menu de opções -----
        printf("=======================================\n");
        printf("BEM VINDO AO JOGO WAR EM LINGUAGEM C!\n\n");
        printf("CADASTRO DE TERRITÓRIOS\n");
        printf("=======================================\n");
        printf("OPÇÕES:\n");
        printf("1 - Cadastrar novo território\n");
        printf("2 - Listar todos os territórios\n");
        printf("0 - Sair\n");
        printf("=======================================\n");
        printf("ESCOLHA UMA OPÇÃO: ");

        // --- Lê a opção do jogador ---
        scanf("%d", &opcao);
        limparBufferEntrada(); //Limpa o '\n' deixado pelo scanf
 
        // ----- Processamento da opção -----
        switch (opcao) {
            case 1: // Cadastro de novo território
                printf("--- Cadastro de Novo Território ---\n\n");

                if (total_territorios < MAX_TERRITORIOS) {
                    printf("Digite o nome do território (SEM ACENTOS OU CARACTERES ESPECIAIS): ");
                    fgets(grupo[total_territorios].nome, TAM_STRING, stdin);

                    printf("Digite a cor do exército: ");
                    fgets(grupo[total_territorios].cor_do_exercito, TAM_STRING, stdin);

                    grupo[total_territorios].nome[strcspn(grupo[total_territorios].nome, "\n")] = '\0';
                    grupo[total_territorios].cor_do_exercito[strcspn(grupo[total_territorios].cor_do_exercito, "\n")] = '\0';

                    printf("Informe a quantidade de tropas: ");
                    scanf("%d", &grupo[total_territorios].quant_de_tropas);
                    limparBufferEntrada();

                    total_territorios++;

                    printf("\nTerritório cadastrado com sucesso!\n");
            } else {
                printf("Número máximo de territórios cadastrados!\n");
            }

            printf("\nPressione ENTER para continuar...");
            getchar(); // --- Pausa para o jogador ler a mensagem antes de voltar ao menu ---                        
            break;
        
        case 2: // ------- Listagem de territórios --------
            printf("Lista de territórios cadastrados:\n\n");

            if (total_territorios == 0){
                printf("Nenhum território cadastrado!\n");
            }
            else {
                for (int i = 0; i < total_territorios; i++){
                    printf("------------------------------\n");
                    printf("TERRITÓRIO %d\n", i+1);
                    printf("Nome: %s\n", grupo[i].nome);
                    printf("Cor do exército: %s\n", grupo[i].cor_do_exercito);
                    printf("Quantidade de tropas: %d\n", grupo[i].quant_de_tropas);
                }
                printf("------------------------------\n");                
            }
            
            //Pausa para o jogador ler, antes do próximo loop limpar a tela
            printf("\nPressione ENTER para continuar...");
            getchar(); // --- Pausa para o jogador ler a mensagem antes de voltar ao menu ---                        
            break;
        
        case 0: // ------ SAIR -------
            printf("\nSaindo do jogo...\n");
            break;
        
        default: // ------ Opção inválida -------
            printf("\nOpção inválida! Tente novamente...\n");
            printf("\nPressione ENTER para continuar...");
            getchar();
            break;
        }
    
    }while (opcao != 0);
    
    return 0;
};