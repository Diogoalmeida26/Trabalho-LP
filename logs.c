#include "logs.h"
#include <stdio.h>
#include <time.h>

#define ARQUIVO_LOG "sistema.log"

void registrar_log(const char *acao, const char *descricao) {
    FILE *arquivo = fopen(ARQUIVO_LOG, "a");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de log");
        return;
    }

    time_t agora = time(NULL);
    char data_hora[20];
    strftime(data_hora, sizeof(data_hora), "%d/%m/%Y %H:%M:%S", localtime(&agora));

    fprintf(arquivo, "[%s] %s: %s\n", data_hora, acao, descricao);
    fclose(arquivo);
}

void exibir_logs() {
    FILE *arquivo = fopen(ARQUIVO_LOG, "r");
    if (!arquivo) {
       
        printf("Nenhum log encontrado.\n");
        return;
    }

    printf("\n=== Logs do Sistema ===\n");
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

