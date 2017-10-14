function solution(array) {
    var sum = (1 + array.length + 1) * (array.length + 1) / 2;
    var arraySum = array.reduce(function(a, b) { return a + b; }, 0);

    return sum - arraySum;
}
