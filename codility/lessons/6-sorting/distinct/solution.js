function solution(array) {
    var i;
    var actualValue;
    var nextValue;
    var distinctValues = 0;

    array.sort(function(a, b) { return a - b; });

    if (array.length > 0) {
        actualValue = array[0];
        ++distinctValues;
    }

    for (i = 0; i < array.length - 1; ++i) {
        nextValue = array[i + 1];
        if (actualValue != nextValue) {
            ++distinctValues;
            actualValue = nextValue;
        }
    }

    return distinctValues;
}
