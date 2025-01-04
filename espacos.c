#include "espacos.h"
#include "logs.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Espaco *head_espacos = NULL;

Espaco *criar_espaco(int id, const char *nome, int capacidade, const char *tipo) {
    Espaco *novo = (Espaco *)malloc(sizeof(Espaco));
    if (!novo) {
        perror("Erro ao alocar memória para espaço");
        exit(EXIT_FAILURE);
    }
    novo->id = id;
    strncpy(novo->nome, nome, TAMANHO_MAX_NOME);
    novo->capacidade = capacidade;
    strncpy(novo->tipo, tipo, TAMANHO_MAX_TIPO);
    novo->proximo = NULL;
    return novo;
}

void inserir_espaco(const char *nome, int capacidade, const char *tipo) {
    static int id = 0;
    id++;

    Espaco *novo = criar_espaco(id, nome, capacidade, tipo);
    if (!head_espacos) {
        head_espacos = novo;
    } else {
        Espaco *atual = head_espacos;
        while (atual->proximo) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    printf("Espaço criado com sucesso! ID: %d\n", id);

    char log_desc[200];
    sprintf(log_desc, "Espaço criado - ID: %d, Nome: %s", id, nome);
    registrar_log("CRIAR ESPAÇO", log_desc);
}

void listar_espacos() {
    if (!head_espacos) {
        printf("Nenhum espaço cadastrado.\n");
        return;
    }
    Espaco *atual = head_espacos;
    printf("ID\tNome\tCapacidade\tTipo\n");
    while (atual) {
        printf("%d\t%s\t%d\t%s\n", atual->id, atual->nome, atual->capacidade, atual->tipo);
        atual = atual->proximo;
    }
}

void atualizar_espaco(int id) {
    Espaco *atual = head_espacos;
    while (atual) {
        if (atual->id == id) {
            printf("Atualizando espaço ID %d:\n", id);
            ler_string("Novo nome: ", atual->nome, TAMANHO_MAX_NOME);
            atual->capacidade = ler_inteiro("Nova capacidade: ");
            ler_string("Novo tipo: ", atual->tipo, TAMANHO_MAX_TIPO);
            printf("Espaço atualizado com sucesso!\n");

            char log_desc[200];
            sprintf(log_desc, "Espaço atualizado - ID: %d, Nome: %s", id, atual->nome);
            registrar_log("ATUALIZAR ESPAÇO", log_desc);
            return;
        }
        atual = atual->proximo;
    }
    printf("Espaço com ID %d não encontrado.\n", id);
}

void remover_espaco(int id) {
    Espaco *atual = head_espacos;
    Espaco *anterior = NULL;

    while (atual) {
        if (atual->id == id) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                head_espacos = atual->proximo;
            }
            free(atual);
            printf("Espaço com ID %d removido.\n", id);

            char log_desc[200];
            sprintf(log_desc, "Espaço removido - ID: %d", id);
            registrar_log("REMOVER ESPAÇO", log_desc);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Espaço com ID %d não encontrado.\n", id);
}

void liberar_espacos() {
    Espaco *atual = head_espacos;
    while (atual) {
        Espaco *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    head_espacos = NULL;
    
}

int espaco_existe(int espaco_id) {
    Espaco *atual = head_espacos;
    while(atual) {
        if(atual->id == espaco_id) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

