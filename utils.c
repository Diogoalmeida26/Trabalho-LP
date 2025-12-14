#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *xrealloc(void *ptr, size_t new_size) {
    void *p = realloc(ptr, new_size);
    if (!p && new_size != 0) {
        fprintf(stderr, "Erro: memoria insuficiente\n");
        exit(1);
    }
    return p;
}

void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta */
    }
}

void ler_string(char *buf, size_t max_len) {
    if (!buf || max_len == 0) return;
    if (fgets(buf, (int)max_len, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    size_t n = strlen(buf);
    if (n > 0 && buf[n - 1] == '\n') buf[n - 1] = '\0';
    else clear_stdin();
}

int ler_int(int *out) {
    if (!out) return 0;
    int value;
    int r = scanf("%d", &value);
    if (r != 1) {
        clear_stdin();
        return 0;
    }
    clear_stdin();
    *out = value;
    return 1;
}

int ler_int_intervalo(int min, int max, int *out) {
    int v;
    if (!ler_int(&v)) return 0;
    if (v < min || v > max) return 0;
    if (out) *out = v;
    return 1;
}

