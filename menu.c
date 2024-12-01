#include "menu.h"
#include "produto.h"
#include "cliente.h"
#include "input.h"

#include <stdio.h>

void menu_produtos() {
    int opcao, id, quantidade;
    char nome[TAM_NOME_PROD], categoria[TAM_CATEGORIA];
    char lista[MAX_PRODUTOS][TAM_NOME_PROD];
    int total;

    do {
        printf("\n--- Menu de Produtos ---\n");
        printf("1. Criar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Listar Produtos por Categoria\n");
        printf("4. Listar Produtos Menos Procurados\n");
        printf("5. Excluir Produto\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        clearInputBuffer(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                printf("ID: ");
                scanf("%d", &id);
                clearInputBuffer();
                printf("Nome: ");
                fgets(nome, TAM_NOME_PROD, stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove o newline
                printf("Categoria: ");
                fgets(categoria, TAM_CATEGORIA, stdin);
                categoria[strcspn(categoria, "\n")] = '\0';
                criar_produto(id, nome, categoria);
                break;

            case 2:
                listar_produtos(lista, &total);
                printf("Produtos:\n");
                for (int i = 0; i < total; i++) {
                    printf("%s\n", lista[i]);
                }
                break;

            case 3:
                printf("Categoria: ");
                fgets(categoria, TAM_CATEGORIA, stdin);
                categoria[strcspn(categoria, "\n")] = '\0';
                produtos_por_categoria(categoria, lista, &total);
                printf("Produtos na categoria %s:\n", categoria);
                for (int i = 0; i < total; i++) {
                    printf("%s\n", lista[i]);
                }
                break;

            case 4:
                produtos_menos_procurados(lista, &total);
                printf("Produtos menos procurados:\n");
                for (int i = 0; i < total; i++) {
                    printf("%s\n", lista[i]);
                }
                break;

            case 5:
                printf("ID do produto a excluir: ");
                scanf("%d", &id);
                clearInputBuffer();
                excluir_produto(id);
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

void menu_clientes() {
    int opcao, id;
    char nome[TAM_NOME], contato[TAM_CONTATO], nif[TAM_NIF], data[TAM_DATA];
    char lista[MAX_CLIENTES][TAM_NOME];
    int total;

    do {
        printf("\n--- Menu de Clientes ---\n");
        printf("1. Criar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Atualizar Cliente\n");
        printf("4. Excluir Cliente\n");
        printf("5. Listar Clientes Mais Ativos\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        clearInputBuffer();

        switch (opcao) {
            case 1:
                printf("ID: ");
                scanf("%d", &id);
                clearInputBuffer();
                printf("Nome: ");
                fgets(nome, TAM_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Contato: ");
                fgets(contato, TAM_CONTATO, stdin);
                contato[strcspn(contato, "\n")] = '\0';
                printf("NIF: ");
                fgets(nif, TAM_NIF, stdin);
                nif[strcspn(nif, "\n")] = '\0';
                printf("Data de Registro (dd/mm/aaaa): ");
                fgets(data, TAM_DATA, stdin);
                data[strcspn(data, "\n")] = '\0';
                criar_cliente(id, nome, contato, nif, data);
                break;

            case 2:
                listar_clientes(lista, &total);
                printf("Clientes:\n");
                for (int i = 0; i < total; i++) {
                    printf("%s\n", lista[i]);
                }
                break;

            case 3:
                printf("ID do cliente para atualizar: ");
                scanf("%d", &id);
                clearInputBuffer();
                printf("Novo Contato: ");
                fgets(contato, TAM_CONTATO, stdin);
                contato[strcspn(contato, "\n")] = '\0';
                atualizar_cliente(id, contato);
                break;

            case 4:
                printf("ID do cliente a excluir: ");
                scanf("%d", &id);
                clearInputBuffer();
                excluir_cliente(id);
                break;

            case 5:
                clientes_mais_ativos(lista, &total);
                printf("Clientes mais ativos:\n");
                for (int i = 0; i < total; i++) {
                    printf("%s\n", lista[i]);
                }
                break;

            case 0:
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}
