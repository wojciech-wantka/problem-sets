#include <math.h> /* sqrt */
#include <stdio.h> /* printf */
#include <stdlib.h> /* atoi */

/**
 * To link math library the lm switches must be provided for gcc:
 * $ gcc main.c -lm
 */

typedef unsigned long big;

const int MAX_NUMBER_OF_PRIME_COMPONENTS = 10;

char isPrime(big number) {
    int upperLimit = sqrt(number);

    for (int candidate = 2; candidate <= upperLimit; ++candidate) {
        if (number % candidate == 0) {
            return 0;
        }
    }

    return 1;
}

int performPrimeDecomposition(big number, big primeComponents[]) {
    int numberOfPrimeComponents = 0;

    for (big candidate = 2; candidate <= number; ++candidate) {
        if (number % candidate == 0 && isPrime(candidate)) {
            primeComponents[numberOfPrimeComponents] = candidate;
            ++numberOfPrimeComponents;
        }
    }

    return numberOfPrimeComponents;
}

void dumpArray(int array[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main(int argc, const char* argv[]) {
    big number = atoi(argv[1]);
    int primeComponents[MAX_NUMBER_OF_PRIME_COMPONENTS];

    int numberOfPrimeComponents = performPrimeDecomposition(number, primeComponents);

    dumpArray(primeComponents, numberOfPrimeComponents);
}
