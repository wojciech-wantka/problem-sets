int reduce(int array[], int length, int (*reductor) (int, int)) {
    int reduction = 0;

    for (int i = 0; i < length; ++i) {
        reduction = reductor(reduction, array[i]);
    }

    return reduction;
}

int xor(int a, int b) {
    return a ^ b;
}

int findSingle(int array[], int length) {
    return reduce(array, length, xor);
}

int solution(int A[], int N) {
    return findSingle(A, N);
}
