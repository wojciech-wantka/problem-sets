function Nesting(string) {
    var brackets = Array(string.length);
    var isCorrect = true;
    var i = 0;
    var headIndex = 0;

    while (i < string.length && isCorrect) {
        if (string[i] == "(") {
            brackets[headIndex++] = string[i];
        } else if (headIndex != 0) {
            --headIndex;
        } else {
            isCorrect = false;
        }

        ++i;
    }

    if (headIndex != 0) {
        isCorrect = false;
    }

    return (isCorrect ? 1 : 0);
}
