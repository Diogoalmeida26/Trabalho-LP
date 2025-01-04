#ifndef EQUIPAMENTOS_H
#define EQUIPAMENTOS_H

#define TAMANHO_MAX_NOME 100
#define TAMANHO_MAX_TIPO 50
#define TAMANHO_MAX_ESTADO 20

typedef struct Equipamento {
    int id;
    char nome[TAMANHO_MAX_NOME];
    char tipo[TAMANHO_MAX_TIPO];
    char estado[TAMANHO_MAX_ESTADO]; // Ex: Disponível, Reservado, Em manutenção
    struct Equipamento *proximo;
} Equipamento;

void inserir_equipamento(const char *nome, const char *tipo, const char *estado);
void listar_equipamentos();
void atualizar_equipamento(int id);
void remover_equipamento(int id);
void liberar_equipamentos();

#endif
