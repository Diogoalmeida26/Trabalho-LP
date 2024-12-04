#include "input.h"
#include <stdio.h>
#include <string.h>

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

