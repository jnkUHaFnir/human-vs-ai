#include <stdio.h>

int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;

    // Handle empty string list case
    if(!strList || !(*strList))
        return 0;

    while (*strList != '\0' || *(strList + 1) != '\0') {
        if (*strList == '\0') {
            flag++;
        } else if (flag != 0) {
            count++;
            flag = 0;
        }
        strList++;
    }

    return count;
}

int main() {
    const char* empty = "\0";
    const char* one = "Hell0 \t\n\v\f\rw0r1d\0";
    const char* two = "Hello\0 \t\0";
    const char* simple = "Hello\0world\0!\0";

    printf("%d\n", numStrsInList(empty));  // Output: 0
    printf("%d\n", numStrsInList(one));    // Output: 1
    printf("%d\n", numStrsInList(two));    // Output: 2
    printf("%d\n", numStrsInList(simple)); // Output: 3

    return 0;
}