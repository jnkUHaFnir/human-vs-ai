float number = 1245.12;

// allocate a character array for the buffer
char number_as_string[50];
sprintf(number_as_string, "%f", number);
float number = 1245.12;

// allocate a pointer
char *number_as_string;
sprintf(number_as_string, "%f", number);
#include <stdio.h>
#include <stdlib.h> // for malloc and free

int main() {
    float number = 1245.12;

    // allocate memory for the pointer
    char *number_as_string = malloc(50); // Allocate space for 50 characters
    if (number_as_string == NULL) {
        // If malloc fails, it returns NULL. Handle the error.
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    sprintf(number_as_string, "%f", number);
    printf("%s\n", number_as_string);

    free(number_as_string); // Don't forget to free the memory when done!
    return 0;
}
