#ifndef FACTORS_H
#define FACTORS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    long long int n;
    long long int p;
    long long int q;
} Factorization;

int is_prime(long long int num);
Factorization factorize(long long int n);

#endif // FACTORS_H

