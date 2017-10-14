struct Slice {
    int begin;
    int end;
    int sum;
};

struct Slice findMaximumSlice(int array[], int length) {
    struct Slice maximumSlice;
    struct Slice steppingSlice;

    maximumSlice.begin = 0;
    maximumSlice.end = 0;
    maximumSlice.sum = array[0];

    steppingSlice.begin = 0;
    steppingSlice.sum = array[0];

    for (steppingSlice.end = 1; steppingSlice.end < length; ++steppingSlice.end) {
        if (steppingSlice.sum < 0) {
            steppingSlice.begin = steppingSlice.end;
            steppingSlice.sum = array[steppingSlice.end];
        } else {
            steppingSlice.sum += array[steppingSlice.end];
        }

        if (steppingSlice.sum > maximumSlice.sum) {
            maximumSlice = steppingSlice;
        }
    }

    return maximumSlice;
}

int solution(int array[], int length) {
    return findMaximumSlice(array, length).sum;
}
