#include <vector>

using namespace std;

bool findLeader(vector<int> &array, int* leader) {
    bool leaderFound = false;
    unsigned int size = 0;
    int value;

    for (unsigned int i = 0; i < array.size(); ++i) {
        if (size == 0) {
            value = array[i];
            ++size;
        } else if (value == array[i]) {
            ++size;
        } else {
            --size;
        }
    }

    if (size > 0) {
        unsigned int count = 0;

        for (unsigned int i = 0; i < array.size(); ++i) {
            if (array[i] == value) {
                ++count;
            }
        }

        if (count > array.size() / 2) {
            *leader = value;
            leaderFound = true;
        }
    }

    return leaderFound;
}

int solution(vector<int> &array) {
    int leader;
    bool leaderFound = findLeader(array, &leader); 

    if (leaderFound) {
        unsigned int i = 0;

        while (array[i] != leader) {
            ++i;
        }

        return i;
    } else {
        return -1;
    }
}
