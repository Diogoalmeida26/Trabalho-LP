#include <stdio.h>
#include "encomendas.h"

// Arrays para armazenar informações das encomendas
int encomenda_ids[MAX_ENCOMENDAS];
int encomenda_clientes[MAX_ENCOMENDAS];
char encomenda_datas_criacao[MAX_ENCOMENDAS][TAM_DATA];
int encomenda_prioridades[MAX_ENCOMENDAS]; // 0: Baixa, 1: Média, 2: Alta
int encomenda_estados[MAX_ENCOMENDAS]; // 0: Aberta, 1: Produção, 2: Finalizada
float encomenda_taxas_cumprimento[MAX_ENCOMENDAS];
int total_encomendas_registradas = 0;

// Função para criar uma nova encomenda
void criar_encomenda(int cliente_id, const char data[TAM_DATA], int prioridade) {
    if (total_encomendas_registradas < MAX_ENCOMENDAS) {
        int index = total_encomendas_registradas;
        encomenda_ids[index] = index + 1;
        encomenda_clientes[index] = cliente_id;

        for (int i = 0; i < TAM_DATA; i++) {
            encomenda_datas_criacao[index][i] = data[i];
            if (data[i] == '\0') break;
        }

        encomenda_prioridades[index] = prioridade;
        encomenda_estados[index] = 0; // Estado inicial: Aberta
        encomenda_taxas_cumprimento[index] = 0.0;

        total_encomendas_registradas++;
    }
}

// Função para listar todas as encomendas
void listar_encomendas(char lista[MAX_ENCOMENDAS][TAM_DATA], int *quantidade) {
    *quantidade = total_encomendas_registradas;
    for (int i = 0; i < total_encomendas_registradas; i++) {
        for (int j = 0; j < TAM_DATA; j++) {
            lista[i][j] = encomenda_datas_criacao[i][j];
        }
    }
}

// Função para listar encomendas por estado
void encomendas_por_estado(int estado, int ids_filtrados[MAX_ENCOMENDAS], int *quantidade) {
    *quantidade = 0;
    for (int i = 0; i < total_encomendas_registradas; i++) {
        if (encomenda_estados[i] == estado) {
            ids_filtrados[*quantidade] = encomenda_ids[i];
            (*quantidade)++;
        }
    }
}

// Função para atualizar o estado de uma encomenda
void atualizar_encomenda(int id, int novo_estado, float nova_taxa) {
    if (id > 0 && id <= total_encomendas_registradas) {
        int index = id - 1;
        encomenda_estados[index] = novo_estado;
        if (novo_estado == 2) { // Finalizada
            encomenda_taxas_cumprimento[index] = 100.0;
        } else if (novo_estado == 1) { // Em Produção
            encomenda_taxas_cumprimento[index] = nova_taxa;
        }
    }
}

// Função para excluir uma encomenda
void excluir_encomenda(int id) {
    if (id > 0 && id <= total_encomendas_registradas) {
        for (int i = id - 1; i < total_encomendas_registradas - 1; i++) {
            encomenda_ids[i] = encomenda_ids[i + 1];
            encomenda_clientes[i] = encomenda_clientes[i + 1];

            for (int j = 0; j < TAM_DATA; j++) {
                encomenda_datas_criacao[i][j] = encomenda_datas_criacao[i + 1][j];
            }

            encomenda_prioridades[i] = encomenda_prioridades[i + 1];
            encomenda_estados[i] = encomenda_estados[i + 1];
            encomenda_taxas_cumprimento[i] = encomenda_taxas_cumprimento[i + 1];
        }
        total_encomendas_registradas--;
    }
}

// Função para gerar relatório de estados
void relatorio_encomendas_por_estado(int *abertas, int *producao, int *finalizadas) {
    *abertas = 0;
    *producao = 0;
    *finalizadas = 0;
    for (int i = 0; i < total_encomendas_registradas; i++) {
        if (encomenda_estados[i] == 0) (*abertas)++;
        else if
