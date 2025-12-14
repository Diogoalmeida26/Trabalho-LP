#include "relatorios.h"
#include <stdio.h>

void listar_ocorrencias_por_estado(const OcorrenciaRepo *r, EstadoOcorrencia estado) {
    if (!r) return;
    printf("Ocorrencias com estado %d:\n", estado);
    for (size_t k = 0; k < r->size; ++k) {
        const Ocorrencia *o = &r->itens[k];
        if (o->estado == estado) {
            printf("  #%d | %s | tipo %d | prio %d\n", o->id, o->local, o->tipo, o->prioridade);
        }
    }
}

void listar_ocorrencias_por_prioridade(const OcorrenciaRepo *r, Prioridade prio) {
    if (!r) return;
    printf("Ocorrencias com prioridade %d:\n", prio);
    for (size_t k = 0; k < r->size; ++k) {
        const Ocorrencia *o = &r->itens[k];
        if (o->prioridade == prio) {
            printf("  #%d | %s | estado %d\n", o->id, o->local, o->estado);
        }
    }
}

void listar_intervencoes_por_ocorrencia(const IntervencaoRepo *ir, int ocorrenciaId) {
    if (!ir || ocorrenciaId <= 0) return;
    printf("Intervencoes da ocorrencia %d:\n", ocorrenciaId);
    for (size_t k = 0; k < ir->size; ++k) {
        const Intervencao *i = &ir->itens[k];
        if (i->ocorrenciaId == ocorrenciaId) {
            printf("  #%d | estado %d | bombeiros %zu | equipamentos %zu\n",
                   i->id, i->estado, i->nb, i->ne);
        }
    }
}

void listar_bombeiros_disponiveis(const BombeiroRepo *br) {
    if (!br) return;
    printf("Bombeiros disponiveis:\n");
    for (size_t k = 0; k < br->size; ++k) {
        const Bombeiro *b = &br->itens[k];
        if (b->estado == BOMBEIRO_DISPONIVEL) {
            printf("  #%d | %s | esp %d\n", b->id, b->nome, b->esp);
        }
    }
}

void listar_equipamentos_disponiveis(const EquipamentoRepo *er) {
    if (!er) return;
    printf("Equipamentos disponiveis:\n");
    for (size_t k = 0; k < er->size; ++k) {
        const Equipamento *e = &er->itens[k];
        if (e->estado == EQUIP_DISPONIVEL) {
            printf("  #%d | %s | local %s\n", e->id, e->nome, e->local);
        }
    }
}

