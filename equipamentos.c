#include "equipamentos.h"
#include "logs.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Equipamento *head_equipamentos = NULL;

Equipamento *criar_equipamento(int id, const char *nome, const char *tipo, const char *estado) {
    Equipamento *novo = (Equipamento *)malloc(sizeof(Equipamento));
    if (!novo) {
        perror("Erro ao alocar memória para equipamento");
        exit(EXIT_FAILURE);
    }
    novo->id = id;
    strncpy(novo->nome, nome, TAMANHO_MAX_NOME);
    strncpy(novo->tipo, tipo, TAMANHO_MAX_TIPO);
    strncpy(novo->estado, estado, TAMANHO_MAX_ESTADO);
    novo->proximo = NULL;
    return novo;
}

void inserir_equipamento(const char *nome, const char *tipo, const char *estado) {
    static int id = 0;
    id++;

    Equipamento *novo = criar_equipamento(id, nome, tipo, estado);
    if (!head_equipamentos) {
        head_equipamentos = novo;
    } else {
        Equipamento *atual = head_equipamentos;
        while (atual->proximo) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    printf("Equipamento criado com sucesso! ID: %d\n", id);

    char log_desc[200];
    sprintf(log_desc, "Equipamento criado - ID: %d, Nome: %s", id, nome);
    registrar_log("CRIAR EQUIPAMENTO", log_desc);
}

void listar_equipamentos() {
    if (!head_equipamentos) {
        printf("Nenhum equipamento cadastrado.\n");
        return;
    }
    Equipamento *atual = head_equipamentos;
    printf("ID\tNome\t\tTipo\t\tEstado\n");
    while (atual) {
        printf("%d\t%s\t\t%s\t\t%s\n", atual->id, atual->nome, atual->tipo, atual->estado);
        atual = atual->proximo;
    }
}

void atualizar_equipamento(int id) {
    Equipamento *atual = head_equipamentos;
    while (atual) {
        if (atual->id == id) {
            printf("Atualizando equipamento ID %d:\n", id);
            ler_string("Novo nome: ", atual->nome, TAMANHO_MAX_NOME);
            ler_string("Novo tipo: ", atual->tipo, TAMANHO_MAX_TIPO);
            ler_string("Novo estado (Disponível, Reservado, etc.): ", atual->estado, TAMANHO_MAX_ESTADO);
            printf("Equipamento atualizado com sucesso!\n");

            char log_desc[200];
            sprintf(log_desc, "Equipamento atualizado - ID: %d, Nome: %s", id, atual->nome);
            registrar_log("ATUALIZAR EQUIPAMENTO", log_desc);
            return;
        }
        atual = atual->proximo;
    }
    printf("Equipamento com ID %d não encontrado.\n", id);
}

void remover_equipamento(int id) {
    Equipamento *atual = head_equipamentos;
    Equipamento *anterior = NULL;

    while (atual) {
        if (atual->id == id) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                head_equipamentos = atual->proximo;
            }
            free(atual);
            printf("Equipamento com ID %d removido.\n", id);

            char log_desc[200];
            sprintf(log_desc, "Equipamento removido - ID: %d", id);
            registrar_log("REMOVER EQUIPAMENTO", log_desc);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Equipamento com ID %d não encontrado.\n", id);
}

void liberar_equipamentos() {
    Equipamento *atual = head_equipamentos;
    while (atual) {
        Equipamento *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    head_equipamentos = NULL;
    
}

