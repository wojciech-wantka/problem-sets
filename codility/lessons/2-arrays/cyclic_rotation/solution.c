void rotateOnce(int array[], int length) {
    int last = array[length - 1];

    for (int i = length - 1; i > 0; --i) {
        array[i] = array[i - 1];
    }

    array[0] = last;
}

void rotate(int array[], int length, int k) {
    if (length == 0) {
        return;
    }

    k = k % length;

    for (int i = 0; i < k; ++i) {
        rotateOnce(array, length);
    }
}

struct Results solution(int A[], int N, int K) {
    rotate(A, N, K);

    struct Results result;
    result.A = A;
    result.N = N;

    return result;
}
