#include <stdio.h>

int main() {
    int fibonacciFar = 1;
    int fibonacciNear = 2;

    int fibonacciActual;

    int sum = 2;

    while (fibonacciActual <= 4000000) {
        fibonacciActual = fibonacciFar + fibonacciNear;

        fibonacciFar = fibonacciNear;
        fibonacciNear = fibonacciActual;

        if (fibonacciActual % 2 == 0) {
            sum += fibonacciActual;
        }
    }

    printf("Sum of even terms: %d\n", sum);
}
