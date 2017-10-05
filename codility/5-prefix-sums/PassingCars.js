function PassingCars(cars) {
    var goingEast = 0;
    var numberOfPassings = 0;

    for (var i = 0; i < cars.length; ++i) {
        if (cars[i] == 0) {
            ++goingEast;
        } else { // meeting a car going to the east implies increasing number of meetings by actual number of cars going to the east.
            numberOfPassings += goingEast;
        }
    }

    if (numberOfPassings > 1000000000) {
        numberOfPassings = -1;
    }

    return numberOfPassings; 
}
