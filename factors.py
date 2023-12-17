#!/usr/bin/python3

import sys
import math

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

def factorize(n):
    for i in range(2, n):
        if n % i == 0 and is_prime(i) and is_prime(n // i):
            return i, n // i
    return n, 1

def main():
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    input_file = sys.argv[1]

    with open(input_file, 'r') as file:
        for line in file:
            n = int(line.strip())
            p, q = factorize(n)
            print(f"{n}={p}*{q}")

if __name__ == "__main__":
    main()

