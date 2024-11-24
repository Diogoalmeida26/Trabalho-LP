#include "cliente.h" // Incluir cliente.h para integrar funções

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
