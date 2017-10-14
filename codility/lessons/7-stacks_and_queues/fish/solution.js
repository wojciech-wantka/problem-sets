function solution(sizes, directions) {
    var fishesGoingDownstream = Array(sizes.length);
    var headIndex = -1;
    var numberOfEatenFishes = 0;
    var i;

    for (i = 0; i < sizes.length; ++i) {
        if (directions[i] == 1) {
            fishesGoingDownstream[++headIndex] = i;
        } else {
            while (headIndex >= 0 && sizes[i] > sizes[fishesGoingDownstream[headIndex]]) {
                --headIndex;
                ++numberOfEatenFishes;
            }

            if (headIndex != -1) {
                ++numberOfEatenFishes;
            }
        }
    }

    return sizes.length - numberOfEatenFishes;
}
