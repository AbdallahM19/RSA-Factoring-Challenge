#include <stdio.h>
#include <stdlib.h>

// Function to find and print the prime factorization of a number
void find_and_times(int n) {
    printf("%d=", n);

    // Find and print the factors
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            printf("%d", i);
            n /= i;
            if (n > 1) {
                printf("*");
            }
        }
    }

    printf("\n");
}

// Function to read numbers from a file and factorize them
void factor_list(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        find_and_times(num);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    factor_list(argv[1]);

    return 0;
}

