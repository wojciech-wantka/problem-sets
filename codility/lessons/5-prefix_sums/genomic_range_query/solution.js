function solution(sequence, queryStarts, queryStops) {
    var impact = Array(sequence.length);
    var occurences = Array(sequence.length + 1);
    var answers = Array(queryStarts.length);
    var counter;
    var i, j, k;

    occurences[0] = [0, 0, 0, 0];

    for (i = 0; i < impact.length; ++i) {
        if (sequence[i] == "A") {
            impact[i] = 0;
        } else if (sequence[i] == "C") {
            impact[i] = 1;
        } else if (sequence[i] == "G") {
            impact[i] = 2;
        } else {
            impact[i] = 3;
        }
    }

    for (i = 1; i < occurences.length; ++i) {
        occurences[i] = occurences[i - 1].slice(0); // occurences[i + 1] <- occurences[i]
        ++occurences[i][impact[i - 1]];
    }

    for (i = 0; i < answers.length; ++i) {
        if (queryStarts[i] != queryStops[i]) {
            counter = minus(occurences[queryStops[i] + 1], occurences[queryStarts[i]]);
        } else {
            counter = one(impact[queryStarts[i]], 4);
        }

        for (k = 0; counter[k] == 0; ++k) ;

        answers[i] = k + 1;
    }

    return answers;

    // Returns array containing componentwise differences of two given arrays.
    function minus(array1, array2) {
        var differences = Array(array1.length);
        var i;

        for (i = 0; i < differences.length; ++i) {
            differences[i] = array1[i] - array2[i];
        }

        return differences;
    }

    // Returns array of given "length" containing zeros in all position except for position given as "index".
    function one(index, length) {
        var array = Array(length);
        var i;

        for (i = 0; i < array.length; ++i) {
            array[i] = 0;
        }

        array[index] = 1;
        return array;
    }
}
