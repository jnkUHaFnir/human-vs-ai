#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *input = NULL;
    char temp;
    int i = 0, j = 0;

    // Dynamically allocate memory for input
    input = (char*)malloc(256 * sizeof(char));
    if (input == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    // Read user input with error checking
    if (scanf("%255s", input) != 1) {
        printf("Error: Input reading failed\n");
        free(input);
        return 1;
    }

    j = strlen(input) - 1;

    while (i < j)
    {
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
