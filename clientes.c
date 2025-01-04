#include "cliente.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Array estático para armazenar os clientes e o contador de clientes
Cliente clientes[MAX_CLIENTES];
int total_clientes_cadastrados = 0;

// Inicializa o sistema de clientes
void inicializar_clientes() {
    total_clientes_cadastrados = 0;
    for (int i = 0; i < MAX_CLIENTES; i++) {
        clientes[i].id = -1;
        strcpy(clientes[i].nome, "");
        strcpy(clientes[i].telemovel, "");
        strcpy(clientes[i].nif, "");
        clientes[i].data_registro.dia = 0;
        clientes[i].data_registro.mes = 0;
        clientes[i].data_registro.ano = 0;
        clientes[i].atividades = 0;
    }
}

// Cria um novo cliente
void criar_cliente() {
    if (total_clientes_cadastrados >= MAX_CLIENTES) {
        puts("Erro: Limite de clientes atingido.");
        return;
    }

    Cliente novo_cliente;
    novo_cliente.id = total_clientes_cadastrados + 1;

    readString(novo_cliente.nome, TAM_NOME, "Digite o nome do cliente: ");
    lerNumeroNaoZero(novo_cliente.telemovel, "Digite o número de telemóvel (9 dígitos, sem começar com 0): ");
    lerNumeroNaoZero(novo_cliente.nif, "Digite o NIF (9 dígitos, sem começar com 0): ");

    printf("Digite a data de registro (dd mm aaaa): ");
    novo_cliente.data_registro.dia = getInt(1, 31, "");
    novo_cliente.data_registro.mes = getInt(1, 12, "");
    novo_cliente.data_registro.ano = getInt(1900, 2100, "");

    novo_cliente.atividades = 0;

    clientes[total_clientes_cadastrados] = novo_cliente;
    total_clientes_cadastrados++;
    puts("Cliente cadastrado com sucesso!");
}

// Lista todos os clientes
void listar_clientes() {
    if (total_clientes_cadastrados == 0) {
        puts("Nenhum cliente cadastrado.");
        return;
    }

    puts("\n--- Lista de Clientes ---");
    for (int i = 0; i < total_clientes_cadastrados; i++) {
        Cliente c = clientes[i];
        printf("ID: %d | Nome: %s | Telemóvel: %s | NIF: %s | Data de Registro: %02d/%02d/%04d | Encomendas: %d\n",
               c.id, c.nome, c.telemovel, c.nif,
               c.data_registro.dia, c.data_registro.mes, c.data_registro.ano,
               c.atividades);
    }
}

// Atualiza os dados de um cliente
void atualizar_cliente() {
    int id = getInt(1, total_clientes_cadastrados, "Digite o ID do cliente que deseja atualizar: ");
    for (int i = 0; i < total_clientes_cadastrados; i++) {
        if (clientes[i].id == id) {
            readString(clientes[i].nome, TAM_NOME, "Digite o novo nome do cliente: ");
            lerNumeroNaoZero(clientes[i].telemovel, "Digite o novo número de telemóvel (9 dígitos, sem começar com 0): ");
            puts("Dados do cliente atualizados com sucesso!");
            return;
        }
    }
    puts("Erro: Cliente não encontrado.");
}

// Exclui um cliente
void excluir_cliente() {
    int id = getInt(1, total_clientes_cadastrados, "Digite o ID do cliente que deseja excluir: ");
    for (int i = 0; i < total_clientes_cadastrados; i++) {
        if (clientes[i].id == id) {
            // Reorganiza o array, movendo os elementos seguintes para a esquerda
            for (int j = i; j < total_clientes_cadastrados - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            total_clientes_cadastrados--;
            puts("Cliente excluído com sucesso!");
            return;
        }
    }
    puts("Erro: Cliente não encontrado.");
}

// Exibe o total de clientes cadastrados
void total_clientes() {
    printf("Total de clientes cadastrados: %d\n", total_clientes_cadastrados);
}

// Lista os clientes mais ativos
void clientes_mais_ativos() {
    if (total_clientes_cadastrados == 0) {
        puts("Nenhum cliente cadastrado.");
        return;
    }

    int maior_atividade = clientes[0].atividades;
    for (int i = 1; i < total_clientes_cadastrados; i++) {
        if (clientes[i].atividades > maior_atividade) {
            maior_atividade = clientes[i].atividades;
        }
    }

    puts("\n--- Clientes Mais Ativos ---");
    for (int i = 0; i < total_clientes_cadastrados; i++) {
        if (clientes[i].atividades == maior_atividade) {
            printf("ID: %d | Nome: %s | Telemóvel: %s | Encomendas: %d\n",
                   clientes[i].id, clientes[i].nome, clientes[i].telemovel, clientes[i].atividades);
        }
    }
}
