#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void clearInputBuffer();
int getInt(int minValue, int maxValue, const char *msg);
float getFloat(float minValue, float maxValue, const char *msg);
char getChar(const char *msg);
void readString(char *str, unsigned int size, const char *msg);
void lerNumeroNaoZero(char *numero, const char *msg); // Adicionado protótipo da função

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

#endif // INPUT_H
