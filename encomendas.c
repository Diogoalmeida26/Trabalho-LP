#include <stdio.h>
#include "encomendas.h"

// Variáveis 
int encomenda_ids[MAX_ENCOMENDAS];
int encomenda_clientes[MAX_ENCOMENDAS];
char encomenda_datas_criacao[MAX_ENCOMENDAS][TAM_DATA];
int encomenda_prioridades[MAX_ENCOMENDAS]; // 0: Baixa, 1: Média, 2: Alta
int encomenda_estados[MAX_ENCOMENDAS]; // 0: Aberta, 1: Produção, 2: Finalizada
float encomenda_taxas_cumprimento[MAX_ENCOMENDAS];
int total_encomendas_registradas = 0;

void criar_encomenda() {
    if (total_encomendas_registradas >= MAX_ENCOMENDAS) {
        printf("Limite máximo de encomendas alcançado.\n");
        return;
    }

    printf("\n--- Criar Encomenda ---\n");
    encomenda_ids[total_encomendas_registradas] = total_encomendas_registradas + 1;

    printf("ID do Cliente: ");
    scanf("%d", &encomenda_clientes[total_encomendas_registradas]);

    printf("Prioridade (0: Baixa, 1: Média, 2: Alta): ");
    scanf("%d", &encomenda_prioridades[total_encomendas_registradas]);

    encomenda_estados[total_encomendas_registradas] = 0; // Estado inicial: Aberta
    encomenda_taxas_cumprimento[total_encomendas_registradas] = 0.0;

    printf("Data de Criação (dd/mm/aaaa): ");
    scanf("%s", encomenda_datas_criacao[total_encomendas_registradas]);

    total_encomendas_registradas++;
    printf("Encomenda criada com sucesso!\n");
}

void listar_encomendas() {
    printf("\n--- Lista de Encomendas ---\n");

    if (total_encomendas_registradas == 0) {
        printf("Nenhuma encomenda registrada.\n");
        return;
    }

    for (int i = 0; i < total_encomendas_registradas; i++) {
        printf("ID: %d | Cliente: %d | Data: %s | Prioridade: %d | Estado: %d | Taxa: %.2f%%\n",
               encomenda_ids[i], encomenda_clientes[i], encomenda_datas_criacao[i],
               encomenda_prioridades[i], encomenda_estados[i], encomenda_taxas_cumprimento[i]);
    }
}

void atualizar_encomenda() {
    printf("\n--- Atualizar Encomenda ---\n");
    int id;
    printf("Informe o ID da Encomenda para atualizar: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_encomendas_registradas) {
        printf("Encomenda não encontrada.\n");
        return;
    }

    printf("Novo Estado (0: Aberta, 1: Produção, 2: Finalizada): ");
    scanf("%d", &encomenda_estados[id - 1]);

    if (encomenda_estados[id - 1] == 2) { // finalizada
        encomenda_taxas_cumprimento[id - 1] = 100.0;
    } else if (encomenda_estados[id - 1] == 1) { //  Em produção
        printf("Informe a nova Taxa de Cumprimento (0-99): ");
        scanf("%f", &encomenda_taxas_cumprimento[id - 1]);
    }

    printf("Encomenda atualizada com sucesso!\n");
}

void excluir_encomenda() {
    printf("\n--- Excluir Encomenda ---\n");
    int id;
    printf("Informe o ID da Encomenda para excluir: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_encomendas_registradas) {
        printf("Encomenda não encontrada.\n");
        return;
    }

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
    printf("Encomenda excluída com sucesso!\n");
}

void relatorio_encomendas_por_estado() {
    int abertas = 0, producao = 0, finalizadas = 0;

    for (int i = 0; i < total_encomendas_registradas; i++) {
        if (encomenda_estados[i] == 0) abertas++;
        else if (encomenda_estados[i] == 1) producao++;
        else if (encomenda_estados[i] == 2) finalizadas++;
    }

    printf("\n--- Relatório de Encomendas por Estado ---\n");
    printf("Abertas: %d | Produção: %d | Finalizadas: %d\n", abertas, producao, finalizadas);
}
   
}
