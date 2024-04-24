int numStrsInList(const char* strList) {
    int count = 0;
    char last_char = 1; // Initialize with any character other than '\0'

    while (*strList || last_char) {
        if (*strList == '\0' && last_char == '\0') {
            count++;
        }
        last_char = *strList;
        strList++;
    }
    return count;
}
#include <stdio.h>

int numStrsInList(const char* strList) {
    int count = 0;
    char last_char = 1; // Initialize with any character other than '\0'

    while (*strList || last_char) {
        if (*strList == '\0' && last_char == '\0') {
            count++;
        }
        last_char = *strList;
        strList++;
    }
    return count;
}

int main() {
    const char* empty = "\0";
    const char* one = "Hell0 \t\n\v\f\rw0r1d\0";
    const char* two = "Hello\0 \t\0";
    const char* simple = "Hello\0world\0!\0";

    printf("empty: %d\n", numStrsInList(empty));
    printf("one: %d\n", numStrsInList(one));
    printf("two: %d\n", numStrsInList(two));
    printf("simple: %d\n", numStrsInList(simple));

    return 0;
}
empty: 0
one: 1
two: 2
simple: 3
