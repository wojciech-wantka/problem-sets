int cutTrailingZeros(int number) {
    while (number % 2 == 0) {
        number /= 2;
    }

    return number;
}

int returnMaximalBinaryGap(int number) {
    number = cutTrailingZeros(number);

    int maximalBinaryGap = 0;
    int actualBinaryGap = 0;

    while (number != 0) {
        if (number % 2 == 0) {
            ++actualBinaryGap;
        } else {
            if (actualBinaryGap > maximalBinaryGap) {
                maximalBinaryGap = actualBinaryGap;
            }

            actualBinaryGap = 0;
        }

        number /= 2;
    }

    return maximalBinaryGap;
}

int solution(int N) {
    return returnMaximalBinaryGap(N);
}