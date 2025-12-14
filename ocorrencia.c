#include "ocorrencia.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void ensure_capacity_oc(OcorrenciaRepo *r) {
    if (r->cap == 0) {
        r->cap = 8;
        r->itens = malloc(r->cap * sizeof(Ocorrencia));
    } else if (r->size >= r->cap) {
        r->cap *= 2;
        r->itens = xrealloc(r->itens, r->cap * sizeof(Ocorrencia));
    }
}

void init_ocorr_repo(OcorrenciaRepo *r) {
    if (!r) return;
    r->itens = NULL;
    r->size = 0;
    r->cap = 0;
    r->nextId = 0;
}

void free_ocorr_repo(OcorrenciaRepo *r) {
    if (!r) return;
    free(r->itens);
    r->itens = NULL;
    r->size = r->cap = 0;
    r->nextId = 0;
}

int adicionar_ocorrencia(OcorrenciaRepo *r, const char *local, TipoOcorrencia tipo, DataHora dh, Prioridade prio) {
    if (!r || !texto_valido(local)) return 0;
    if (!validar_tipo_ocorrencia(tipo) || !validar_prioridade(prio)) return 0;
    if (!validar_datahora(dh)) return 0;
    ensure_capacity_oc(r);
    Ocorrencia *o = &r->itens[r->size++];
    o->id = ++r->nextId;
    strncpy(o->local, local, MAX_LOCAL - 1);
    o->local[MAX_LOCAL - 1] = '\0';
    o->tipo = tipo;
    o->dataHora = dh;
    o->prioridade = prio;
    o->estado = OCORR_REPORTADA;
    return o->id;
}

Ocorrencia *buscar_ocorrencia(OcorrenciaRepo *r, int id) {
    if (!r || id <= 0) return NULL;
    for (size_t k = 0; k < r->size; ++k) {
        if (r->itens[k].id == id) return &r->itens[k];
    }
    return NULL;
}

int atualizar_ocorrencia(OcorrenciaRepo *r, int id, const char *local, TipoOcorrencia tipo, DataHora dh, Prioridade prio) {
    Ocorrencia *o = buscar_ocorrencia(r, id);
    if (!o) return 0;
    if (local) {
        if (!texto_valido(local)) return 0;
        strncpy(o->local, local, MAX_LOCAL - 1);
        o->local[MAX_LOCAL - 1] = '\0';
    }
    if (!validar_tipo_ocorrencia(tipo) || !validar_prioridade(prio)) return 0;
    if (!validar_datahora(dh)) return 0;
    o->tipo = tipo;
    o->dataHora = dh;
    o->prioridade = prio;
    return 1;
}

int atualizar_estado_ocorrencia(OcorrenciaRepo *r, int id, EstadoOcorrencia novoEstado) {
    Ocorrencia *o = buscar_ocorrencia(r, id);
    if (!o) return 0;
    if (!validar_estado_ocorrencia(novoEstado)) return 0;
    o->estado = novoEstado;
    return 1;
}

int remover_ocorrencia(OcorrenciaRepo *r, int id) {
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

void listar_ocorrencias(const OcorrenciaRepo *r) {
    if (!r) return;
    printf("Ocorrencias (%zu):\n", r->size);
    for (size_t k = 0; k < r->size; ++k) {
        const Ocorrencia *o = &r->itens[k];
        printf("  #%d | %s | tipo %d | prio %d | estado %d\n",
               o->id, o->local, o->tipo, o->prioridade, o->estado);
    }
}

