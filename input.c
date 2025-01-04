#include "input.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ler_string(const char *mensagem, char *destino, int tamanho) {
    printf("%s", mensagem);
    fgets(destino, tamanho, stdin);

    // Remover '\n' ao final da string
    size_t len = strlen(destino);
    if (len > 0 && destino[len - 1] == '\n') {
        destino[len - 1] = '\0';
    }
}

int ler_inteiro(const char *mensagem) {
    char buffer[50];
    int valor;
    while (1) {
        printf("%s", mensagem);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &valor) == 1) {
            return valor;
        } else {
            printf("Entrada inválida. Digite um número inteiro.\n");
        }
    }
}

