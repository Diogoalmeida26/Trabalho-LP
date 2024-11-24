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
void menu_encomenda() {
    int opcao;

    do {
        printf("\n--- Gestão de Encomendas ---\n");
        printf("1. Criar Encomenda\n");
        printf("2. Listar Encomendas\n");
        printf("3. Atualizar Encomenda\n");
        printf("4. Excluir Encomenda\n");
        printf("5. Listar Encomendas por Estado\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_encomenda();
                break;
            case 2:
                listar_encomendas();
                break;
            case 3:
                atualizar_encomenda();
                break;
            case 4:
                excluir_encomenda();
                break;
            case 5:
                listar_encomendas_por_estado();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
void menu_maquina() {
    int opcao;

    do {
        printf("\n--- Gestão de Máquinas ---\n");
        printf("1. Criar Máquina\n");
        printf("2. Listar Máquinas\n");
        printf("3. Atualizar Máquina\n");
        printf("4. Excluir Máquina\n");
        printf("5. Máquinas Mais Utilizadas\n");
        printf("6. Tempo Médio por Máquina\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_maquina();
                break;
            case 2:
                listar_maquinas();
                break;
            case 3:
                atualizar_maquina();
                break;
            case 4:
                excluir_maquina();
                break;
            case 5:
                maquinas_mais_utilizadas();
                break;
            case 6:
                tempo_medio_por_maquina();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}
