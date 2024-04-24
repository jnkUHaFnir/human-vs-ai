#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *input = NULL;
    char temp;
    int i = 0, j = 0;

    // Allocate memory for the input string
    input = (char *)malloc(256 * sizeof(char));
    if (input == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter a string: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character from input

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

    // Free the dynamically allocated memory
    free(input);

    return 0;
}
