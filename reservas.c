#include <stdio.h>
#include "produto.h"

// Arrays para armazenar informações dos produtos
int ids[MAX_PRODUTOS];
char nomes[MAX_PRODUTOS][TAM_NOME_PROD];
char categorias[MAX_PRODUTOS][TAM_CATEGORIA];
int procuras[MAX_PRODUTOS];
int total_produtos = 0;

// Função para adicionar um produto ao array
void criar_produto(int id, const char nome[TAM_NOME_PROD], const char categoria[TAM_CATEGORIA]) {
    if (total_produtos < MAX_PRODUTOS) {
        ids[total_produtos] = id;
        for (int i = 0; i < TAM_NOME_PROD; i++) {
            nomes[total_produtos][i] = nome[i];
            if (nome[i] == '\0') break;
        }
        for (int i = 0; i < TAM_CATEGORIA; i++) {
            categorias[total_produtos][i] = categoria[i];
            if (categoria[i] == '\0') break;
        }
        procuras[total_produtos] = 0; // Inicializa a contagem de procura
        total_produtos++;
    }
}

// Função para listar todos os produtos
void listar_produtos(char lista[MAX_PRODUTOS][TAM_NOME_PROD]) {
    for (int i = 0; i < total_produtos; i++) {
        for (int j = 0; j < TAM_NOME_PROD; j++) {
            lista[i][j] = nomes[i][j];
        }
    }
}

// Função para listar produtos de uma categoria específica
void produtos_por_categoria(const char categoria[TAM_CATEGORIA], char lista[MAX_PRODUTOS][TAM_NOME_PROD], int *quantidade) {
    *quantidade = 0;
    for (int i = 0; i < total_produtos; i++) {
        int categoria_igual = 1;
        for (int j = 0; j < TAM_CATEGORIA; j++) {
            if (categorias[i][j] != categoria[j]) {
                categoria_igual = 0;
                break;
            }
            if (categoria[j] == '\0') break;
        }
        if (categoria_igual) {
            for (int j = 0; j < TAM_NOME_PROD; j++) {
                lista[*quantidade][j] = nomes[i][j];
            }
            (*quantidade)++;
        }
    }
}

// Função para excluir um produto pelo ID
void excluir_produto(int id) {
    for (int i = 0; i < total_produtos; i++) {
        if (ids[i] == id) {
            for (int j = i; j < total_produtos - 1; j++) {
                ids[j] = ids[j + 1];
                for (int k = 0; k < TAM_NOME_PROD; k++) {
                    nomes[j][k] = nomes[j + 1][k];
                }
                for (int k = 0; k < TAM_CATEGORIA; k++) {
                    categorias[j][k] = categorias[j + 1][k];
                }
                procuras[j] = procuras[j + 1];
            }
            total_produtos--;
            return;
        }
    }
}



void total_produtos() {
    return total_produtos;
}


// Função para obter os produtos menos procurados
void produtos_menos_procurados(char lista[MAX_PRODUTOS][TAM_NOME_PROD], int *quantidade) {
    if (total_produtos == 0) {
        *quantidade = 0;
        return;
    }

    int menor_procuras = procuras[0];
    for (int i = 1; i < total_produtos; i++) {
        if (procuras[i] < menor_procuras) {
            menor_procuras = procuras[i];
        }
    }

    *quantidade = 0;
    for (int i = 0; i < total_produtos; i++) {
        if (procuras[i] == menor_procuras) {
            for (int j = 0; j < TAM_NOME_PROD; j++) {
                lista[*quantidade][j] = nomes[i][j];
            }
            (*quantidade)++;
        }
    }
}
