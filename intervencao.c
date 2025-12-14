#include "intervencao.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void ensure_capacity_in(IntervencaoRepo *r) {
    if (r->cap == 0) {
        r->cap = 8;
        r->itens = malloc(r->cap * sizeof(Intervencao));
    } else if (r->size >= r->cap) {
        r->cap *= 2;
        r->itens = xrealloc(r->itens, r->cap * sizeof(Intervencao));
    }
}

static int append_int(int **arr, size_t *n, size_t *cap, int value) {
    if (*cap == 0) {
        *cap = 8;
        *arr = malloc(*cap * sizeof(int));
    } else if (*n >= *cap) {
        *cap *= 2;
        *arr = xrealloc(*arr, *cap * sizeof(int));
    }
    (*arr)[(*n)++] = value;
    return 1;
}

void init_interv_repo(IntervencaoRepo *r) {
    if (!r) return;
    r->itens = NULL;
    r->size = 0;
    r->cap = 0;
    r->nextId = 0;
}

void free_interv_repo(IntervencaoRepo *r) {
    if (!r) return;
    for (size_t k = 0; k < r->size; ++k) {
        free(r->itens[k].bombeiros);
        free(r->itens[k].equipamentos);
    }
    free(r->itens);
    r->itens = NULL;
    r->size = r->cap = 0;
    r->nextId = 0;
}

int adicionar_intervencao(IntervencaoRepo *r, int ocorrenciaId, DataHora inicio, EstadoIntervencao estado) {
    if (!r || ocorrenciaId <= 0) return 0;
    if (!validar_datahora(inicio)) return 0;
    if (!validar_estado_intervencao(estado)) return 0;
    ensure_capacity_in(r);
    Intervencao *i = &r->itens[r->size++];
    i->id = ++r->nextId;
    i->ocorrenciaId = ocorrenciaId;
    i->inicio = inicio;
    i->fim.ano = i->fim.mes = i->fim.dia = 0;
    i->fim.hora = i->fim.min = 0;
    i->estado = estado;
    i->bombeiros = NULL;
    i->equipamentos = NULL;
    i->nb = i->ne = 0;
    i->capBombeiros = i->capEquipamentos = 0;
    return i->id;
}

Intervencao *buscar_intervencao(IntervencaoRepo *r, int id) {
    if (!r || id <= 0) return NULL;
    for (size_t k = 0; k < r->size; ++k) {
        if (r->itens[k].id == id) return &r->itens[k];
    }
    return NULL;
}

int atualizar_estado_intervencao(IntervencaoRepo *r, int id, EstadoIntervencao novo) {
    Intervencao *i = buscar_intervencao(r, id);
    if (!i) return 0;
    if (!validar_estado_intervencao(novo)) return 0;
    i->estado = novo;
    return 1;
}

int fechar_intervencao(IntervencaoRepo *r, int id, DataHora fim) {
    Intervencao *i = buscar_intervencao(r, id);
    if (!i) return 0;
    if (!validar_datahora(fim)) return 0;
    i->fim = fim;
    i->estado = INTERV_CONCLUIDA;
    return 1;
}

int alocar_bombeiro_intervencao(Intervencao *i, BombeiroRepo *br, int bombeiroId) {
    if (!i || !br || bombeiroId <= 0) return 0;
    if (!buscar_bombeiro(br, bombeiroId)) return 0;
    return append_int(&i->bombeiros, &i->nb, &i->capBombeiros, bombeiroId);
}

int alocar_equipamento_intervencao(Intervencao *i, EquipamentoRepo *er, int equipamentoId) {
    if (!i || !er || equipamentoId <= 0) return 0;
    if (!buscar_equipamento(er, equipamentoId)) return 0;
    return append_int(&i->equipamentos, &i->ne, &i->capEquipamentos, equipamentoId);
}

int remover_intervencao(IntervencaoRepo *r, int id) {
    if (!r || id <= 0) return 0;
    for (size_t k = 0; k < r->size; ++k) {
        if (r->itens[k].id == id) {
            free(r->itens[k].bombeiros);
            free(r->itens[k].equipamentos);
            r->itens[k] = r->itens[r->size - 1];
            r->size--;
            return 1;
        }
    }
    return 0;
}

void listar_intervencoes(const IntervencaoRepo *r) {
    if (!r) return;
    printf("Intervencoes (%zu):\n", r->size);
    for (size_t k = 0; k < r->size; ++k) {
        const Intervencao *i = &r->itens[k];
        printf("  #%d | ocorr %d | estado %d | bombeiros %zu | equipamentos %zu\n",
               i->id, i->ocorrenciaId, i->estado, i->nb, i->ne);
    }
}

