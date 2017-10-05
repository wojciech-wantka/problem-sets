function PermMissingElem(permutation) {
    var isPresent = Array(permutation.length + 1);
    var i;

    for (i = 0; i < permutation.length; ++i) {
        isPresent[permutation[i] - 1] = true;
    }

    i = 0;

    while (isPresent[i]) {
        ++i;
    }

    return i + 1;
}
