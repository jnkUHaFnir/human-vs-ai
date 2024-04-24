#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char temp[1024];
    char* buf;
    int buf_size;

    while (fgets(temp, sizeof(temp), stdin) != NULL) {
        buf_size = strlen(temp) + 1;
        buf = (char*) malloc(buf_size * sizeof(char));

        if (buf == NULL) {
            printf("Error: Memory allocation failed\n");
            return 1;
        }

        strncpy(buf, temp, buf_size);
        buf[buf_size - 1] = '\0'; // Ensure null-termination, in case the input is too long.

        // Process input using buf
        printf("User input: %s", buf);

        // Free memory before the next iteration
        free(buf);
    }

    return 0;
}
