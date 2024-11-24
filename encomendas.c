#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "encomenda.h"

// Lista dinâmica de encomendas
Encomenda *encomendas = NULL;
int total_encomendas = 0;

// Função auxiliar para obter a data atual no formato "dd/mm/aaaa"
void obter_data_atual(char *data) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(data, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void criar_encomenda() {
    printf("\n--- Criar Encomenda ---\n");

    // Realocação dinâmica para uma nova encomenda
    encomendas = realloc(encomendas, (total_encomendas + 1) * sizeof(Encomenda));
    Encomenda *nova_encomenda = &encomendas[total_encomendas];
    nova_encomenda->id = total_encomendas + 1;

    // Associar a um cliente existente
    printf("ID do Cliente: ");
    scanf("%d", &nova_encomenda->id_cliente);

    // Obter a data de criação
    obter_data_atual(nova_encomenda->data_criacao);

    printf("Prioridade (Baixa, Média, Alta): ");
    scanf(" %[^\n]s", nova_encomenda->prioridade);

    strcpy(nova_encomenda->estado, "Aberta"); // Estado inicial
    nova_encomenda->taxa_cumprimento = 0.0;

    // Adicionar itens à encomenda
    printf("Número de Itens na Encomenda: ");
    scanf("%d", &nova_encomenda->num_itens);

    nova_encomenda->itens = malloc(nova_encomenda->num_itens * sizeof(ItemEncomenda));
    for (int i = 0; i < nova_encomenda->num_itens; i++) {
        printf("ID do Produto %d: ", i + 1);
        scanf("%d", &nova_encomenda->itens[i].id_produto);

        printf("Quantidade do Produto %d: ", i + 1);
        scanf("%d", &nova_encomenda->itens[i].quantidade);
    }

    total_encomendas++;
    printf("Encomenda criada com sucesso!\n");
}

void listar_encomendas() {
    printf("\n--- Lista de Encomendas ---\n");

    if (total_encomendas == 0) {
        printf("Nenhuma encomenda cadastrada.\n");
        return;
    }

    for (int i = 0; i < total_encomendas; i++) {
        Encomenda *e = &encomendas[i];
        printf("ID: %d | Cliente: %d | Data: %s | Prioridade: %s | Estado: %s | Progresso: %.2f%%\n",
               e->id, e->id_cliente, e->data_criacao, e->prioridade, e->estado, e->taxa_cumprimento);

        printf("Itens:\n");
        for (int j = 0; j < e->num_itens; j++) {
            printf("  Produto: %d | Quantidade: %d\n",
                   e->itens[j].id_produto, e->itens[j].quantidade);
        }
    }
}

void atualizar_encomenda() {
    printf("\n--- Atualizar Encomenda ---\n");
    int id;
    printf("Informe o ID da Encomenda para atualizar: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_encomendas) {
        printf("Encomenda não encontrada.\n");
        return;
    }

    Encomenda *e = &encomendas[id - 1];
    printf("Novo Estado (atual: %s): ", e->estado);
    scanf(" %[^\n]s", e->estado);

    if (strcmp(e->estado, "Finalizada") == 0) {
        e->taxa_cumprimento = 100.0;
    } else if (strcmp(e->estado, "Produção") == 0) {
        e->taxa_cumprimento = 50.0; // Exemplo de progresso padrão
    } else {
        e->taxa_cumprimento = 0.0;
    }

    printf("Encomenda atualizada com sucesso!\n");
}

void excluir_encomenda() {
    printf("\n--- Excluir Encomenda ---\n");
    int id;
    printf("Informe o ID da Encomenda para excluir: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_encomendas) {
        printf("Encomenda não encontrada.\n");
        return;
    }

    free(encomendas[id - 1].itens); // Liberar memória dos itens

    for (int i = id; i < total_encomendas; i++) {
        encomendas[i - 1] = encomendas[i];
    }

    total_encomendas--;
    encomendas = realloc(encomendas, total_encomendas * sizeof(Encomenda));

    printf("Encomenda excluída com sucesso!\n");
}

void listar_encomendas_por_estado() {
    printf("\n--- Encomendas por Estado ---\n");
    char estado[15];
    printf("Informe o estado (Aberta, Produção, Finalizada): ");
    scanf(" %[^\n]s", estado);

    for (int i = 0; i < total_encomendas; i++) {
        if (strcmp(encomendas[i].estado, estado) == 0) {
            printf("ID: %d | Cliente: %d | Data: %s | Prioridade: %s\n",
                   encomendas[i].id, encomendas[i].id_cliente, encomendas[i].data_criacao, encomendas[i].prioridade);
        }
    }
}
