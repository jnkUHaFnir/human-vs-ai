#include <stdio.h>

int main() {
    char buf[100]; // Adjust the buffer size as needed

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        // Process the input in buf
        // For example, you can remove the newline character if present
        size_t len = strlen(buf);
        if (len > 0 && buf[len-1] == '\n') {
            buf[len-1] = '\0'; // Remove the newline character
        }

        // Do something with buf
        printf("Input: %s\n", buf);
    }

    return 0;
}
