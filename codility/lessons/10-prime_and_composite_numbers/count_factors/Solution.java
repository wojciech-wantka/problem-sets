import static java.lang.Math.sqrt;

class Solution {
    public int solution(int N) {
        int numberOfFactors = 0;
        int pivot = (int) sqrt(N);

        for (int i = 1; i <= pivot; ++i) {
            if (N % i == 0) {
                numberOfFactors += 2;
            }
        }

        if (pivot * pivot == N) {
            --numberOfFactors;
        }

        return numberOfFactors;
    }
}
