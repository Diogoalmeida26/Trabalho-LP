#include "bombeiro.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

static void ensure_capacity_b(BombeiroRepo *r) {
    if (r->cap == 0) {
        r->cap = 8;
        r->itens = malloc(r->cap * sizeof(Bombeiro));
    } else if (r->size >= r->cap) {
        r->cap *= 2;
        r->itens = xrealloc(r->itens, r->cap * sizeof(Bombeiro));
    }
}

void init_bombeiro_repo(BombeiroRepo *r) {
    if (!r) return;
    r->itens = NULL;
    r->size = 0;
    r->cap = 0;
    r->nextId = 0;
}

void free_bombeiro_repo(BombeiroRepo *r) {
    if (!r) return;
    free(r->itens);
    r->itens = NULL;
    r->size = r->cap = 0;
    r->nextId = 0;
}

int adicionar_bombeiro(BombeiroRepo *r, const char *nome, Especialidade esp, EstadoBombeiro estado) {
    if (!r || !texto_valido(nome)) return 0;
    if (!validar_especialidade(esp) || !validar_estado_bombeiro(estado)) return 0;
    ensure_capacity_b(r);
    Bombeiro *b = &r->itens[r->size++];
    b->id = ++r->nextId;
    strncpy(b->nome, nome, MAX_NOME - 1);
    b->nome[MAX_NOME - 1] = '\0';
    b->esp = esp;
    b->estado = estado;
    b->intervCount = 0;
    return b->id;
}

Bombeiro *buscar_bombeiro(BombeiroRepo *r, int id) {
    if (!r || id <= 0) return NULL;
    for (size_t k = 0; k < r->size; ++k) {
        if (r->itens[k].id == id) return &r->itens[k];
    }
    return NULL;
}

int atualizar_bombeiro(BombeiroRepo *r, int id, const char *nome, Especialidade esp, EstadoBombeiro estado) {
    Bombeiro *b = buscar_bombeiro(r, id);
    if (!b) return 0;
    if (nome) {
        if (!texto_valido(nome)) return 0;
        strncpy(b->nome, nome, MAX_NOME - 1);
        b->nome[MAX_NOME - 1] = '\0';
    }
    if (!validar_especialidade(esp) || !validar_estado_bombeiro(estado)) return 0;
    b->esp = esp;
    b->estado = estado;
    return 1;
}

int remover_bombeiro(BombeiroRepo *r, int id) {
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

void listar_bombeiros(const BombeiroRepo *r) {
    if (!r) return;
    printf("Bombeiros (%zu):\n", r->size);
    for (size_t k = 0; k < r->size; ++k) {
        const Bombeiro *b = &r->itens[k];
        printf("  #%d | %s | esp %d | estado %d | interv %d\n",
               b->id, b->nome, b->esp, b->estado, b->intervCount);
    }
}

