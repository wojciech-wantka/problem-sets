const int LENGTH_OF_EXPRESSION = 400;

void ReadAlgebraicExpression (char algebraicExpression[LENGTH_OF_EXPRESSION + 1]) {
    int i = 0, endOfExpression = 0;

    while (!endOfExpression) {
        scanf("%c", &algebraicExpression[i]);
        if (algebraicExpression[i] == '\n') {
            algebraicExpression[i] = 0;
            endOfExpression = 1;
        } else {
            ++i;
        }
    }
}

void TransformExpression (char algebraicExpression[LENGTH_OF_EXPRESSION + 1], char rpnExpression[LENGTH_OF_EXPRESSION + 1]) {
    char operatorStack[LENGTH_OF_EXPRESSION + 1];
    int algebraicIndex = 1, rpnIndex = 0, openBrackets = 1, putIndex = 0;

    while (openBrackets) {
        if (algebraicExpression[algebraicIndex] == '(') {
            ++openBrackets;
        } else if (algebraicExpression[algebraicIndex] == ')') {
            --openBrackets;
            rpnExpression[rpnIndex++] = operatorStack[--putIndex];
        } else if (algebraicExpression[algebraicIndex] >= 'a' && algebraicExpression[algebraicIndex] <= 'z') {
            rpnExpression[rpnIndex++] = algebraicExpression[algebraicIndex];
        } else {
            operatorStack[putIndex++] = algebraicExpression[algebraicIndex];
        }

        ++algebraicIndex;
    }
    rpnExpression[rpnIndex] = 0;
}

void PrintRpnExpression (char rpnExpression[LENGTH_OF_EXPRESSION + 1]) {
    int i = 0;

    while (rpnExpression[i] != 0) {
        printf("%c", rpnExpression[i++]);
    }
}

int main() {
    int i, numberOfExpressions;
    char ignored;
    char algebraicExpression[LENGTH_OF_EXPRESSION + 1];
    char rpnExpression[LENGTH_OF_EXPRESSION + 1];

    scanf("%d", &numberOfExpressions);
    scanf("%c", &ignored);

    for (i = 0; i < numberOfExpressions; ++i) {
        ReadAlgebraicExpression(algebraicExpression);
        TransformExpression(algebraicExpression, rpnExpression);
        PrintRpnExpression(rpnExpression);
        printf("\n");
    }

    return 0;
}
