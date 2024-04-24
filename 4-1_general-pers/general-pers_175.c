#include <stdio.h>
#include <stdlib.h>

int read_string()
{
    char* input = NULL;
    int counter = 0;
    int capacity = 1;  // Initial capacity of the buffer

    input = (char*) malloc(sizeof(char));

    if (input == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return -1;
    }

    while ((input[counter] = getchar()) != '\n') {
        counter++;

        if (counter >= capacity) {
            capacity *= 2;  // Double the capacity
            char* temp = (char*) realloc(input, capacity * sizeof(char));

            if (temp == NULL) {
                printf("Memory reallocation failed. Exiting.\n");
                free(input);
                return -1;
            }

            input = temp;
        }
    }

    input[counter] = '\0'; // Null-terminate the string

    printf("Input string: %s\n", input);
    printf("Length of string: %d\n", counter);

    free(input); // Free the allocated memory

    return 0;
}

int main()
{
    read_string();

    return 0;
}
