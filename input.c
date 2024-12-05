#include "input.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void clearInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int getInt(int minValue, int maxValue, const char *msg) {
    int value;
    printf("%s", msg);
    while (scanf("%d", &value) != 1 || value < minValue || value > maxValue) {
        puts("INVALID_VALUE_MESSAGE");
        clearInputBuffer();
        printf("%s", msg);
    }
    clearInputBuffer();
    return value;
}

    
    float getFloat(float minValue, float maxValue, const char *msg) {
    float value;
    printf("%s", msg);
    while (scanf("%f", &value) != 1 || value < minValue || value > maxValue) {
        puts("INVALID_VALUE_MESSAGE");
        clearInputBuffer();
        printf("%s", msg);
    }
    clearInputBuffer();
    return value;
}
    
char getChar(const char *msg) {
    char value;
    printf("%s", msg);
    value = getchar();
    clearInputBuffer();
    return value;
}
void readString(char *str, unsigned int size, const char *msg) {
    printf("%s", msg);
    if (fgets(str, size, stdin) != NULL) {
        unsigned int len = strlen(str) - 1;
        if (str[len] == '\n') {
            str[len] = '\0';
        } else {
            clearInputBuffer();
        }
    }
}
void lerNumeroNaoZero(char *numero, const char *msg) {
    int valido = 0;

    do {
        printf("%s", msg);
        readString(numero, 10, ""); // Tamanho 10: 9 dígitos + '\0'

        // Verifica se tem exatamente 9 dígitos
        int tamanho = strlen(numero);
        if (tamanho != 9) {
            puts("Erro: O número deve ter exatamente 9 dígitos.");
            continue;
        }

        // Verifica se todos os caracteres são dígitos
        valido = 1; // Assume que o número é válido
        for (int i = 0; i < tamanho; i++) {
            if (!isdigit(numero[i])) {
                puts("Erro: Apenas números são permitidos.");
                valido = 0;
                break;
            }
        }

        // Verifica se o primeiro dígito é 0
        if (valido && numero[0] == '0') {
            puts("Erro: O número não pode começar com zero.");
            valido = 0;
        }
    } while (!valido);
}
