#include <stdio.h>
#include <stdlib.h>
#include "produto.h" // Inclui as definições e funções de produtos

// Prototipação dos submenus
void menu_produto();

int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Gestão de Encomendas ---\n");
        printf("1. Gestão de Produtos\n");
        printf("2. Gestão de Clientes (Em Desenvolvimento)\n");
        printf("3. Gestão de Encomendas (Em Desenvolvimento)\n");
        printf("4. Gestão de Máquinas (Em Desenvolvimento)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menu_produto();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Submenu de Gestão de Produtos
void menu_produto() {
    int opcao;

    do {
        printf("\n--- Gestão de Produtos ---\n");
        printf("1. Criar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Atualizar Produto\n");
        printf("4. Excluir Produto\n");
        printf("5. Total de Produtos\n");
        printf("6. Produtos por Categoria\n");
        printf("7. Produtos Mais/Menos Procurados\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_produto();
                break;
            case 2:
                listar_produtos();
                break;
            case 3:
                atualizar_produto();
                break;
            case 4:
                excluir_produto();
                break;
            case 5:
                total_produtos();
                break;
            case 6:
                produtos_por_categoria();
                break;
            case 7:
                produtos_mais_menos_procurados();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
