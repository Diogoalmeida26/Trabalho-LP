#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"

// Lista dinâmica de clientes
Cliente *clientes = NULL;
int total_clientes_cadastrados = 0;

// Função auxiliar para obter a data atual no formato "dd/mm/aaaa"
void obter_data_atual(char *data) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(data, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void criar_cliente() {
    printf("\n--- Criar Cliente ---\n");

    // Realocação dinâmica para um novo cliente
    clientes = realloc(clientes, (total_clientes_cadastrados + 1) * sizeof(Cliente));
    Cliente *novo_cliente = &clientes[total_clientes_cadastrados];
    novo_cliente->id = total_clientes_cadastrados + 1;

    printf("Nome do Cliente: ");
    scanf(" %[^\n]s", novo_cliente->nome);

    printf("Contato (E-mail ou Telefone): ");
    scanf(" %[^\n]s", novo_cliente->contato);

    printf("NIF (Número de Identificação Fiscal): ");
    scanf(" %[^\n]s", novo_cliente->nif);

    // Geração automática da data de registro
    obter_data_atual(novo_cliente->data_registro);

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
        Cliente *c = &clientes[i];
        printf("ID: %d | Nome: %s | Contato: %s | NIF: %s | Data de Registro: %s\n", 
               c->id, c->nome, c->contato, c->nif, c->data_registro);
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

    Cliente *c = &clientes[id - 1];
    printf("Novo Nome (atual: %s): ", c->nome);
    scanf(" %[^\n]s", c->nome);

    printf("Novo Contato (atual: %s): ", c->contato);
    scanf(" %[^\n]s", c->contato);

    printf("Novo NIF (atual: %s): ", c->nif);
    scanf(" %[^\n]s", c->nif);

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

    for (int i = id; i < total_clientes_cadastrados; i++) {
        clientes[i - 1] = clientes[i];
    }

    total_clientes_cadastrados--;
    clientes = realloc(clientes, total_clientes_cadastrados * sizeof(Cliente));

    printf("Cliente excluído com sucesso!\n");
}

void total_clientes() {
    printf("\nTotal de Clientes Cadastrados: %d\n", total_clientes_cadastrados);
}

void clientes_mais_ativos() {
    printf("\n--- Clientes Mais Ativos ---\n");
    printf("Função em desenvolvimento.\n");
    // A lógica será baseada no número de encomendas associadas a cada cliente
    // quando o módulo Encomenda for implementado.
}
