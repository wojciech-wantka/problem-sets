function solution(numberOfCounters, operations) {
    var counters = Array.apply(null, Array(numberOfCounters)).map(Number.prototype.valueOf, 0);
    var maxCount = 0;
    var i, j;

    for (i = 0; i < operations.length; ++i) {
        if (operations[i] <= numberOfCounters) {
            if (maxCount == counters[operations[i] - 1]) {
                ++maxCount;
            }

            ++counters[operations[i] - 1];
        } else {
            for (j = 0; j < counters.length; ++j) {
                counters[j] = maxCount;
            }
        }
    }

    return counters;
}
