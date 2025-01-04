#ifndef RESERVAS_H
#define RESERVAS_H

#define TAMANHO_MAX_ESTADO 20

typedef struct Reserva {
    int id;
    int cliente_id;
    int espaco_id;
    int duracao;  // Em horas
    int participantes;
    char estado[TAMANHO_MAX_ESTADO]; // Ex: Pendente, Confirmada
    struct Reserva *proximo;
} Reserva;

void inserir_reserva(int cliente_id, int espaco_id, int duracao, int participantes, const char *estado);
void listar_reservas();
void atualizar_reserva(int id);
void remover_reserva(int id);
void liberar_reservas();

#endif
