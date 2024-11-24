#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipação de funções principais
void menu_produto();
void menu_cliente();
void menu_encomenda();
void menu_maquina();

int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Gestão de Encomendas ---\n");
        printf("1. Gestão de Produtos\n");
        printf("2. Gestão de Clientes\n");
        printf("3. Gestão de Encomendas\n");
        printf("4. Gestão de Máquinas\n");
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
            case 4:
                menu_maquina();
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
