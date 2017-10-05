import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

public class Main {
    private static int maxNumberOfCities = 10000;

    public static void main(String[] args) throws IOException {
        Graph graph = new Graph(maxNumberOfCities);
        DijkstraOutput dijkstraOutput = new DijkstraOutput(maxNumberOfCities);
        Map<String, Integer> nodeIndexes = new HashMap<>();

        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int numberOfTestCases = Integer.parseInt(bufferedReader.readLine());

        for (int testCase = 0; testCase < numberOfTestCases; ++testCase) {
            loadData(graph, nodeIndexes, bufferedReader);
            dijkstraOutput.clear();

            int numberOfQueries = Integer.parseInt(bufferedReader.readLine());

            for (int queriesResolved = 0; queriesResolved < numberOfQueries; ++queriesResolved) {
                String nextLine = bufferedReader.readLine();
                String[] splitted = nextLine.split(" ");
                String source = splitted[0];
                String destination = splitted[1];

                if (!dijkstraOutput.isComputed(nodeIndexes.get(source))) {
                    List<Integer> distances = graph.dijkstra(nodeIndexes.get(source));
                    dijkstraOutput.addOutput(nodeIndexes.get(source), distances);
                }

                System.out.println(dijkstraOutput.getDistance(nodeIndexes.get(source), nodeIndexes.get(destination)));
            }

            bufferedReader.readLine();
        }
    }

    private static void loadData(Graph graph, Map<String, Integer> nodeIndexes, BufferedReader bufferedReader) throws IOException {
        graph.clear();
        nodeIndexes.clear();

        int numberOfCities = Integer.parseInt(bufferedReader.readLine());

        for (int cityIndex = 0; cityIndex < numberOfCities; ++cityIndex) {
            String cityName = bufferedReader.readLine();

            int numberOfNeighbours = Integer.parseInt(bufferedReader.readLine());
            List<Edge> neighbours = new ArrayList<>(numberOfNeighbours);

            for (int neighboursLoaded = 0; neighboursLoaded < numberOfNeighbours; ++neighboursLoaded) {
                String nextLine = bufferedReader.readLine();
                String[] splitted = nextLine.split(" ");
                int neighbourIndex = Integer.parseInt(splitted[0]) - 1;
                int neighbourDistance = Integer.parseInt(splitted[1]);
                neighbours.add(new Edge(neighbourIndex, neighbourDistance));
            }

            graph.putNeighbours(neighbours);
            nodeIndexes.put(cityName, cityIndex);
        }
    }
}

class Graph {
    private List<List<Edge>> neighbourhood;

    public Graph(int capacity) {
        neighbourhood = new ArrayList<>(capacity);
    }

    public void clear() {
        neighbourhood.clear();

    }

    public void putNeighbours(List<Edge> neighbours) {
        neighbourhood.add(neighbours);
    }

    public List<Integer> dijkstra(int sourceNodeIndex) {
        List<Integer> distances = new ArrayList<>(neighbourhood.size());
        boolean[] isQueued = new boolean[neighbourhood.size()];
        int numberOfQueuedNodes = neighbourhood.size();
        PriorityQueue<Edge> queue = new PriorityQueue<>();

        for (int i = 0; i < neighbourhood.size(); ++i) {
            distances.add(Integer.MAX_VALUE);
        }

        distances.set(sourceNodeIndex, 0);

        for (int i = 0; i < neighbourhood.size(); ++i) {
            queue.add(new Edge(i, distances.get(i)));
            isQueued[i] = true;
        }

        while (numberOfQueuedNodes > 0) {
            Edge nearest = queue.poll();

            if (!isQueued[nearest.getNodeIndex()]) {
                continue;
            }

            isQueued[nearest.getNodeIndex()] = false;
            --numberOfQueuedNodes;

            for (Edge neighbourEdge : neighbourhood.get(nearest.getNodeIndex())) {
                if (isQueued[neighbourEdge.getNodeIndex()]) {
                    int alternative = distances.get(nearest.getNodeIndex()) + neighbourEdge.getDistance();
                    if (alternative < distances.get(neighbourEdge.getNodeIndex())) {
                        distances.set(neighbourEdge.getNodeIndex(), alternative);
                        queue.add(new Edge(neighbourEdge.getNodeIndex(), alternative));
                    }
                }
            }
        }

        return distances;
    }
}

class DijkstraOutput {
    private List<List<Integer>> distances;

    public DijkstraOutput(int capacity) {
        distances = new ArrayList<>(capacity);

        for (int i = 0; i < capacity; ++i) {
            distances.add(null);
        }
    }

    public void clear() {
        for (int i = 0; i < distances.size(); ++i) {
            distances.set(i, null);
        }
    }

    public boolean isComputed(int nodeIndex) {
        return !(distances.get(nodeIndex) == null);
    }

    public void addOutput(int nodeIndex, List<Integer> distances) {
        this.distances.set(nodeIndex, distances);
    }

    public int getDistance(int sourceIndex, int destinationIndex) {
        return distances.get(sourceIndex).get(destinationIndex);
    }
}

class Edge implements Comparable<Edge> {
    private int nodeIndex;
    private int distance;

    public Edge(int nodeIndex, int distance) {
        this.nodeIndex = nodeIndex;
        this.distance = distance;
    }

    public int getNodeIndex() {
        return nodeIndex;
    }

    public int getDistance() {
        return distance;
    }

    @Override
    public int compareTo(Edge that) {
        return distance - that.distance;
    }
}
