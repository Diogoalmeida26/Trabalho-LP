#include "reservas.h"
#include "clientes.h"
#include "espacos.h"
#include "logs.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Reserva *head_reservas = NULL;

Reserva *criar_reserva(int id, int cliente_id, int espaco_id, int duracao, int participantes, const char *estado) {
    Reserva *nova = (Reserva *)malloc(sizeof(Reserva));
    if (!nova) {
        perror("Erro ao alocar memória para reserva");
        exit(EXIT_FAILURE);
    }
    nova->id = id;
    nova->cliente_id = cliente_id;
    nova->espaco_id = espaco_id;
    nova->duracao = duracao;
    nova->participantes = participantes;
    strncpy(nova->estado, estado, TAMANHO_MAX_ESTADO);
    nova->proximo = NULL;
    return nova;
}

void inserir_reserva(int cliente_id, int espaco_id, int duracao, int participantes, const char *estado) {
    static int id = 0;
    id++;

    // Verificar se o cliente e o espaço existem
    if (!cliente_existe(cliente_id)) {
        printf("Cliente com ID %d não encontrado.\n", cliente_id);
        registrar_log("ERRO", "Tentativa de criar reserva com cliente inexistente.");
        return;
    }
    if (!espaco_existe(espaco_id)) {
        printf("Espaço com ID %d não encontrado.\n", espaco_id);
        registrar_log("ERRO", "Tentativa de criar reserva com espaço inexistente.");
        return;
    }

    Reserva *nova = criar_reserva(id, cliente_id, espaco_id, duracao, participantes, estado);
    if (!head_reservas) {
        head_reservas = nova;
    } else {
        Reserva *atual = head_reservas;
        while (atual->proximo) {
            atual = atual->proximo;
        }
        atual->proximo = nova;
    }
    printf("Reserva criada com sucesso! ID: %d\n", id);

    char log_desc[200];
    sprintf(log_desc, "Reserva criada - ID: %d, Cliente ID: %d, Espaço ID: %d", id, cliente_id, espaco_id);
    registrar_log("CRIAR RESERVA", log_desc);
}

void listar_reservas() {
    if (!head_reservas) {
        printf("Nenhuma reserva cadastrada.\n");
        return;
    }
    Reserva *atual = head_reservas;
    printf("ID\tCliente\tEspaço\tDuração\tParticipantes\tEstado\n");
    while (atual) {
        printf("%d\t%d\t%d\t%d\t%d\t%s\n", 
               atual->id, 
               atual->cliente_id, 
               atual->espaco_id, 
               atual->duracao, 
               atual->participantes, 
               atual->estado);
        atual = atual->proximo;
    }
}

void atualizar_reserva(int id) {
    Reserva *atual = head_reservas;
    while (atual) {
        if (atual->id == id) {
            printf("Atualizando reserva ID %d:\n", id);
            atual->cliente_id = ler_inteiro("Novo ID do cliente: ");
            if (!cliente_existe(atual->cliente_id)) {
                printf("Cliente com ID %d não encontrado.\n", atual->cliente_id);
                return;
            }
            atual->espaco_id = ler_inteiro("Novo ID do espaço: ");
            if (!espaco_existe(atual->espaco_id)) {
                printf("Espaço com ID %d não encontrado.\n", atual->espaco_id);
                return;
            }
            atual->duracao = ler_inteiro("Nova duração (em horas): ");
            atual->participantes = ler_inteiro("Novo número de participantes: ");
            ler_string("Novo estado (Pendente, Confirmada, etc.): ", atual->estado, TAMANHO_MAX_ESTADO);
            printf("Reserva atualizada com sucesso!\n");

            char log_desc[200];
            sprintf(log_desc, "Reserva atualizada - ID: %d, Cliente ID: %d, Espaço ID: %d", id, atual->cliente_id, atual->espaco_id);
            registrar_log("ATUALIZAR RESERVA", log_desc);
            return;
        }
        atual = atual->proximo;
    }
    printf("Reserva com ID %d não encontrada.\n", id);
}

void remover_reserva(int id) {
    Reserva *atual = head_reservas;
    Reserva *anterior = NULL;

    while (atual) {
        if (atual->id == id) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                head_reservas = atual->proximo;
            }
            free(atual);
            printf("Reserva com ID %d removida.\n", id);

            char log_desc[200];
            sprintf(log_desc, "Reserva removida - ID: %d", id);
            registrar_log("REMOVER RESERVA", log_desc);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Reserva com ID %d não encontrada.\n", id);
}

void liberar_reservas() {
    Reserva *atual = head_reservas;
    while (atual) {
        Reserva *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    head_reservas = NULL;
    
}
