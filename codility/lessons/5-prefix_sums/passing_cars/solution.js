function solution(cars) {
    var goingEast = 0;
    var numberOfPassings = 0;

    for (var i = 0; i < cars.length; ++i) {
        if (cars[i] == 0) {
            ++goingEast;
        } else {
            numberOfPassings += goingEast;
        }
    }

    if (numberOfPassings > 1000000000) {
        numberOfPassings = -1;
    }

    return numberOfPassings; 
}
