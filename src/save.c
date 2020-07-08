#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "save.h"

void    save_balance_data(int64_t balance[NB_GAME], char* file_name) {
    uint8_t file_name_length = strlen(file_name);
    char folder[FOLDER_LENGTH] = FOLDER_NAME;
    char* path = malloc(sizeof(char) * (FOLDER_LENGTH + file_name_length) + 1);

    memcpy(path, folder, sizeof(char) * FOLDER_LENGTH);
    strcat(path, file_name);

    if (access(file_name, F_OK) != -1) {
        remove(file_name);
    }

    FILE *fd;
    fd = fopen (path, "w");

    if (fd) {
        for (int i = 0; i < NB_GAME; i++) {
            fprintf(fd, "%d,%ld\n", i, balance[i]);
        }
        fclose(fd);
    } else {
        dprintf(2, "%s: fopen() failed\n", path);
    }

    free(path);
}
