int gcd(int a, int b) {
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int solution(int N, int M) {
    return N / gcd(N, M);
}
