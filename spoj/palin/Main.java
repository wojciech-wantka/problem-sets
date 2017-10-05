import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

enum State {Lesser, Equal, Greater};

class Number {
	public static char[] digits;
	private static boolean isCarry;
	private static int sentinel;
	
	public static void parse(String number) {
		digits = number.toCharArray();
		isCarry = false;
		sentinel = (digits.length - 1) / 2;
	}
	
	private static void increment() {
	    int i = sentinel;
		isCarry = true;
		
		while (isCarry && i >= 0) {
		    if (digits[i] != '9') {
			    isCarry = false;
				++digits[i];
			} else {
			    digits[i] = '0';
				--i;
			}
		}
	}
	
	public static void println() {
		if (isCarry) {
		    digits = new char[digits.length + 1];
			digits[0] = '1';
			for (int i = 1; i < digits.length - 1; ++i) digits[i] = '0';
			digits[digits.length - 1] = '1';
		} else for (int i = 0; i <= sentinel; ++i) digits[digits.length - 1 - i] = digits[i];
			
	    System.out.println (new String(digits));
	}
		
	public static void generateNextPalindrome() {
		State state = State.Equal;

		for (int i = sentinel; i >= 0 && state == State.Equal; --i) {
			char left = digits[i];
			char right = digits[digits.length - 1 - i];
			
		    if (left < right) state = State.Lesser;
			else if (left > right) state = State.Greater;
		}
			
		if (state == State.Lesser || state == State.Equal) increment();
	}
}

public class PALIN {
	public static void main(String[] args) throws IOException {
		BufferedReader bufferedReader = new BufferedReader (new InputStreamReader(System.in));
		int testCases = Integer.parseInt (bufferedReader.readLine());
		
		for (int i = 0; i < testCases; ++i) {
		    Number.parse (bufferedReader.readLine());
			Number.generateNextPalindrome();
			Number.println();
		}
	}
}