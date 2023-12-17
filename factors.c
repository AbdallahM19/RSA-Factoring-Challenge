// factors.c
#include <stdio.h>
#include <stdlib.h>
#include "factors.h"

int main(int argc, char *argv[]) {
    FILE *file;
    size_t count;
    ssize_t line;
    char *buffer = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((line = getline(&buffer, &count, file)) != -1) {
        factorize(buffer);
    }

    free(buffer);
    fclose(file);
    return 0;
}
