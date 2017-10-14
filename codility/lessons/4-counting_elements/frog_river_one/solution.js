function solution(destination, targets) {
    var trajectory = Array(destination)

    for (var i = 0; i < targets.length; ++i) {
        if (targets[i] < destination + 1 && trajectory[targets[i] - 1] == undefined) {
            trajectory[targets[i] - 1] = i;
        }
    }

    var time = Math.max.apply(null, trajectory);

    return (isNaN(time) ? -1 : time);
}
