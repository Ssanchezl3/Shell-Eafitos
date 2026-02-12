#include <stdio.h>
#include <string.h>
#include "history.h"

static char history[HISTORY_SIZE][MAX_COMMAND_LEN];
static int history_count = 0;
static int history_index = 0;

void add_history(const char *command) {
    if (!command || command[0] == '\n')
        return;

    strncpy(history[history_index], command, MAX_COMMAND_LEN - 1);
    history[history_index][MAX_COMMAND_LEN - 1] = '\0';

    // quitar salto de línea
    history[history_index][strcspn(history[history_index], "\n")] = '\0';

    history_index = (history_index + 1) % HISTORY_SIZE;
    if (history_count < HISTORY_SIZE)
        history_count++;
}

void show_history(void) {
    int start = (history_index - history_count + HISTORY_SIZE) % HISTORY_SIZE;

    for (int i = 0; i < history_count; i++) {
        int idx = (start + i) % HISTORY_SIZE;
        printf("%d  %s\n", i + 1, history[idx]);
    }
}

