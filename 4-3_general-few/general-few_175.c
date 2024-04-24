#include <stdio.h>
#include <stdlib.h>

int read_string()
{
    char* input = NULL;
    int counter = 0;
    int capacity = 1;

    input = (char*)malloc(capacity * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed.");
        return -1;
    }

    char c;
    while ((c = getchar()) != '\n') {
        if (counter == capacity - 1) {
            capacity *= 2;
            input = (char*)realloc(input, capacity * sizeof(char));
            if (input == NULL) {
                printf("Memory reallocation failed.");
                return -1;
            }
        }
        input[counter++] = c;
    }
    input[counter] = '\0'; // Null-terminate the string

    printf("Input string: %s\n", input);
    printf("Length of string: %d\n", counter);

    free(input); // Free the dynamically allocated memory

    return 0;
}

int main()
{
    read_string();

    return 0;
}
