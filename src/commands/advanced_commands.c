#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

#define HISTORY_SIZE 10

static char *history[HISTORY_SIZE];
static int history_count = 0;

/* Guarda cada comando */
void history_add(const char *line) {
    int index = history_count % HISTORY_SIZE;

    free(history[index]);          // libera si ya existía
    history[index] = strdup(line);

    history_count++;
}

/* Muestra SOLO los últimos 10 */
void cmd_historial(char **args) {
    (void) args;

    int total = history_count < HISTORY_SIZE ? history_count : HISTORY_SIZE;
    int start = history_count - total;

    for (int i = 0; i < total; i++) {
        int index = (start + i) % HISTORY_SIZE;
        printf("%d  %s", start + i + 1, history[index]);
    }
}

void cmd_limpiar(char **args) {
    (void) args;   // evita warning
    printf("\033[H\033[J");
}