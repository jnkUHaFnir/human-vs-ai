#include <stdio.h>

int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;

    if(!strList || !(*strList)) // Check for NULL pointer or empty string list
        return -1;

    while (*strList != '\0') {
        if (*strList == '\0') {
            if (flag) {
                count++;
                flag = 0;
            } else {
                flag = 1;
            }
        } else {
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

    printf("Number of strings in 'empty': %d\n", numStrsInList(empty));
    printf("Number of strings in 'one': %d\n", numStrsInList(one));
    printf("Number of strings in 'two': %d\n", numStrsInList(two));
    printf("Number of strings in 'simple': %d\n", numStrsInList(simple));

    return 0;
}
