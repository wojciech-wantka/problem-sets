#include <iostream>

using namespace std;
typedef unsigned int uint;

const uint MAX_RANGES = 10;

enum BOUNDARY_TYPE {START, STOP};

void SieveOfErastotenes(uint isPrime[], uint startIndex, uint a, uint b) {
    uint i, j;

    if (a == 1) {
        isPrime[startIndex] = 0;
    } else {
        isPrime[startIndex] = 1;
    }

    for (i = startIndex + 1; i < startIndex + b - a + 1; ++i) {
        isPrime[i] = 1;
    }

    for (i = 2; i * i <= b; ++i) {
        j = (a / i) * i;

        if (j < a) {
            j += i;
        }

        for ( ; j <= b; j += i) if (j != i) {
            isPrime[startIndex + j - a] = 0;
        }
    }
}

struct Boundary {
    uint value;
    uint index;
    BOUNDARY_TYPE type;
    Boundary * prev;
    Boundary * next;
};

struct PrimeGenerator {
    uint tests;
    Boundary boundaries[MAX_RANGES][2];
    Boundary * head;
    Boundary * tail;
    uint * isPrime;

    PrimeGenerator(); 
    ~PrimeGenerator();
    void InitSentinels();
    void GenerateList();
    void SpecifyIndexes();
    void SpecifyPrimes();
    void RunCryptosystemSession();
};

PrimeGenerator::PrimeGenerator() {
    uint i, j;

    cin >> tests;

    for (i = 0; i < tests; ++i) {
        for (j = 0; j < 2; ++j) {
            cin >> boundaries[i][j].value;
            boundaries[i][j].type = (BOUNDARY_TYPE) j;
        }
    }
}

PrimeGenerator::~PrimeGenerator() {
    delete [] isPrime;
}

void PrimeGenerator::InitSentinels() {
    boundaries[0][0].prev = 0;
    boundaries[0][0].next = &boundaries[0][1];
    boundaries[0][1].prev = &boundaries[0][0];
    boundaries[0][1].next = 0;
    head = &boundaries[0][0];
    tail = &boundaries[0][1];
}

void PrimeGenerator::GenerateList() {
    uint i;
    int j;
    Boundary * tmp;

    InitSentinels();

    for (i = 1; i < tests; ++i) for (j = 1; j >= 0; --j) {
        for (tmp = head; (tmp != 0) && (boundaries[i][j].value > tmp->value); tmp = tmp->next) ;

        if (tmp == head) {
            boundaries[i][j].prev = 0;
            boundaries[i][j].next = head;
            head = head->prev = &boundaries[i][j];
        } else if (tmp == 0) {
            boundaries[i][j].prev = tail;
            boundaries[i][j].next = 0;
            tail = tail->next = &boundaries[i][j];
        } else {
            boundaries[i][j].prev = tmp->prev;
            boundaries[i][j].next = tmp;
            tmp->prev = tmp->prev->next = &boundaries[i][j];
        }
    }
}

void PrimeGenerator::SpecifyIndexes() {
    uint index;
    Boundary * tmp;

    for (index = 0, head->index = 0, tmp = head->next ; tmp != 0; tmp = tmp->next) {
        if (tmp->prev->type == STOP && tmp->type == START) {
            index += (tmp->value == tmp->prev->value ? 0 : 1);
        } else index += tmp->value - tmp->prev->value;
            tmp->index = index;
    }
}

void PrimeGenerator::SpecifyPrimes() {
    Boundary *left, *right;

    GenerateList();
    SpecifyIndexes();
    isPrime = new uint [tail->index + 1];

    for (left = head; left != 0; left = right->next) {
        for (right = left->next; right != tail && !((right->type == STOP) && (right->next->type == START) && (right->next->value - right->value > 1)); right = right->next) {
            ;
        }

        SieveOfErastotenes (isPrime, left->index, left->value, right->value);
    }
}

void PrimeGenerator::RunCryptosystemSession() {
    uint i, j, k;

    for (i = 0; i < tests; ++i) {
        for (j = boundaries[i][0].index, k = boundaries[i][0].value; j < boundaries[i][1].index + 1; ++j, ++k) {
            if (isPrime[j]) {
                cout << k << endl;
            }
        }

        cout << endl;
    }
}

int main() {
    PrimeGenerator generator;
    cout << endl;
    generator.SpecifyPrimes();
    generator.RunCryptosystemSession();
    
    return 0;
}
