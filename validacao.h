#ifndef VALIDACAO_H
#define VALIDACAO_H

#include "tipos.h"  /* Deve declarar DataHora e os enums usados */

int texto_valido(const char *s);

int validar_datahora(DataHora d);

int validar_prioridade(Prioridade p);
int validar_tipo_ocorrencia(TipoOcorrencia t);
int validar_estado_ocorrencia(EstadoOcorrencia e);

int validar_estado_intervencao(EstadoIntervencao e);

int validar_especialidade(Especialidade e);
int validar_estado_bombeiro(EstadoBombeiro e);

int validar_estado_equipamento(EstadoEquip e);

#endif /* VALIDACAO_H */
