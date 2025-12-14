#ifndef INTERVENCAO_H
#define INTERVENCAO_H

#include <stddef.h>
#include "tipos.h"
#include "validacao.h"
#include "bombeiro.h"
#include "equipamento.h"
#include "ocorrencia.h"

typedef struct {
    int id;
    int ocorrenciaId;
    DataHora inicio;
    DataHora fim; /* se sem fim: zeros */
    EstadoIntervencao estado;
    int *bombeiros;
    size_t nb, capBombeiros;
    int *equipamentos;
    size_t ne, capEquipamentos;
} Intervencao;

typedef struct {
    Intervencao *itens;
    size_t size;
    size_t cap;
    int nextId;
} IntervencaoRepo;

void init_interv_repo(IntervencaoRepo *r);
void free_interv_repo(IntervencaoRepo *r);

int adicionar_intervencao(IntervencaoRepo *r, int ocorrenciaId, DataHora inicio, EstadoIntervencao estado);
Intervencao *buscar_intervencao(IntervencaoRepo *r, int id);

int atualizar_estado_intervencao(IntervencaoRepo *r, int id, EstadoIntervencao novo);
int fechar_intervencao(IntervencaoRepo *r, int id, DataHora fim);

int alocar_bombeiro_intervencao(Intervencao *i, BombeiroRepo *br, int bombeiroId);
int alocar_equipamento_intervencao(Intervencao *i, EquipamentoRepo *er, int equipamentoId);

int remover_intervencao(IntervencaoRepo *r, int id);

void listar_intervencoes(const IntervencaoRepo *r);

#endif /* INTERVENCAO_H */

