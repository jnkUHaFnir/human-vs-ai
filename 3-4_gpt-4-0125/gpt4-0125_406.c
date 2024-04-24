#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 100

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

bool read_line(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';  // Replace newline with null terminator.
        } else if (len == (size - 1)) {
            // Input exceeded buffer size. Clear the input buffer.
            clear_input_buffer();
            printf("Input too long, please try again with shorter input.\n");
            return false; // Indicate that reading was unsuccessful due to long input.
        }
        return true; // Indicate successful read.
    }
    return false; // Indicate failure to read.
}

int main() {
    char input[BUFFER_SIZE];
    printf("Enter your input: ");
    
    while (!read_line(input, BUFFER_SIZE)) {
        printf("Enter your input: "); // Prompt again until a valid input is given.
    }
    
    printf("You entered: %s\n", input);
    return 0;
}
