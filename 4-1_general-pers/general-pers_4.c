#include <stdio.h>

int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;

    if (!strList || !(*strList))
        return -1;

    while (*strList != '\0' || flag != 1) {
        if (*strList == '\0') {
            if (*(strList + 1) == '\0') {
                flag = 1;
            } else {
                count++;
            }
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

    printf("%d\n", numStrsInList(empty));
    printf("%d\n", numStrsInList(one));
    printf("%d\n", numStrsInList(two));
    printf("%d\n", numStrsInList(simple));

    return 0;
}
