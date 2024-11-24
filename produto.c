#include <stdio.h>
#include "produto.h"

// Definições das variáveis 
int produto_ids[MAX_PRODUTOS];
char produto_nomes[MAX_PRODUTOS][TAM_NOME_PROD];
char produto_categorias[MAX_PRODUTOS][TAM_CATEGORIA];
int produto_quantidades[MAX_PRODUTOS];
float produto_precos[MAX_PRODUTOS];
int total_produtos_cadastrados = 0;

void criar_produto() {
    if (total_produtos_cadastrados >= MAX_PRODUTOS) {
        printf("Limite máximo de produtos alcançado.\n");
        return;
    }

    produto_ids[total_produtos_cadastrados] = total_produtos_cadastrados + 1;

    printf("\n--- Criar Produto ---\n");
    printf("Nome do Produto: ");
    scanf(" %[^\n]s", produto_nomes[total_produtos_cadastrados]);

    printf("Categoria do Produto: ");
    scanf(" %[^\n]s", produto_categorias[total_produtos_cadastrados]);

    printf("Quantidade em Estoque: ");
    scanf("%d", &produto_quantidades[total_produtos_cadastrados]);

    printf("Preço do Produto: ");
    scanf("%f", &produto_precos[total_produtos_cadastrados]);

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
        printf("ID: %d | Nome: %s | Categoria: %s | Quantidade: %d | Preço: %.2f\n",
               produto_ids[i], produto_nomes[i], produto_categorias[i],
               produto_quantidades[i], produto_precos[i]);
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

    printf("Novo Nome (atual: %s): ", produto_nomes[id - 1]);
    scanf(" %[^\n]s", produto_nomes[id - 1]);

    printf("Nova Categoria (atual: %s): ", produto_categorias[id - 1]);
    scanf(" %[^\n]s", produto_categorias[id - 1]);

    printf("Nova Quantidade (atual: %d): ", produto_quantidades[id - 1]);
    scanf("%d", &produto_quantidades[id - 1]);

    printf("Novo Preço (atual: %.2f): ", produto_precos[id - 1]);
    scanf("%f", &produto_precos[id - 1]);

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

    for (int i = id - 1; i < total_produtos_cadastrados - 1; i++) {
        produto_ids[i] = produto_ids[i + 1];

        for (int j = 0; j < TAM_NOME_PROD; j++) {
            produto_nomes[i][j] = produto_nomes[i + 1][j];
        }
        for (int j = 0; j < TAM_CATEGORIA; j++) {
            produto_categorias[i][j] = produto_categorias[i + 1][j];
        }
        produto_quantidades[i] = produto_quantidades[i + 1];
        produto_precos[i] = produto_precos[i + 1];
    }
total_produtos_cadastrados--;
    printf("Produto excluído com sucesso!\n");
}

void total_produtos() {
    printf("\nTotal de Produtos Cadastrados: %d\n", total_produtos_cadastrados);
}

void produtos_por_categoria() {
    printf("\n--- Produtos por Categoria ---\n");
    char categoria[TAM_CATEGORIA];
    int encontrados = 0;

    printf("Informe a categoria para listar os produtos: ");
    scanf(" %[^\n]s", categoria);

    for (int i = 0; i < total_produtos_cadastrados; i++) {
       
        int iguais = 1;
        for (int j = 0; j < TAM_CATEGORIA && categoria[j] != '\0'; j++) {
            if (categoria[j] != produto_categorias[i][j]) {
                iguais = 0;
                break;
            }
        }

        if (iguais) {
            printf("ID: %d | Nome: %s | Quantidade: %d | Preço: %.2f\n",
                   produto_ids[i], produto_nomes[i], produto_quantidades[i], produto_precos[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum produto encontrado na categoria '%s'.\n", categoria);
    }
}

void produtos_mais_menos_procurados() {
    printf("\n--- Produtos Mais/Menos Procurados ---\n");
    printf("Função em desenvolvimento.\n");
    
}
