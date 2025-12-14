#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include <stddef.h>
#include "tipos.h"
#include "validacao.h"

#define MAX_NOME 64
#define MAX_LOCAL 64

typedef struct {
    int id;
    char nome[MAX_NOME];
    EstadoEquip estado;
    char local[MAX_LOCAL];
} Equipamento;

typedef struct {
    Equipamento *itens;
    size_t size;
    size_t cap;
    int nextId;
} EquipamentoRepo;

void init_equip_repo(EquipamentoRepo *r);
void free_equip_repo(EquipamentoRepo *r);

int adicionar_equipamento(EquipamentoRepo *r, const char *nome, EstadoEquip estado, const char *local);
Equipamento *buscar_equipamento(EquipamentoRepo *r, int id);

int atualizar_equipamento(EquipamentoRepo *r, int id, const char *nome, EstadoEquip estado, const char *local);
int remover_equipamento(EquipamentoRepo *r, int id);

void listar_equipamentos(const EquipamentoRepo *r);

#endif /* EQUIPAMENTO_H */

