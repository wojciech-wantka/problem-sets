#include <stdio.h>

char checkIfIsLeader(int value, int array[], int length, int* occurrences) {
    *occurrences = 0;

    for (int i = 0; i < length; ++i) {
        if (array[i] == value) {
            ++(*occurrences);
        }
    }

    if (*occurrences > length / 2) {
        return 1;
    } else {
        return 0;
    }
}

int findLeader(int array[], int length, char* isLeader, int* occurrences) {
    int hypotheticalLeader = array[0];
    int sizeOfStack = 1;

    for (int i = 1; i < length; ++i) {
        if (sizeOfStack == 0) {
            hypotheticalLeader = array[i];
            ++sizeOfStack;
        } else if (array[i] == hypotheticalLeader) {
            ++sizeOfStack;
        } else {
            --sizeOfStack;
        }
    }

    if (sizeOfStack == 0) {
        *isLeader = 0;
    } else {
        *isLeader = checkIfIsLeader(hypotheticalLeader, array, length, occurrences);
    }

    return hypotheticalLeader;
}

int findNumberOfEquiLeaders(int array[], int length) {
    char isLeader;
    int occurrences;

    int leader = findLeader(array, length, &isLeader, &occurrences);

    if (!isLeader) {
        return 0;
    }

    int numberOfEquiLeaders = 0;

    int occurrencesInLeft = 0;
    int occurrencesInRight = occurrences;

    for (int i = 0; i < length - 1; ++i) {
        if (array[i] == leader) {
            ++occurrencesInLeft;
            --occurrencesInRight;
        }

        if (
            occurrencesInLeft > (i + 1) / 2 &&
            occurrencesInRight > (length - i - 1) / 2
        ) {
            ++numberOfEquiLeaders;
        }
    }

    return numberOfEquiLeaders;
}

int solution(int array[], int length) {
    return findNumberOfEquiLeaders(array, length);
}
