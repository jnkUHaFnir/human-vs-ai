#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *input;
    char temp;
    int i = 0, j;

    // Allocate memory for input string
    input = (char *)malloc(256 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read input string
    printf("Enter a string: ");
    fgets(input, 256, stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    j = strlen(input) - 1;

    while (i < j) {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
        i++;
        j--;
    }

    printf("Reverse = %s\n", input);

    // Free dynamically allocated memory
    free(input);

    return 0;
}
