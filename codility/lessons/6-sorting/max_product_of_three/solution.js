function solution(array) {
    var max;

    array.sort(function(a, b) { return a - b; });

    var right = array[array.length - 1] * array[array.length - 2] * array[array.length - 3];
    var left = array[0] * array[1] * array[array.length - 1];

    if (right >= left) {
        max = right;
    } else {
        max = left;
    }

    return max;
}
