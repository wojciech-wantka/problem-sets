function MinAvgTwoSlice(array) {
    var minAverage = (array[0] + array[1]) / 2;
    var minStart = 0;

    var rightAverage = minAverage;
    var rightStart = minStart;

    var longAverage;
    var shortAverage;

    var i;

    for (i = 1; i < array.length - 1; ++i) {
        longAverage = (rightAverage * (i - rightStart + 1) + array[i + 1]) / (i - rightStart + 2);
        shortAverage = (array[i] + array[i + 1]) / 2;

        if (shortAverage < longAverage) {
            rightAverage = shortAverage;
            rightStart = i;
        } else {
            rightAverage = longAverage;
        }

        if (rightAverage < minAverage) {
            minAverage = rightAverage;
            minStart = rightStart;
        }
    }

    return minStart;
}
