function MissingInteger(array) {
    var isPresent = Array(array.length);
    var i;

    for (i = 0; i < array.length; ++i) if (array[i] > 0) {
        isPresent[array[i] - 1] = true;
    }

    for (i = 0; i < isPresent.length && isPresent[i]; ++i);

    return i + 1;
}
