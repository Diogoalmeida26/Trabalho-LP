#include <stdio.h>
#include <string.h>
#include "maquinas.h"

void criar_maquina(Maquina maquinas[], int *total_maquinas, const char *nome, const char *tipo) {
    if (*total_maquinas >= MAX_MAQUINAS) {
        printf("Limite máximo de máquinas alcançado.\n");
        return;
    }

    Maquina nova_maquina;
    nova_maquina.id = *total_maquinas + 1;
    strncpy(nova_maquina.nome, nome, TAM_NOME - 1);
    nova_maquina.nome[TAM_NOME - 1] = '\0'; 
    strncpy(nova_maquina.tipo, tipo, TAM_TIPO - 1);
    nova_maquina.tipo[TAM_TIPO - 1] = '\0'; 
    nova_maquina.tempo_total_producao = 0;
    nova_maquina.processos_associados = 0;

    maquinas[*total_maquinas] = nova_maquina;
    (*total_maquinas)++;
    printf("Máquina criada com sucesso! ID: %d\n", nova_maquina.id);
}

void listar_maquinas(const Maquina maquinas[], int total_maquinas) {
    printf("\n--- Lista de Máquinas ---\n");

    if (total_maquinas == 0) {
        printf("Nenhuma máquina cadastrada.\n");
        return;
    }

    for (int i = 0; i < total_maquinas; i++) {
        printf("ID: %d | Nome: %s | Tipo: %s | Tempo Total de Produção: %d min | Processos Associados: %d\n",
               maquinas[i].id, maquinas[i].nome, maquinas[i].tipo,
               maquinas[i].tempo_total_producao, maquinas[i].processos_associados);
    }
}

void atualizar_maquina(Maquina maquinas[], int total_maquinas, int id, const char *novo_nome, const char *novo_tipo) {
    if (id <= 0 || id > total_maquinas) {
        printf("Máquina não encontrada.\n");
        return;
    }

    int index = id - 1;

    if (novo_nome != NULL) {
        strncpy(maquinas[index].nome, novo_nome, TAM_NOME - 1);
        maquinas[index].nome[TAM_NOME - 1] = '\0'; // Garantir terminação
    }

    if (novo_tipo != NULL) {
        strncpy(maquinas[index].tipo, novo_tipo, TAM_TIPO - 1);
        maquinas[index].tipo[TAM_TIPO - 1] = '\0'; // Garantir terminação
    }

    printf("Máquina atualizada com sucesso!\n");
}

void excluir_maquina(Maquina maquinas[], int *total_maquinas, int id) {
    if (id <= 0 || id > *total_maquinas) {
        printf("Máquina não encontrada.\n");
        return;
    }

    for (int i = id - 1; i < *total_maquinas - 1; i++) {
        maquinas[i] = maquinas[i + 1];
    }

    (*total_maquinas)--;
    printf("Máquina excluída com sucesso!\n");
}

void relatorio_maquinas_mais_utilizadas(const Maquina maquinas[], int total_maquinas) {
    printf("\n--- Relatório: Máquinas Mais Utilizadas ---\n");

    if (total_maquinas == 0) {
        printf("Nenhuma máquina cadastrada.\n");
        return;
    }

    int max_processos = 0;
    for (int i = 0; i < total_maquinas; i++) {
        if (maquinas[i].processos_associados > max_processos) {
            max_processos = maquinas[i].processos_associados;
        }
    }

    printf("Máquinas com o maior número de processos associados (%d):\n", max_processos);
    for (int i = 0; i < total_maquinas; i++) {
        if (maquinas[i].processos_associados == max_processos) {
            printf("ID: %d | Nome: %s | Tipo: %s | Processos Associados: %d\n",
                   maquinas[i].id, maquinas[i].nome, maquinas[i].tipo, maquinas[i].processos_associados);
        }
    }
}
