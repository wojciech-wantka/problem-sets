#include <stdio.h>

void k_center_combinatorial(int number_of_nodes, int distances[][number_of_nodes], int number_of_centers) {
}

void k_center_greedy(int number_of_nodes, int distances[][number_of_nodes], int number_of_centers) {
    char is_center[number_of_nodes];

    is_center[0] = 1;

    for (int i = 1; i < number_of_nodes; ++i) {
        is_center[i] = 0;
    }

    int centers[number_of_centers];
    int number_of_chosen_centers = 0;

    centers[number_of_chosen_centers++] = 0;

    while (number_of_chosen_centers < number_of_centers) {
        int chosen_center;
        int max_compound_distance = 0;

        for (int i = 0; i < number_of_nodes; ++i) {
            if (!is_center[i]) {
                int compound_distance = 0;

                for (int j = 0; j < number_of_chosen_centers; ++j) {
                    compound_distance += distances[i][centers[j]];
                }

                if (compound_distance > max_compound_distance) {
                    max_compound_distance = compound_distance;
                    chosen_center = i;
                }
            }
        }

        is_center[chosen_center] = 1;
        centers[number_of_chosen_centers++] = chosen_center;
    }

    for (int i = 0; i < number_of_nodes; ++i) {
        if (is_center[i]) {
            printf("%d ", i + 1);
        }
    }

    printf("\n");
}

void perform_test_case() {
    int number_of_buildings;
    int number_of_shelters;

    scanf("%d %d", &number_of_buildings, &number_of_shelters);

    int coordinates[number_of_buildings][2];

    for (int i = 0; i < number_of_buildings; ++i) {
        int x;
        int y;

        scanf("%d %d", &x, &y);

        coordinates[i][0] = x;
        coordinates[i][1] = y;
    }

    int distances[number_of_buildings][number_of_buildings];

    for (int i = 0; i < number_of_buildings; ++i) {
        for (int j = 0; j < number_of_buildings; ++j) {
            int x = coordinates[i][0] - coordinates[j][0];
            int y = coordinates[i][1] - coordinates[j][1];
            distances[i][j] = x * x + y * y;
        }
    }

    k_center_greedy(number_of_buildings, distances, number_of_shelters);
}

int main() {
    int number_of_test_cases;

    scanf("%d", &number_of_test_cases);

    for (int i = 0; i < number_of_test_cases; ++i) {
        printf("case %d Y\n", i + 1);
        perform_test_case();
    }
}
