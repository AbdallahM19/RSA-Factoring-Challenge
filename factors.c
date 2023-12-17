// factors.c
#include <stdio.h>
#include <stdlib.h>
#include "factors.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_file = argv[1];
    FILE *file = fopen(input_file, "r");

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Factorization result;

    while (fscanf(file, "%lld", &result.n) == 1) {
        result = factorize(result.n);
        printf("%lld=%lld*%lld\n", result.n, result.p, result.q);
    }

    fclose(file);
    return 0;
}

