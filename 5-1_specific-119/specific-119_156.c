#include <stdio.h>

int main() {
    char buf[100]; // Make sure to define a proper size for your buffer

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        // Process the input string here
        // (Note: fgets includes the newline character '\n' in the buffer if there is space)
    }

    return 0;
}
