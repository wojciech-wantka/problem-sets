#include <stdio.h>

int main() {
    unsigned int value;
    while(scanf("%u", &value), value != 42) printf("%u\n", value);
    return 0;
}