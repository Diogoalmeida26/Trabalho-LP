#include "cliente.h"
#include <string.h>

// Arrays fixos para armazenar os dados dos clientes
int ids[MAX_CLIENTES];
char nomes[MAX_CLIENTES][TAM_NOME];
char contatos[MAX_CLIENTES][TAM_CONTATO];
char nifs[MAX_CLIENTES][TAM_NIF];
char datas_registro[MAX_CLIENTES][TAM_DATA];
int atividades[MAX_CLIENTES]; // Contador de encomendas para identificar clientes ativos
int total_clientes = 0;

// Criar um novo cliente
void criar_cliente(int id, const char nome[TAM_NOME], const char contato[TAM_CONTATO], const char nif[TAM_NIF], const char data[TAM_DATA]) {
    if (total_clientes < MAX_CLIENTES) {
        ids[total_clientes] = id;
        for (int i = 0; i < TAM_NOME; i++) {
            nomes[total_clientes][i] = nome[i];
            if (nome[i] == '\0') break;
        }
        for (int i = 0; i < TAM_CONTATO; i++) {
            contatos[total_clientes][i] = contato[i];
            if (contato[i] == '\0') break;
        }
        for (int i = 0; i < TAM_NIF; i++) {
            nifs[total_clientes][i] = nif[i];
            if (nif[i] == '\0') break;
        }
        for (int i = 0; i < TAM_DATA; i++) {
            datas_registro[total_clientes][i] = data[i];
            if (data[i] == '\0') break;
        }
        atividades[total_clientes] = 0;
        total_clientes++;
    }
}


// Listar todos os clientes
void listar_clientes(char lista[MAX_CLIENTES][TAM_NOME], int *quantidade) {
    *quantidade = total_clientes;
    for (int i = 0; i < total_clientes; i++) {
        for (int j = 0; j < TAM_NOME; j++) {
            lista[i][j] = nomes[i][j];
        }
    }
}

// Atualizar o contato de um cliente
void atualizar_cliente(int id, const char novo_contato[TAM_CONTATO]) {
    for (int i = 0; i < total_clientes; i++) {
        if (ids[i] == id) {
            for (int j = 0; j < TAM_CONTATO; j++) {
                contatos[i][j] = novo_contato[j];
                if (novo_contato[j] == '\0') break;
            }
            return;
        }
    }
}

// Excluir um cliente
void excluir_cliente(int id) {
    for (int i = 0; i < total_clientes; i++) {
        if (ids[i] == id) {
            for (int j = i; j < total_clientes - 1; j++) {
                ids[j] = ids[j + 1];
                for (int k = 0; k < TAM_NOME; k++) {
                    nomes[j][k] = nomes[j + 1][k];
                }
                for (int k = 0; k < TAM_CONTATO; k++) {
                    contatos[j][k] = contatos[j + 1][k];
                }
                for (int k = 0; k < TAM_NIF; k++) {
                    nifs[j][k] = nifs[j + 1][k];
                }
                for (int k = 0; k < TAM_DATA; k++) {
                    datas_registro[j][k] = datas_registro[j + 1][k];
                }
                atividades[j] = atividades[j + 1];
            }
            total_clientes--;
            return;
        }
    }
}

// Obter o total de clientes
int obter_total_clientes() {
    return total_clientes;
}


// Identificar os clientes mais ativos
void clientes_mais_ativos(char lista[MAX_CLIENTES][TAM_NOME], int *quantidade) {
    if (total_clientes == 0) {
        *quantidade = 0;
        return;
    }

    int maior_atividade = atividades[0];
    for (int i = 1; i < total_clientes; i++) {
        if (atividades[i] > maior_atividade) {
            maior_atividade = atividades[i];
        }
    }

    *quantidade = 0;
    for (int i = 0; i < total_clientes; i++) {
        if (atividades[i] == maior_atividade) {
            for (int j = 0; j < TAM_NOME; j++) {
                lista[*quantidade][j] = nomes[i][j];
            }
            (*quantidade)++;
        }
    }
}
// Renomeie a variável
int num_clientes = 0;


