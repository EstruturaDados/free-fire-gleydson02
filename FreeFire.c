#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// ===== STRUCT DO ITEM =====
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
} Item;


// ===== FUNÇÃO PARA LISTAR ITENS =====
void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    printf("\n===== ITENS NA MOCHILA =====\n");
    printf("%-20s %-20s %-10s\n", "Nome", "Tipo", "Quantidade");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < total; i++) {
        printf("%-20s %-20s %-10d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}


// ===== FUNÇÃO PARA REMOVER ITEM =====
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf("\nNão há itens para remover.\n");
        return;
    }

    char nomeRemover[50];
    printf("\nDigite o nome do item que deseja remover: ");
    getchar(); // limpa buffer
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    int encontrado = -1;

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item não encontrado!\n");
        return;
    }

    // desloca todos para "tapar o buraco"
    for (int i = encontrado; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--;

    printf("Item removido com sucesso!\n");
}


// ===== MAIN =====
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;

    int opcao;

    do {
        printf("\n===== MENU - MOCHILA FREE FIRE =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: {
                if (total >= MAX_ITENS) {
                    printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
                    break;
                }

                getchar(); // limpa \n após scanf

                printf("\nNome do item: ");
                fgets(mochila[total].nome, sizeof(mochila[total].nome), stdin);
                mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0';

                printf("Tipo do item: ");
                fgets(mochila[total].tipo, sizeof(mochila[total].tipo), stdin);
                mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = '\0';

                printf("Quantidade: ");
                scanf("%d", &mochila[total].quantidade);

                total++;
                printf("Item adicionado com sucesso!\n");
                break;
            }

            case 2:
                removerItem(mochila, &total);
                break;

            case 3:
                listarItens(mochila, total);
                break;

            case 0:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}