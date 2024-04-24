#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t message_len = 1; // + 1 for terminating NULL
    char *buffer = (char*) malloc(message_len);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    for (int i = 0; i < 200000; i++) {
        char tmp[12]; // Assuming the maximum length of an integer is 11 characters
        int size = snprintf(tmp, sizeof(tmp), "%d \n", i);

        char *new_buffer = (char*) realloc(buffer, message_len + size + 1);
        if (new_buffer == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            free(buffer);
            return -1;
        }

        buffer = new_buffer;
        strcat(buffer, tmp);
        message_len += size;
    }

    char substr[56];
    memcpy(substr, buffer, sizeof(substr) - 1);
    substr[sizeof(substr) - 1] = '\0'; // Ensure null-termination

    printf("%s", substr);

    free(buffer);
    
    return 0;
}
