import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer firstLine = new StringTokenizer(bufferedReader.readLine());
        int knapsackCapacity = Integer.parseInt(firstLine.nextToken());
        int numberOfItems = Integer.parseInt(firstLine.nextToken());

        ItemDescription[] itemDescriptions = new ItemDescription[numberOfItems];

        for (int i = 0; i < numberOfItems; ++i) {
            StringTokenizer itemDescriptionLine = new StringTokenizer(bufferedReader.readLine());
            int size = Integer.parseInt(itemDescriptionLine.nextToken());
            int value = Integer.parseInt(itemDescriptionLine.nextToken());

            itemDescriptions[i] = new ItemDescription(size, value);
        }

        System.out.println(knapsackProblem(itemDescriptions, knapsackCapacity));
    }

    private static int knapsackProblem(ItemDescription[] itemDescriptions, int knapsackCapacity) {
        int[][] dynamicSolutions = new int[itemDescriptions.length + 1][knapsackCapacity + 1];

        for (int numberOfItems = 1; numberOfItems <= itemDescriptions.length; ++numberOfItems) {
            for (int capacity = 0; capacity <= knapsackCapacity; ++capacity) {
                if (itemDescriptions[numberOfItems - 1].size > capacity) {
                    dynamicSolutions[numberOfItems][capacity] = dynamicSolutions[numberOfItems - 1][capacity];
                } else {
                    dynamicSolutions[numberOfItems][capacity] = max(
                        dynamicSolutions[numberOfItems - 1][capacity],
                        dynamicSolutions[numberOfItems - 1][capacity - itemDescriptions[numberOfItems - 1].size] + itemDescriptions[numberOfItems - 1].value
                    );
                }
            }
        }

        return dynamicSolutions[itemDescriptions.length][knapsackCapacity];
    }
}

class ItemDescription {
    public int size;
    public int value;

    public ItemDescription(int size, int value) {
        this.size = size;
        this.value = value;
    }
}
