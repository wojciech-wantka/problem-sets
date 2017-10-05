import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int number;

        while ((number = input.nextInt()) != 42) {
            System.out.println(number);
        }
    }
}