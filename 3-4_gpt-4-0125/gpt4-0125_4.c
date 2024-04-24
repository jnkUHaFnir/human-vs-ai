#include <stdio.h>

int numStrsInList(const char* strList) {
    int count = 0;
    // Start with assuming the list might be empty or NULL.
    if(strList == NULL || *strList == '\0') {
        return 0; // Return 0 since no strings are found, or list is NULL.
    }

    while (1) { // A condition to break inside the loop is safer than trying to guess at the start.
        if (*strList == '\0') {
            // Upon finding a NUL char, immediately look ahead to check if another NUL char follows.
            if (*(strList + 1) == '\0') {
                // If the next character is also NUL, we've reached the list terminator. Break the loop.
                break;
            }
            else {
                // It's the end of a string, but not the end of the list.
                count++;
            }
        }
        strList++; // Move to the next character.
    }
    return count;
}

int main() {
    const char* empty = "\0\0"; // Corrected to match the expected checklist end
    const char* one = "Hell0 \t\n\v\f\rw0r1d\0\0"; // Each test string must end with two NULs
    const char* two = "Hello\0 \t\0\0";
    const char* simple = "Hello\0world\0!\0\0";

    printf("%d\n", numStrsInList(empty)); // Expected output: 0
    printf("%d\n", numStrsInList(one)); // Expected output: 1
    printf("%d\n", numStrsInList(two)); // Expected output: 2
    printf("%d\n", numStrsInList(simple)); // Expected output: 3

    return 0;
}
