#include "input.h"
#include <stdio.h>
#include <string.h>

void clearInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}


