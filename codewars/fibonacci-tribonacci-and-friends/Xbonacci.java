import java.util.Arrays;
import java.util.stream.DoubleStream;

public class Xbonacci {
    public double[] xbonacci(double[] signature, int lengthOfSequence) {
        double[] sequence = Arrays.copyOf(signature, lengthOfSequence);

        if (sequence.length > signature.length) {
            sequence[signature.length] = DoubleStream.of(signature).sum();

            for (int i = signature.length + 1; i < sequence.length; ++i) {
                sequence[i] = 2 * sequence[i - 1] - sequence[i - signature.length - 1];
            }
        }

        return sequence;
    }
}
