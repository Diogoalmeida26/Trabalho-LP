#include "validacao.h"

int texto_valido(const char *s) {
    return s != NULL && s[0] != '\0';
}

int validar_datahora(DataHora d) {
    if (d.ano < 1900 || d.ano > 3000) return 0;
    if (d.mes < 1 || d.mes > 12) return 0;
    if (d.dia < 1 || d.dia > 31) return 0;
    if (d.hora < 0 || d.hora > 23) return 0;
    if (d.min < 0 || d.min > 59) return 0;
    return 1;
}

int validar_prioridade(Prioridade p) {
    return p >= PRIO_BAIXA && p <= PRIO_ALTA;
}

int validar_tipo_ocorrencia(TipoOcorrencia t) {
    return t >= TIPO_FLORESTAL && t <= TIPO_INDUSTRIAL;
}

int validar_estado_ocorrencia(EstadoOcorrencia e) {
    return e >= OCORR_REPORTADA && e <= OCORR_CONCLUIDA;
}

int validar_estado_intervencao(EstadoIntervencao e) {
    return e >= INTERV_PLANEAMENTO && e <= INTERV_CONCLUIDA;
}

int validar_especialidade(Especialidade e) {
    return e >= ESP_COMBATE && e <= ESP_SUPORTE;
}

int validar_estado_bombeiro(EstadoBombeiro e) {
    return e >= BOMBEIRO_DISPONIVEL && e <= BOMBEIRO_EM_TREINO;
}

int validar_estado_equipamento(EstadoEquip e) {
    return e >= EQUIP_DISPONIVEL && e <= EQUIP_MANUTENCAO;
}

