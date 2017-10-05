function CountDiv(a, b, k) {
    var numberOfDivisable;

    if (a % k == 0) {
        numberOfDivisable = Math.floor((B - A) / K) + 1;
    } else {
        numberOfDivisable = Math.floor((B - (A - A % K)) / K);
    }

    return numberOfDivisable;
}
