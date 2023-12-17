// factorize.c
#include <math.h>
#include "factors.h"

int is_prime(long long int num) {
    if (num < 2)
        return 0;
    for (long long int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

Factorization factorize(long long int n) {
    Factorization result;
    result.n = n;
    result.p = 1;
    result.q = n;

    for (long long int i = 2; i <= n / 2; ++i) {
        if (n % i == 0 && is_prime(i) && is_prime(n / i)) {
            result.p = i;
            result.q = n / i;
            break;
        }
    }

    return result;
}

