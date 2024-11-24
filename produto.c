#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

// Lista dinâmica de produtos
Produto *produtos = NULL;
int total_produtos_cadastrados = 0;

void criar_produto() {
    printf("\n--- Criar Produto ---\n");

    // Realocação dinâmica para um novo produto
    produtos = realloc(produtos, (total_produtos_cadastrados + 1) * sizeof(Produto));

    Produto *novo_produto = &produtos[total_produtos_cadastrados];
    novo_produto->id = total_produtos_cadastrados + 1;

    printf("Nome do Produto: ");
    scanf(" %[^\n]s", novo_produto->nome);

    printf("Categoria do Produto: ");
    scanf(" %[^\n]s", novo_produto->categoria);

    printf("Número de Processos: ");
    scanf("%d", &novo_produto->num_processos);

    // Alocação para processos
    novo_produto->processos = malloc(novo_produto->num_processos * sizeof(Processo));

    for (int i = 0; i < novo_produto->num_processos; i++) {
        printf("ID da Máquina para o Processo %d: ", i + 1);
        scanf("%d", &novo_produto->processos[i].id_maquina);

        printf("Tempo de Execução (minutos): ");
        scanf("%d", &novo_produto->processos[i].tempo_execucao);
    }

    total_produtos_cadastrados++;
    printf("Produto cadastrado com sucesso!\n");
}

void listar_produtos() {
    printf("\n--- Lista de Produtos ---\n");
    if (total_produtos_cadastrados == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (int i = 0; i < total_produtos_cadastrados; i++) {
        Produto *p = &produtos[i];
        printf("ID: %d | Nome: %s | Categoria: %s\n", p->id, p->nome, p->categoria);
        printf("Processos:\n");

        for (int j = 0; j < p->num_processos; j++) {
            printf("  Máquina: %d | Tempo: %d minutos\n", 
                   p->processos[j].id_maquina, 
                   p->processos[j].tempo_execucao);
        }
    }
}

void atualizar_produto() {
    printf("\n--- Atualizar Produto ---\n");
    int id;
    printf("Informe o ID do Produto para atualizar: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_produtos_cadastrados) {
        printf("Produto não encontrado.\n");
        return;
    }

    Produto *p = &produtos[id - 1];
    printf("Novo Nome (atual: %s): ", p->nome);
    scanf(" %[^\n]s", p->nome);

    printf("Nova Categoria (atual: %s): ", p->categoria);
    scanf(" %[^\n]s", p->categoria);

    printf("Número de Processos (atual: %d): ", p->num_processos);
    int novos_processos;
    scanf("%d", &novos_processos);

    if (novos_processos != p->num_processos) {
        free(p->processos); // Liberar memória atual
        p->processos = malloc(novos_processos * sizeof(Processo));
        p->num_processos = novos_processos;
    }

    for (int i = 0; i < p->num_processos; i++) {
        printf("ID da Máquina para o Processo %d: ", i + 1);
        scanf("%d", &p->processos[i].id_maquina);

        printf("Tempo de Execução (minutos): ");
        scanf("%d", &p->processos[i].tempo_execucao);
    }

    printf("Produto atualizado com sucesso!\n");
}

void excluir_produto() {
    printf("\n--- Excluir Produto ---\n");
    int id;
    printf("Informe o ID do Produto para excluir: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_produtos_cadastrados) {
        printf("Produto não encontrado.\n");
        return;
    }

    // Liberar memória dos processos associados
    free(produtos[id - 1].processos);

    for (int i = id; i < total_produtos_cadastrados; i++) {
        produtos[i - 1] = produtos[i];
    }

    total_produtos_cadastrados--;
    produtos = realloc(produtos, total_produtos_cadastrados * sizeof(Produto));

    printf("Produto excluído com sucesso!\n");
}

void total_produtos() {
    printf("\nTotal de Produtos Cadastrados: %d\n", total_produtos_cadastrados);
}

void produtos_por_categoria() {
    printf("\n--- Produtos por Categoria ---\n");
    if (total_produtos_cadastrados == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    char categoria[20];
    printf("Informe a categoria: ");
    scanf(" %[^\n]s", categoria);

    for (int i = 0; i < total_produtos_cadastrados; i++) {
        Produto *p = &produtos[i];
        if (strcmp(p->categoria, categoria) == 0) {
            printf("ID: %d | Nome: %s\n", p->id, p->nome);
        }
    }
}

void produtos_mais_menos_procurados() {
    printf("\n--- Produtos Mais e Menos Procurados ---\n");
    // Placeholder para análise (não implementado por falta de dados de "procura").
    printf("Função em desenvolvimento.\n");
}
