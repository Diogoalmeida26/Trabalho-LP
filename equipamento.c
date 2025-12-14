#include "equipamento.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void ensure_capacity_e(EquipamentoRepo *r) {
    if (r->cap == 0) {
        r->cap = 8;
        r->itens = malloc(r->cap * sizeof(Equipamento));
    } else if (r->size >= r->cap) {
        r->cap *= 2;
        r->itens = xrealloc(r->itens, r->cap * sizeof(Equipamento));
    }
}

void init_equip_repo(EquipamentoRepo *r) {
    if (!r) return;
    r->itens = NULL;
    r->size = 0;
    r->cap = 0;
    r->nextId = 0;
}

void free_equip_repo(EquipamentoRepo *r) {
    if (!r) return;
    free(r->itens);
    r->itens = NULL;
    r->size = r->cap = 0;
    r->nextId = 0;
}

int adicionar_equipamento(EquipamentoRepo *r, const char *nome, EstadoEquip estado, const char *local) {
    if (!r || !texto_valido(nome) || !texto_valido(local)) return 0;
    if (!validar_estado_equipamento(estado)) return 0;
    ensure_capacity_e(r);
    Equipamento *e = &r->itens[r->size++];
    e->id = ++r->nextId;
    strncpy(e->nome, nome, MAX_NOME - 1);
    e->nome[MAX_NOME - 1] = '\0';
    strncpy(e->local, local, MAX_LOCAL - 1);
    e->local[MAX_LOCAL - 1] = '\0';
    e->estado = estado;
    return e->id;
}

Equipamento *buscar_equipamento(EquipamentoRepo *r, int id) {
    if (!r || id <= 0) return NULL;
    for (size_t k = 0; k < r->size; ++k) {
        if (r->itens[k].id == id) return &r->itens[k];
    }
    return NULL;
}

int atualizar_equipamento(EquipamentoRepo *r, int id, const char *nome, EstadoEquip estado, const char *local) {
    Equipamento *e = buscar_equipamento(r, id);
    if (!e) return 0;
    if (nome) {
        if (!texto_valido(nome)) return 0;
        strncpy(e->nome, nome, MAX_NOME - 1);
        e->nome[MAX_NOME - 1] = '\0';
    }
    if (local) {
        if (!texto_valido(local)) return 0;
        strncpy(e->local, local, MAX_LOCAL - 1);
        e->local[MAX_LOCAL - 1] = '\0';
    }
    if (!validar_estado_equipamento(estado)) return 0;
    e->estado = estado;
    return 1;
}

int remover_equipamento(EquipamentoRepo *r, int id) {
    if (!r || id <= 0) return 0;
    for (size_t k = 0; k < r->size; ++k) {
        if (r->itens[k].id == id) {
            r->itens[k] = r->itens[r->size - 1];
            r->size--;
            return 1;
        }
    }
    return 0;
}

void listar_equipamentos(const EquipamentoRepo *r) {
    if (!r) return;
    printf("Equipamentos (%zu):\n", r->size);
    for (size_t k = 0; k < r->size; ++k) {
        const Equipamento *e = &r->itens[k];
        printf("  #%d | %s | estado %d | local %s\n",
               e->id, e->nome, e->estado, e->local);
    }
}

