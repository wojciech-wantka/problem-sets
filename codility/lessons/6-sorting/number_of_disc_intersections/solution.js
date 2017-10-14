/* ************************************************************************ */
/* ******************** Brute force approach: O(n ^ 2) ******************** */
/* ************************************************************************ */

function bruteForce(array) {
    var low = Array(array.length);
    var high = Array(array.length);
    var i;
    var j;
    var numberOfIntersections = 0;

    for (i = 0; i < array.length; ++i) {
        low[i] = i - array[i];
        high[i] = i + array[i];
    }

    for (i = 0; i < array.length - 1; ++i) {
        for (j = i + 1; j < array.length; ++j) {
            if ((low[j] <= low[i] && low[i] <= high[j]) || (low[j] <= high[i] && high[i] <= high[j]) || (low[i] <= low[j] && low[j] <= high[i]) || (low[i] <= high[j] && high[j] <= high[i])) {
                ++numberOfIntersections;
            }
        }
    }

    if (numberOfIntersections > 10000000) {
        numberOfIntersections = -1;
    }

    return numberOfIntersections;
}

/* ********************************************************************************************* */
/* ******************** Sorting low and high limits of circles: O(n * lg n) ******************** */
/* ********************************************************************************************* */

function solution(array) {
    var low = Array(array.length);
    var high = Array(array.length);
    var i;
    var highIndex = 0;
    var numberOfIntersections = 0;

    for (i = 0; i < array.length; ++i) {
        low[i] = i - array[i];
        high[i] = i + array[i];
    }

    low.sort(function(a, b) { return a - b; });
    high.sort(function(a, b) { return a - b; });

    for (i = 1; i < array.length; ++i) {
        while (high[highIndex] < low[i]) {
            ++highIndex;
        }

        numberOfIntersections += i - highIndex;
    }

    if (numberOfIntersections > 10000000) {
        numberOfIntersections = -1;
    }

    return numberOfIntersections;
}
