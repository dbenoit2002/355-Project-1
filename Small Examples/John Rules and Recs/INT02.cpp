//Understand integer conversion rules

#include <stdio.h>
#include <limits.h>

int main() {
    short s1 = 30000;
    short s2 = 30000;
    long result;

    result = (long)s1 + (long)s2;

    printf("Correct result of adding two short values: %ld\n", result);

    int signedVal = -10;
    unsigned int unsignedVal = 50;

    printf("Correct comparison result: %d\n", signedVal < (int)unsignedVal);

    return 0;
}
