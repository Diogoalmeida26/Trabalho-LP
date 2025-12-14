#ifndef OCORRENCIA_H
#define OCORRENCIA_H

#include <stddef.h>
#include "tipos.h"
#include "validacao.h"

#ifndef MAX_LOCAL
#define MAX_LOCAL 64
#endif

typedef struct {
    int id;
    char local[MAX_LOCAL];
    TipoOcorrencia tipo;
    DataHora dataHora;
    Prioridade prioridade;
    EstadoOcorrencia estado;
} Ocorrencia;

typedef struct {
    Ocorrencia *itens;
    size_t size;
    size_t cap;
    int nextId;
} OcorrenciaRepo;

void init_ocorr_repo(OcorrenciaRepo *r);
void free_ocorr_repo(OcorrenciaRepo *r);

int adicionar_ocorrencia(OcorrenciaRepo *r, const char *local, TipoOcorrencia tipo, DataHora dh, Prioridade prio);
Ocorrencia *buscar_ocorrencia(OcorrenciaRepo *r, int id);

int atualizar_ocorrencia(OcorrenciaRepo *r, int id, const char *local, TipoOcorrencia tipo, DataHora dh, Prioridade prio);
int atualizar_estado_ocorrencia(OcorrenciaRepo *r, int id, EstadoOcorrencia novoEstado);
int remover_ocorrencia(OcorrenciaRepo *r, int id);

void listar_ocorrencias(const OcorrenciaRepo *r);

#endif /* OCORRENCIA_H */

