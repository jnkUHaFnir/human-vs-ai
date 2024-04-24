#include <stdio.h>
#include <stdlib.h>

int read_string()
{
    char *input = NULL;
    int counter = 0;
    int capacity = 1; // initial capacity for one character

    input = (char*)malloc(capacity * sizeof(char)); // allocate memory for one character

    if (input == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    int ch;
    while ((ch = getchar()) != '\n') {
        input[counter] = (char)ch;
        counter++;

        // Check if more memory needs to be allocated
        if (counter == capacity) {
            capacity *= 2; // double the capacity
            input = (char*)realloc(input, capacity * sizeof(char));

            if (input == NULL) {
                printf("Memory reallocation failed.\n");
                return -1;
            }
        }
    }

    // Null-terminate the string
    input[counter] = '\0';

    printf("String read: %s\n", input);
    printf("Length of string: %d\n", counter);

    free(input); // free dynamically allocated memory

    return 0;
}

int main() {
    read_string();
    return 0;
}
