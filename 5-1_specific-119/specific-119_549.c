#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *input = (char *)malloc(256 * sizeof(char));
    char temp;
    int i = 0, j = 0;

    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the trailing newline character

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

    free(input); // Free the allocated memory
    return 0;
}
