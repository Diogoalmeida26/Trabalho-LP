#include "menu.h"
#include <stdio.h>
#include "input.h"

int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Gestão de Encomendas ---\n");
        printf("1. Menu de Produtos\n");
        printf("2. Menu de Clientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        cleanInputBuffer();
        switch (opcao) {
            case 1:
                menu_produtos();
                break;

            case 2:
                menu_clientes();
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
