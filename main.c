#include <stdio.h>
#include <stdlib.h>
#include "produto.h" 
#include "cliente.h"


void menu_produto();
void menu_cliente();

int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Gestão de Encomendas ---\n");
        printf("1. Gestão de Produtos\n");
        printf("2. Gestão de Clientes\n");
        printf("3. Gestão de Encomendas\n");
        printf("4. Gestão de Máquinas (Em Desenvolvimento)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menu_produto();
                break;
            case 2:
                menu_cliente();
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
void menu_cliente() {
    int opcao;

    do {
        printf("\n--- Gestão de Clientes ---\n");
        printf("1. Criar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Atualizar Cliente\n");
        printf("4. Excluir Cliente\n");
        printf("5. Total de Clientes\n");
        printf("6. Clientes Mais Ativos\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_cliente();
                break;
            case 2:
                listar_clientes();
                break;
            case 3:
                atualizar_cliente();
                break;
            case 4:
                excluir_cliente();
                break;
            case 5:
                total_clientes();
                break;
            case 6:
                clientes_mais_ativos();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
