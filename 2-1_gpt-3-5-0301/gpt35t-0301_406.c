#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20

int main() {
    char *input = (char *) malloc(MAX_INPUT_LENGTH * sizeof(char)); // allocate memory for input

    do {
        printf("Enter a string (up to %d characters): ", MAX_INPUT_LENGTH - 1);
        fgets(input, MAX_INPUT_LENGTH, stdin);

        if (strlen(input) == MAX_INPUT_LENGTH - 1 && input[MAX_INPUT_LENGTH - 2] != '\n') {
            // input too long, clear input buffer and ask again
            printf("Input too long. Please enter a shorter string.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            // valid input, remove newline character and print
            input[strcspn(input, "\n")] = '\0';
            printf("Input: %s\n", input);
            break;
        }
    } while (1);

    free(input); // free memory
    return 0;
}
