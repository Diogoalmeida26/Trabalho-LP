#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

/* realloc com verificação de erro */
void *xrealloc(void *ptr, size_t new_size);

/* Limpa resto da linha no stdin */
void clear_stdin(void);

/* Lê string com limite e remove newline final */
void ler_string(char *buf, size_t max_len);

/* Lê inteiro; devolve 1 se ok, 0 se falha */
int ler_int(int *out);

/* Lê inteiro dentro de intervalo [min,max]; devolve 1 se ok */
int ler_int_intervalo(int min, int max, int *out);

#endif /* UTILS_H */

