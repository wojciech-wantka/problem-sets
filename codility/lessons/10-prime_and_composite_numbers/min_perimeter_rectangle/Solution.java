import java.lang.Math;

class Solution {
    public int solution(int N) {
        int a = 1;
        int b = 1;

        for (a = (int) Math.sqrt(N); a > 0; --a) {
            b = N / a;

            if (a * b == N) {
                break;
            }
        }

        return 2 * (a + b);
    }
}
