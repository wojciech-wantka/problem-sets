import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int numberOfItems = Integer.parseInt(bufferedReader.readLine());

        long[] values = new long[numberOfItems];

        for (int i = 0; i < numberOfItems; ++i) {
            long value = Long.parseLong(bufferedReader.readLine());
            values[i] = value;
        }

        int[] indexes = KarmarkarKarpPartitionFinder.karmarkarKarpPartition(values);

        for (int i = 0; i < indexes.length; ++i) {
            System.out.println(indexes[i] + 1);
        }
    }
}

class KarmarkarKarpPartitionFinder {
    public static int[] karmarkarKarpPartition(long[] values) {
        PriorityQueue<Item> heap = new PriorityQueue<>(values.length, Comparator.comparing(Item::getValue).reversed());

        for (int i = 0; i < values.length; ++i) {
            heap.add(new Item(i, values[i]));
        }

        LinkedList<Pair> pairs = new LinkedList<>();

        Item difference = null;

        while (heap.size() > 1) {
            Item bigger = heap.poll();
            Item smaller = heap.poll();
            pairs.addFirst(new Pair(bigger, smaller));
            difference = new Item(-1, bigger.getValue() - smaller.getValue());
            heap.add(difference);
        }

        List<Item> output = new ArrayList<>(values.length / 2);
        output.add(difference);

        while (!pairs.isEmpty()) {
            Pair pair = pairs.removeFirst();
            Item bigger = pair.getBigger();
            Item smaller = pair.getSmaller();
            difference = new Item(-1, bigger.getValue() - smaller.getValue());

            if (output.contains(difference)) {
                output.remove(difference);
                output.add(bigger);
            } else {
                output.add(smaller);
            }
        }

        int[] indexes = new int[output.size()];

        for (int i = 0; i < indexes.length; ++i) {
            indexes[i] = output.get(i).getIndex();
        }

        return indexes;
    }

    private static class Item {
        private int index;
        private long value;

        public Item(int index, long value) {
            this.index = index;
            this.value = value;
        }

        public int getIndex() {
            return index;
        }

        public long getValue() {
            return value;
        }

        @Override
        public boolean equals(Object thatObject) {
            Item thatItem = (Item) thatObject;
            return value == thatItem.value;
        }
    }

    private static class Pair {
        private Item bigger;
        private Item smaller;

        public Pair(Item bigger, Item smaller) {
            this.bigger = bigger;
            this.smaller = smaller;
        }

        public Item getBigger() {
            return bigger;
        }

        public Item getSmaller() {
            return smaller;
        }
    }
}
