#include "clientes.h"
#include "logs.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Cliente *head_clientes = NULL;

Cliente *criar_cliente(int id, const char *nome, const char *contato, const char *nif) {
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo) {
        perror("Erro ao alocar memória para cliente");
        exit(EXIT_FAILURE);
    }
    novo->id = id;
    strncpy(novo->nome, nome, TAMANHO_MAX_NOME);
    strncpy(novo->contato, contato, TAMANHO_MAX_CONTATO);
    strncpy(novo->nif, nif, TAMANHO_MAX_NIF);
    novo->data_registro = time(NULL);
    novo->proximo = NULL;
    return novo;
}

void inserir_cliente(const char *nome, const char *contato, const char *nif) {
    int id = 0;
    id++;

    Cliente *novo = criar_cliente(id, nome, contato, nif);
    if (!head_clientes) {
        head_clientes = novo;
    } else {
        Cliente *atual = head_clientes;
        while (atual->proximo) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    printf("Cliente criado com sucesso! ID: %d\n", id);

    char log_desc[200];
    printf(log_desc, "Cliente criado - ID: %d, Nome: %s", id, nome);
    registrar_log("CRIAR CLIENTE", log_desc);
    
}

void listar_clientes() {
    if (!head_clientes) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    Cliente *atual = head_clientes;
    printf("ID\tNome\tContato\tNIF\tData Registro\n");
    while (atual) {
        char data_formatada[20];
        strftime(data_formatada, sizeof(data_formatada), "%d/%m/%Y", localtime(&atual->data_registro));
        printf("%d\t%s\t%s\t%s\t%s\n", atual->id, atual->nome, atual->contato, atual->nif, data_formatada);
        atual = atual->proximo;
    }
}

void atualizar_cliente(int id) {
    Cliente *atual = head_clientes;
    while (atual) {
        if (atual->id == id) {
            printf("Atualizando cliente ID %d:\n", id);
            ler_string("Novo nome: ", atual->nome, TAMANHO_MAX_NOME);
            ler_string("Novo contato: ", atual->contato, TAMANHO_MAX_CONTATO);
            ler_string("Novo NIF: ", atual->nif, TAMANHO_MAX_NIF);
            printf("Cliente atualizado com sucesso!\n");

            char log_desc[200];
            printf(log_desc, "Cliente atualizado - ID: %d, Nome: %s", id, atual->nome);
            registrar_log("ATUALIZAR CLIENTE", log_desc);
            return;
        }
        atual = atual->proximo;
    }
    printf("Cliente com ID %d não encontrado.\n", id);
}

void remover_cliente(int id) {
    Cliente *atual = head_clientes;
    Cliente *anterior = NULL;

    while (atual) {
        if (atual->id == id) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                head_clientes = atual->proximo;
            }
            free(atual);
            printf("Cliente com ID %d removido.\n", id);

            char log_desc[200];
            printf(log_desc, "Cliente removido - ID: %d", id);
            registrar_log("REMOVER CLIENTE", log_desc);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Cliente com ID %d não encontrado.\n", id);
}

void liberar_clientes() {
    Cliente *atual = head_clientes;
    while (atual) {
        Cliente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    head_clientes = NULL;
    
}

int cliente_existe(int cliente_id) {
    Cliente *atual = head_clientes;
    while(atual) {
        if(atual->id == cliente_id) {
            return 1;
        }
        atual = atual->proximo;
        }
    return 0;
    }
