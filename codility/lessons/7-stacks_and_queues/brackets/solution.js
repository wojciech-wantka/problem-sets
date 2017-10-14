function solution(string) {
    var brackets = Array(string.length);
    var isCorrect = true;
    var i = 0;
    var headIndex = 0;

    while (i < string.length && isCorrect) {
        if (string[i] == "(" || string[i] == "[" || string[i] == "{") { // if next bracket is an opening bracket
            brackets[headIndex++] = string[i];
        } else if (closingBracket(brackets[headIndex - 1]) == string[i]) { // if it is an closing bracket: check if the opening bracket laying on the stack head correspond to it.
            --headIndex;
        } else { // if so, then pop this opening bracket
            return 0;
        }

        ++i;
    }

    if (headIndex != 0) {
        isCorrect = false;
    }

    return (isCorrect ? 1 : 0);

    function closingBracket(openingBracket) {
        var bracket;

        switch (openingBracket) {
            case "(": bracket = ")"; break;
            case "[": bracket = "]"; break;
            case "{": bracket = "}"; break;
        }

        return bracket;
    }
}
