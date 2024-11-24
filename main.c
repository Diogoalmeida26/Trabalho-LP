#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "cliente.h"
#include "encomenda.h"

// Prototipação dos submenus
void menu_produto();
void menu_cliente();
void menu_encomenda();

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
            case 3:
                menu_encomenda();
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
