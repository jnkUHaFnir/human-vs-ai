#include <stdio.h>
#include <stdlib.h>

char* read_string() {
    int buffer_size = 1;  // Start with a buffer for 1 character
    char* input = malloc(buffer_size);
    
    if (!input) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }
    
    int counter = 0;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Resize the input buffer if it's not big enough
        if (counter + 1 == buffer_size) {
            buffer_size *= 2;
            char* temp = realloc(input, buffer_size);
            if (!temp) {
                free(input);
                fprintf(stderr, "Memory reallocation failed!\n");
                return NULL;
            }
            input = temp;
        }

        // Store the new character
        input[counter++] = ch;
    }
    input[counter] = '\0';  // Null-terminate the string

    // Optional: Shrink the buffer to fit the string
    char* temp = realloc(input, counter + 1);
    if (temp) {
        input = temp;
    } else {
        // If realloc fails, we just use the input buffer with the current size
    }

    printf("Length of string: %d\n", counter);
    return input;  // Return the dynamically allocated string
}

int main() {
    printf("Please enter a string: ");
    char* user_input = read_string();
    
    if (user_input) {
        printf("You entered: %s\n", user_input);
        free(user_input);  // Don't forget to free the memory
    }
    return 0;
}
