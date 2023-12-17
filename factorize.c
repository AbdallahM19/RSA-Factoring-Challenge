// factorize.c
#include <stdio.h>
#include <stdlib.h>
#include "factors.h"

void factorize(char *buffer) {
    unsigned long long num = strtoull(buffer, NULL, 10);

    // Check if conversion to unsigned long long was successful
    if (num == 0 && buffer[0] != '0') {
        fprintf(stderr, "Error: Invalid number - %s\n", buffer);
        return;
    }

    unsigned long long i;
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            printf("%llu=%llu*%llu\n", num, num / i, i);
            break;
        }
    }
}
