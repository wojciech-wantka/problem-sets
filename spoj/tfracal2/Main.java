import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.SortedMap;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    private final static int numberOfTestCases = 1000;

    public static void main(String[] args) throws IOException {
        Map<String, String> expressions = new HashMap<>();
        Stack<String> variables = new Stack<>();

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        bufferedReader.readLine();

        String line;

        for (int i = 0; i < numberOfTestCases; ++i) {
            while ((line = bufferedReader.readLine()) != null && !line.contains("case")) {
                StringTokenizer tokenizer = new StringTokenizer(line, "=");
                String variable = tokenizer.nextToken();
                String expression = tokenizer.nextToken();
                variables.push(variable);
                expressions.put(variable, expression);
            }

            SortedMap<String, Fraction> fractions = executeCase(expressions, variables);

            System.out.println("case " + (i + 1) + " Y");

            for (String variable : fractions.keySet()) {
                System.out.println(variable + " " + fractions.get(variable));
            }
        }
    }

    private static SortedMap<String, Fraction> executeCase(Map<String, String> expressions, Stack<String> variables) {
        SortedMap<String, Fraction> fractions = new TreeMap<>();

        String initialVariable = variables.pop();
        fractions.put(initialVariable, new Fraction(expressions.get(initialVariable)));

        while (!variables.isEmpty()) {
            String variable = variables.pop();
            fractions.put(variable, computeExpression(expressions.get(variable), fractions));
        }

        return fractions;
    }

    private static Fraction computeExpression(String expression, Map<String, Fraction> fractions) {
        Stack<Fraction> stack = new Stack<>();

        StringTokenizer stringTokenizer = new StringTokenizer(expression, "_*/+", true);

        while (stringTokenizer.hasMoreTokens()) {
            String token = stringTokenizer.nextToken();

            if (token.equals("_")) {
                continue;
            }

            if (token.equals("*") || token.equals("/") || token.equals("+")) {
                Fraction operand2 = stack.pop();
                Fraction operand1 = stack.pop();

                stack.push(Fraction.compute(operand1, operand2, token));
            } else {
                stack.push(fractions.get(token));
            }
        }

        return stack.pop();
    }
}

class Fraction {
    private BigInteger numerator;
    private BigInteger denominator;

    public Fraction() {
    }

    public Fraction(String fractionString) {
        StringTokenizer tokenizer = new StringTokenizer(fractionString, "/");
        numerator = new BigInteger(tokenizer.nextToken());
        denominator = new BigInteger(tokenizer.nextToken());
        normalize();
    }

    public static Fraction compute(final Fraction operand1, final Fraction operand2, String operation) {
        Fraction output = new Fraction();

        if (operation.equals("*")) {
            multiply(output, operand1, operand2);
        } else if (operation.equals("/")) {
            divide(output, operand1, operand2);
        } else {
            add(output, operand1, operand2);
        }

        output.normalize();

        return output;
    }

    @Override
    public String toString() {
        return numerator + " " + denominator;
    }

    private static void multiply(Fraction output, final Fraction operand1, final Fraction operand2) {
        output.numerator = operand1.numerator.multiply(operand2.numerator);
        output.denominator = operand1.denominator.multiply(operand2.denominator);
    }

    private static void divide(Fraction output, final Fraction operand1, final Fraction operand2) {
        output.numerator = operand1.numerator.multiply(operand2.denominator);
        output.denominator = operand1.denominator.multiply(operand2.numerator);
    }

    private static void add(Fraction output, final Fraction operand1, final Fraction operand2) {
        output.numerator = operand1.numerator.multiply(operand2.denominator).add(operand1.denominator.multiply(operand2.numerator));
        output.denominator = operand1.denominator.multiply(operand2.denominator);
    }

    private void normalize() {
        BigInteger gcd = numerator.gcd(denominator);
        numerator = numerator.divide(gcd);
        denominator = denominator.divide(gcd);
    }
}
