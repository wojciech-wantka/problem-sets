struct Results solution(int number_of_counters, int operations[], int number_of_operations) {
    int* counters = (int*) calloc(number_of_counters, sizeof(int));

    int max_count = 0;

    for (int i = 0; i < number_of_operations; ++i) {
        if (operations[i] <= number_of_counters) {
            int counter_index = operations[i] - 1;

            if (max_count == counters[counter_index]) {
                ++max_count;
            }

            ++counters[counter_index];
        } else {
            for (int j = 0; j < number_of_counters; ++j) {
                counters[j] = max_count;
            }
        }
    }

    struct Results result;
    result.C = counters;
    result.L = number_of_counters;

    return result;
}