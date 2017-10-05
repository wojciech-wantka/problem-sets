#include <stdio.h>

unsigned int numberOfTrailingZerosInFactorial(unsigned int number) {
    unsigned int powerOf5 = 5;
    unsigned int numberOfTrailingZeros = 0;

    number = number / 5 * 5;

    while (powerOf5 <= number) {
        numberOfTrailingZeros += number / powerOf5;
        powerOf5 *= 5;
    }

    return numberOfTrailingZeros;
}

int main() {
    unsigned int numberOfTests;
    unsigned int i;
    unsigned int number;

    scanf("%d", &numberOfTests);

    for (i = 0; i < numberOfTests; ++i) {
        scanf("%d", &number);
        printf("%d\n", numberOfTrailingZerosInFactorial(number));
    }
}
