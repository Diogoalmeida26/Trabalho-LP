#ifndef CLIENTES_H
#define CLIENTES_H

#include <time.h>
#define TAMANHO_MAX_NOME 100
#define TAMANHO_MAX_CONTATO 150
#define TAMANHO_MAX_NIF 11

typedef struct Cliente {
    int id;
    char nome[TAMANHO_MAX_NOME];
    char contato[TAMANHO_MAX_CONTATO];
    char nif[TAMANHO_MAX_NIF];
    time_t data_registro;
    struct Cliente *proximo;
} Cliente;

void inserir_cliente(const char *nome, const char *contato, const char *nif);
void listar_clientes();
void atualizar_cliente(int id);
void remover_cliente(int id);
void liberar_clientes();

int cliente_existe(int cliente_id);

#endif
