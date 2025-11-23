#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --------- Definição da estrutura --------
typedef struct territorio {
    char nome[30];
    char cor_do_exercito[30];
    int quant_de_tropas;
} Territorio;

//Limpar o buffer de entrada
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ---------- Função de ataque ------------
void atacar(Territorio* atacante, Territorio* defensor) {

repetir_ataque:  // usando repetição em caso de empate

    if (atacante->quant_de_tropas <= 1) {
        printf("O território atacante precisa ter mais de 1 tropa para atacar!\n");
        return;
    }

    printf("\n===== INÍCIO DO ATAQUE =====\n");
    printf("%s (%s) ATACANDO %s (%s)\n",
           atacante->nome, atacante->cor_do_exercito,
           defensor->nome, defensor->cor_do_exercito);

    int dado_atq = (rand() % 6) + 1;
    int dado_def = (rand() % 6) + 1;

    printf("Dado do atacante: %d\n", dado_atq);
    printf("Dado do defensor: %d\n", dado_def);

    // EMPATE → repete o ataque
    if (dado_atq == dado_def) {
        printf("Empate! Jogando os dados novamente...\n");
        goto repetir_ataque;
    }

    // ATACANTE VENCE
    if (dado_atq > dado_def) {
        printf("RESULTADO: Atacante venceu o combate!\n");

        atacante->quant_de_tropas += 1;  // bônus
        defensor->quant_de_tropas -= 1;  // perda

        // DEFENSOR PERDE TODAS AS TROPAS → CONQUISTA
        if (defensor->quant_de_tropas <= 0) {
            printf("O defensor perdeu todas as tropas! Território conquistado!\n");

            strcpy(defensor->cor_do_exercito, atacante->cor_do_exercito);

            defensor->quant_de_tropas = 1; // tropa inicial do território conquistado
            atacante->quant_de_tropas -= 1; // atacante envia 1 tropa para ocupar
        }
    }
    // DEFENSOR VENCE
    else {
        printf("RESULTADO: Defensor venceu o combate!\n");

        defensor->quant_de_tropas += 1; // bônus
        atacante->quant_de_tropas -= 1; // perda

        // ATACANTE PERDE TODAS AS TROPAS → DEFENSOR CONQUISTA
        if (atacante->quant_de_tropas <= 0) {
            printf("O atacante perdeu todas as tropas! Território conquistado pelo defensor!\n");

            strcpy(atacante->cor_do_exercito, defensor->cor_do_exercito);

            atacante->quant_de_tropas = 1;
            defensor->quant_de_tropas -= 1;
        }
    }

    printf("\n===== SITUAÇÃO PÓS-ATAQUE =====\n");
    printf("Atacante -> %s | Tropas: %d | Cor: %s\n",
           atacante->nome, atacante->quant_de_tropas, atacante->cor_do_exercito);

    printf("Defensor -> %s | Tropas: %d | Cor: %s\n",
           defensor->nome, defensor->quant_de_tropas, defensor->cor_do_exercito);

    printf("=================================\n");
}

// ---------- FUNÇÃO PRINCIPAL ----------
int main() {
    srand(time(NULL));

    int total_territorios;
    Territorio* grupo;
    int opcao;

    printf("=======================================\n");
    printf("BEM VINDO AO JOGO WAR EM LINGUAGEM C!\n");
    printf("=======================================\n");

    // -------- PERMITIR O USUÁRIO ESCOLHER QUANTOS TERRITÓRIOS O JOGO VAI TER --------
    do {
        printf("Informe quantos territórios o jogo vai ter (mínimo 2 e máximo 5): ");
        scanf("%d", &total_territorios);
        limparBufferEntrada();

        if (total_territorios < 2 || total_territorios > 5) {
            printf("Valor inválido! Digite um número entre 2 e 5.\n\n");
        }

    } while (total_territorios < 2 || total_territorios > 5);
    // ---------------------------------------

    // ----------- USANDO ALOCAÇÃO DINÂMICA COM MALLOC -----------
    grupo = (Territorio*) malloc(total_territorios * sizeof(Territorio));
    if (grupo == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    int cadastrados = 0;

    // ------------------- MENU DE OPÇÕES -------------------
    do {
        printf("\n=======================================\n");
        printf("LISTA DE OPÇÕES\n");
        printf("=======================================\n");
        printf("1 - Cadastrar novo território\n");
        printf("2 - Listar territórios\n");
        printf("3 - Simular ataque\n");
        printf("0 - Sair\n");
        printf("=======================================\n");
        printf("ESCOLHA UMA OPÇÃO: ");
        
        char entrada[20];
        fgets(entrada, sizeof(entrada), stdin);
        if (sscanf(entrada, "%d", &opcao) != 1) {
            opcao = -1;
        }

        switch (opcao) {

        case 1:
            if (cadastrados < total_territorios) {
                printf("--- Cadastro de Novo Território ---\n\n");

                printf("Nome do território: ");
                fgets(grupo[cadastrados].nome, 30, stdin);

                printf("Cor do exército: ");
                fgets(grupo[cadastrados].cor_do_exercito, 30, stdin);

                grupo[cadastrados].nome[strcspn(grupo[cadastrados].nome, "\n")] = '\0';
                grupo[cadastrados].cor_do_exercito[strcspn(grupo[cadastrados].cor_do_exercito, "\n")] = '\0';

                printf("Quantidade de tropas: ");
                scanf("%d", &grupo[cadastrados].quant_de_tropas);
                limparBufferEntrada();

                cadastrados++;

                printf("\nTerritório cadastrado com sucesso!\n");
            } else {
                printf("Limite máximo de territórios atingido!\n");
            }

            printf("Pressione ENTER para continuar...");
            getchar();
            break;

        case 2:
            printf("\n----- LISTA DE TERRITÓRIOS -----\n");

            if (cadastrados == 0) {
                printf("Nenhum território cadastrado!\n");
            } else {
                for (int i = 0; i < cadastrados; i++) {
                    printf("\nTERRITÓRIO %d\n", i + 1);
                    printf("Nome: %s\n", grupo[i].nome);
                    printf("Cor: %s\n", grupo[i].cor_do_exercito);
                    printf("Tropas: %d\n", grupo[i].quant_de_tropas);
                }
            }

            printf("\nPressione ENTER para continuar...");
            getchar();
            break;

        // -------------------------- CASE 3 MODIFICADO --------------------------
        case 3: // ATAQUE
            if (cadastrados < 2) {
                printf("Cadastre ao menos 2 territórios para simular ataques!\n\n");
                printf("Pressione ENTER para continuar...");
                getchar();
                break;
            }

            // ---- LISTAR TERRITÓRIOS DISPONÍVEIS PARA ATAQUE ----
            printf("\n----- TERRITÓRIOS DISPONÍVEIS -----\n");

            for (int i = 0; i < cadastrados; i++) {
                printf("%d - %s | Cor: %s | Tropas: %d\n",
                       i + 1,
                       grupo[i].nome,
                       grupo[i].cor_do_exercito,
                       grupo[i].quant_de_tropas);
            }

            printf("-------------------------------------\n\n");

            int a, d;

            printf("Escolha o número do território ATACANTE: ");
            scanf("%d", &a);
            limparBufferEntrada();

            printf("Escolha o número do território DEFENSOR: ");
            scanf("%d", &d);
            limparBufferEntrada();

            if (a < 1 || a > cadastrados || d < 1 || d > cadastrados) {
                printf("Território inválido!\n");
                printf("Pressione ENTER para continuar...");
                getchar();
                break;
            }

            if (a == d) {
                printf("Um território não pode atacar ele mesmo!\n");
                printf("Pressione ENTER para continuar...");
                getchar();
                break;
            }

            atacar(&grupo[a - 1], &grupo[d - 1]);

            printf("\nPressione ENTER para continuar...");
            getchar();
            break;
        // -----------------------------------------------------------------------

        case 0:
            printf("Saindo do jogo...\n");
            printf("Pressione ENTER para finalizar...");
            getchar();
            break;

        default:
            printf("Opção inválida!\n");
            printf("Pressione ENTER para continuar...");
            getchar();
            break;
        }

    } while (opcao != 0);

    free(grupo);
    return 0;
}
