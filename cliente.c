#include <stdio.h>
#include "cliente.h"

// Variáveis globais específicas deste arquivo
int cliente_ids[MAX_CLIENTES];
char cliente_nomes[MAX_CLIENTES][TAM_NOME];
char cliente_contatos[MAX_CLIENTES][TAM_CONTATO];
char cliente_nifs[MAX_CLIENTES][TAM_NIF];
char cliente_datas_registro[MAX_CLIENTES][TAM_DATA];
int total_clientes_cadastrados = 0;

void criar_cliente() {
    if (total_clientes_cadastrados >= MAX_CLIENTES) {
        printf("Limite máximo de clientes alcançado.\n");
        return;
    }

    cliente_ids[total_clientes_cadastrados] = total_clientes_cadastrados + 1;

    printf("\n--- Criar Cliente ---\n");
    printf("Nome do Cliente: ");
    scanf(" %[^\n]s", cliente_nomes[total_clientes_cadastrados]);

    printf("Contato (E-mail ou Telefone): ");
    scanf(" %[^\n]s", cliente_contatos[total_clientes_cadastrados]);

    printf("NIF (Número de Identificação Fiscal): ");
    scanf(" %[^\n]s", cliente_nifs[total_clientes_cadastrados]);

    printf("Data de Registro (dd/mm/aaaa): ");
    scanf(" %[^\n]s", cliente_datas_registro[total_clientes_cadastrados]);

    total_clientes_cadastrados++;
    printf("Cliente cadastrado com sucesso!\n");
}

void listar_clientes() {
    printf("\n--- Lista de Clientes ---\n");

    if (total_clientes_cadastrados == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    for (int i = 0; i < total_clientes_cadastrados; i++) {
        printf("ID: %d | Nome: %s | Contato: %s | NIF: %s | Data de Registro: %s\n",
               cliente_ids[i], cliente_nomes[i], cliente_contatos[i], cliente_nifs[i], cliente_datas_registro[i]);
    }
}

void atualizar_cliente() {
    printf("\n--- Atualizar Cliente ---\n");
    int id;
    printf("Informe o ID do Cliente para atualizar: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_clientes_cadastrados) {
        printf("Cliente não encontrado.\n");
        return;
    }

    printf("Novo Nome (atual: %s): ", cliente_nomes[id - 1]);
    scanf(" %[^\n]s", cliente_nomes[id - 1]);

    printf("Novo Contato (atual: %s): ", cliente_contatos[id - 1]);
    scanf(" %[^\n]s", cliente_contatos[id - 1]);

    printf("Novo NIF (atual: %s): ", cliente_nifs[id - 1]);
    scanf(" %[^\n]s", cliente_nifs[id - 1]);

    printf("Nova Data de Registro (atual: %s): ", cliente_datas_registro[id - 1]);
    scanf(" %[^\n]s", cliente_datas_registro[id - 1]);

    printf("Cliente atualizado com sucesso!\n");
}

void excluir_cliente() {
    printf("\n--- Excluir Cliente ---\n");
    int id;
    printf("Informe o ID do Cliente para excluir: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_clientes_cadastrados) {
        printf("Cliente não encontrado.\n");
        return;
    }

    for (int i = id - 1; i < total_clientes_cadastrados - 1; i++) {
        cliente_ids[i] = cliente_ids[i + 1];
        for (int j = 0; j < TAM_NOME; j++) {
            cliente_nomes[i][j] = cliente_nomes[i + 1][j];
        }
        for (int j = 0; j < TAM_CONTATO; j++) {
            cliente_contatos[i][j] = cliente_contatos[i + 1][j];
        }
        for (int j = 0; j < TAM_NIF; j++) {
            cliente_nifs[i][j] = cliente_nifs[i + 1][j];
        }
        for (int j = 0; j < TAM_DATA; j++) {
            cliente_datas_registro[i][j] = cliente_datas_registro[i + 1][j];
        }
    }

    total_clientes_cadastrados--;
    printf("Cliente excluído com sucesso!\n");
}

void total_clientes() {
    printf("\nTotal de Clientes Cadastrados: %d\n", total_clientes_cadastrados);
}

void clientes_mais_ativos() {
    printf("\n--- Clientes Mais Ativos ---\n");
    printf("Função em desenvolvimento.\n");
}
