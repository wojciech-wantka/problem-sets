function Triangle(array) {
    array.sort(function(a, b) { return a - b; });
    var isTriangle = false;
    var max;
    var min1, min2;
    var i = array.length - 1;

    while (i >= 2 && !isTriangle) {
        max = array[i];
        min1 = array[i - 1];
        min2 = array[i - 2];

        if (min1 + min2 > max) {
            isTriangle = true;
        } else {
            --i;
        }
    }

    return (isTriangle ? 1 : 0);
}
