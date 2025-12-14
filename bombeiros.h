#ifndef BOMBEIRO_H
#define BOMBEIRO_H

#include <stddef.h>
#include "tipos.h"
#include "validacao.h"

#define MAX_NOME 64

typedef struct {
    int id;
    char nome[MAX_NOME];
    Especialidade esp;
    EstadoBombeiro estado;
    int intervCount;
} Bombeiro;

typedef struct {
    Bombeiro *itens;
    size_t size;
    size_t cap;
    int nextId;
} BombeiroRepo;

void init_bombeiro_repo(BombeiroRepo *r);
void free_bombeiro_repo(BombeiroRepo *r);

int adicionar_bombeiro(BombeiroRepo *r, const char *nome, Especialidade esp, EstadoBombeiro estado);
Bombeiro *buscar_bombeiro(BombeiroRepo *r, int id);

int atualizar_bombeiro(BombeiroRepo *r, int id, const char *nome, Especialidade esp, EstadoBombeiro estado);
int remover_bombeiro(BombeiroRepo *r, int id);

void listar_bombeiros(const BombeiroRepo *r);

#endif /* BOMBEIRO_H */

