
#ifndef TIPOS_H
#define TIPOS_H

typedef struct {
    int ano, mes, dia, hora, min;
} DataHora;

typedef enum {
    TIPO_FLORESTAL = 1,
    TIPO_URBANO,
    TIPO_INDUSTRIAL
} TipoOcorrencia;

typedef enum {
    PRIO_BAIXA = 1,
    PRIO_NORMAL,
    PRIO_ALTA
} Prioridade;

typedef enum {
    OCORR_REPORTADA = 1,
    OCORR_EM_INTERVENCAO,
    OCORR_CONCLUIDA
} EstadoOcorrencia;

typedef enum {
    INTERV_PLANEAMENTO = 1,
    INTERV_EXECUCAO,
    INTERV_CONCLUIDA
} EstadoIntervencao;

typedef enum {
    ESP_COMBATE = 1,
    ESP_RESGATE,
    ESP_SUPORTE
} Especialidade;

typedef enum {
    BOMBEIRO_DISPONIVEL = 1,
    BOMBEIRO_EM_INTERVENCAO,
    BOMBEIRO_EM_TREINO
} EstadoBombeiro;

typedef enum {
    EQUIP_DISPONIVEL = 1,
    EQUIP_EM_USO,
    EQUIP_MANUTENCAO
} EstadoEquip;

#endif /* TIPOS_H */
