import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer firstLine = new StringTokenizer(bufferedReader.readLine());
        int numberOfTestCases = Integer.parseInt(firstLine.nextToken());
        int divisor = Integer.parseInt(firstLine.nextToken());

        int numberOfDivisable = 0;

        for (int i = 0; i < numberOfTestCases; ++i) {
            int number = Integer.parseInt(bufferedReader.readLine());

            if (number % divisor == 0) {
                ++numberOfDivisable;
            }
        }

        System.out.println(numberOfDivisable);
    }
}