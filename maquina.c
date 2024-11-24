#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maquina.h"

// Lista dinâmica de máquinas
Maquina *maquinas = NULL;
int total_maquinas = 0;

void criar_maquina() {
    printf("\n--- Criar Máquina ---\n");

    // Realocação dinâmica para uma nova máquina
    maquinas = realloc(maquinas, (total_maquinas + 1) * sizeof(Maquina));
    Maquina *nova_maquina = &maquinas[total_maquinas];
    nova_maquina->id = total_maquinas + 1;

    printf("Nome da Máquina: ");
    scanf(" %[^\n]s", nova_maquina->nome);

    printf("Tipo da Máquina (Corte, Fresagem, CNC, etc.): ");
    scanf(" %[^\n]s", nova_maquina->tipo);

    total_maquinas++;
    printf("Máquina cadastrada com sucesso!\n");
}

void listar_maquinas() {
    printf("\n--- Lista de Máquinas ---\n");

    if (total_maquinas == 0) {
        printf("Nenhuma máquina cadastrada.\n");
        return;
    }

    for (int i = 0; i < total_maquinas; i++) {
        Maquina *m = &maquinas[i];
        printf("ID: %d | Nome: %s | Tipo: %s\n", m->id, m->nome, m->tipo);
    }
}

void atualizar_maquina() {
    printf("\n--- Atualizar Máquina ---\n");
    int id;
    printf("Informe o ID da Máquina para atualizar: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_maquinas) {
        printf("Máquina não encontrada.\n");
        return;
    }

    Maquina *m = &maquinas[id - 1];
    printf("Novo Nome (atual: %s): ", m->nome);
    scanf(" %[^\n]s", m->nome);

    printf("Novo Tipo (atual: %s): ", m->tipo);
    scanf(" %[^\n]s", m->tipo);

    printf("Máquina atualizada com sucesso!\n");
}

void excluir_maquina() {
    printf("\n--- Excluir Máquina ---\n");
    int id;
    printf("Informe o ID da Máquina para excluir: ");
    scanf("%d", &id);

    if (id <= 0 || id > total_maquinas) {
        printf("Máquina não encontrada.\n");
        return;
    }

    for (int i = id; i < total_maquinas; i++) {
        maquinas[i - 1] = maquinas[i];
    }

    total_maquinas--;
    maquinas = realloc(maquinas, total_maquinas * sizeof(Maquina));

    printf("Máquina excluída com sucesso!\n");
}

void maquinas_mais_utilizadas() {
    printf("\n--- Máquinas Mais Utilizadas ---\n");
    printf("Função em desenvolvimento. Dependerá de integração com os processos dos produtos.\n");
}

void tempo_medio_por_maquina() {
    printf("\n--- Tempo Médio por Máquina ---\n");
    printf("Função em desenvolvimento. Dependerá de integração com os processos dos produtos.\n");
}
