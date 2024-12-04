#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
void cleanInputBuffer();
int getInt(int minValue, int maxValue, const char *msg);
float getFloat(float minValue, float maxValue, const char *msg);
char getChar(const char *msg);
void readString(char *str, unsigned int size, const char *msg);

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    int id[11];
    char nome[50];
    int tele[10];
    int nif[10];
    data d;
}cliente;

#endif //INPUT_H

