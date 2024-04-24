#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *input = NULL;
    char temp;
    int i = 0, j = 0;

    input = (char *)malloc(256 * sizeof(char)); // Allocate memory for input

    if (input == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("Enter a string: ");
    scanf("%s", input);

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
