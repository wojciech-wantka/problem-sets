import java.util.Scanner;
import java.util.Reader;

class BigNumber
{
    // "length" is the length of underlying table
	public BigNumber(int length)
	{
	    digits = new int[length];
		size = 0;
	}
	
	public void parse(Reader reader)
	{
	    
	}
	
	// "size" is the number of digits in stored number
	private int size;
	
	private int[] digits;
	
	private static int MAX_SIZE = 500;
}

public class Arith
{
    public static void main(String[] args)
	{
	    Scanner scanner = new Scanner(System.in);
		
		int numberOfTests = scanner.nextInt();
		
		for (int i = 0; i < numberOfTests; ++i)
	}
}

