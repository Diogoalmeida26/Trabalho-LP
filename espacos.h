#ifndef ESPACOS_H
#define ESPACOS_H

#define TAMANHO_MAX_NOME 100
#define TAMANHO_MAX_TIPO 50

typedef struct Espaco {
    int id;
    char nome[TAMANHO_MAX_NOME];
    int capacidade;
    char tipo[TAMANHO_MAX_TIPO];
    struct Espaco *proximo;
} Espaco;

void inserir_espaco(const char *nome, int capacidade, const char *tipo);
void listar_espacos();
void atualizar_espaco(int id);
void remover_espaco(int id);
void liberar_espacos();

int espaco_existe(int espaco_id);

#endif
