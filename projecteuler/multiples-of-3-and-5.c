#include <stdio.h>

char isDivisableByAny(int number, int divisors[], int divisorsLength) {
    for (int i = 0; i < divisorsLength; ++i) {
        if (number % divisors[i] == 0) {
            return 1;
        }
    }
    return 0;
}

int returnSumOfMultiples(int lowerLimit, int upperLimit, int divisors[], int divisorsLength) {
    int sum = 0;

    for (int number = lowerLimit; number < upperLimit; ++number) {
        if (isDivisableByAny(number, divisors, divisorsLength)) {
            sum += number;
        }
    }

    return sum;
}

int main() {
    int divisors[] = {3, 5};
    int divisorsLength = 2;
    int lowerLimit = 1;
    int upperLimit = 1000;

    printf("Sum of multiples: %d\n", returnSumOfMultiples(lowerLimit, upperLimit, divisors, divisorsLength));
}
