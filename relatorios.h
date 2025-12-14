#ifndef RELATORIOS_H
#define RELATORIOS_H

#include "ocorrencia.h"
#include "intervencao.h"
#include "bombeiro.h"
#include "equipamento.h"

void listar_ocorrencias_por_estado(const OcorrenciaRepo *r, EstadoOcorrencia estado);
void listar_ocorrencias_por_prioridade(const OcorrenciaRepo *r, Prioridade prio);

void listar_intervencoes_por_ocorrencia(const IntervencaoRepo *ir, int ocorrenciaId);

void listar_bombeiros_disponiveis(const BombeiroRepo *br);
void listar_equipamentos_disponiveis(const EquipamentoRepo *er);

#endif /* RELATORIOS_H */

