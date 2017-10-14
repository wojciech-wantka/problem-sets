function solution(array) {
    var isPresent = Array(array.length + 1);
    var i;
    var isPermutation;

    for (i = 0; i < array.length; ++i) {
        isPresent[array[i] - 1] = true;
    }

    for (i = 0, isPermutation = true; i < array.length && isPermutation; ++i) {
        if (isPresent[i] == undefined) {
            isPermutation = false;
        }
    }

    return (isPermutation ? 1 : 0);
}
