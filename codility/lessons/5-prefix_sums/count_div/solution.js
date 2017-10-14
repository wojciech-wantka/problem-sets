function solution(A, B, K) {
    var numberOfDivisable;

    if (A % K == 0) {
        numberOfDivisable = Math.floor((B - A) / K) + 1;
    } else {
        numberOfDivisable = Math.floor((B - (A - A % K)) / K);
    }

    return numberOfDivisable;
}
