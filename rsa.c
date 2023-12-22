#include <stdio.h>

int is_prime(unsigned long long number) {
    if (number < 2) {
        return 0;
    }
    unsigned long long i;
    for (i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

void factorize_number(unsigned long long number) {
    unsigned long long i;
    for (i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            if (is_prime(i) && is_prime(number / i)) {
                printf("%llu=%llu*%llu\n", number, number / i, i);
                return;
            }
        }
    }
    printf("Prime factors not found for %llu\n", number);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: rsa <file>\n");
        return 1;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file '%s'\n", filename);
        return 1;
    }

    unsigned long long number;
    if (fscanf(file, "%llu", &number) != 1) {
        printf("Invalid number in the file\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    factorize_number(number);

    return 0;
}
