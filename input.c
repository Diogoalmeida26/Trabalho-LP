#include "input.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void clearInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int obterInteiro(int minValue, int maxValue, const char *msg) {
    int value;
    printf("%s", msg);
    while (scanf("%d", &value) != 1 || value < minValue || value > maxValue) {
        puts(VALOR_INVALIDO);
        clearInputBuffer();
        printf("%s", msg);
    }
    clearInputBuffer();
    return value;
}

    
    float obterFloat(float minValue, float maxValue, const char *msg) {
    float value;
    printf("%s", msg);
    while (scanf("%f", &value) != 1 || value < minValue || value > maxValue) {
        puts(VALOR_INVALIDO);
        clearInputBuffer();
        printf("%s", msg);
    }
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
