#ifndef HISTORY_H
#define HISTORY_H

#define HISTORY_SIZE 10
#define MAX_COMMAND_LEN 1024

// Inicializa el sistema de historial (opcional)
void history_init(void);

// Agrega un comando al historial
void history_add(const char *line);

// Imprime los últimos n comandos
void history_print_last(int n);

// Libera memoria del historial (opcional)
void history_free(void);

void show_history(void);

#endif
