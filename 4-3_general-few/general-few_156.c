#include <stdio.h>
#include <string.h>

int main() {
    char buf[1024]; // Define a buffer with a reasonable size

    while (fgets(buf, sizeof(buf), stdin)) {
        buf[strcspn(buf, "\n")] = '\0'; // Remove the newline character
        // Process the input here

        // Reset the buffer for the next input
        memset(buf, 0, sizeof(buf));
    }

    return 0;
}
