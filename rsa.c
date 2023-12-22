#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t gcd(uint64_t a, uint64_t b);
uint64_t pollards_rho(uint64_t n);
void factorize(uint64_t n);
// Function to calculate the greatest common divisor using Euclid's algorithm
uint64_t gcd(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to perform Pollard's rho algorithm for factorization
uint64_t pollards_rho(uint64_t n) {
    if (n % 2 == 0) return 2;

    uint64_t x = rand() % (n - 2) + 2;
    uint64_t y = x;
    uint64_t d = 1;

    uint64_t f(uint64_t x) {
        return (x * x + 1) % n;
    }

    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = gcd(abs((int64_t)x - (int64_t)y), n);
    }

    return d;
}

// Function to factorize a number into two prime factors
void factorize(uint64_t n) {
    printf("%lu=", n);

    // Factorize using Pollard's rho algorithm
    while (n > 1) {
        uint64_t factor = pollards_rho(n);
        printf("%lu", factor);
        n /= factor;
        if (n > 1) {
            printf("*");
        }
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the number from the file and factorize it
    uint64_t num;
    while (fscanf(file, "%lu", &num) == 1) {
        factorize(num);
    }

    // Close the file
    fclose(file);

    return 0;
}

