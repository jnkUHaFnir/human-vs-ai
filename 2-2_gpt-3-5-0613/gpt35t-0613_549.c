#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* input;
    char temp;
    int i = 0, j = 0;

    input = (char*)malloc(256 * sizeof(char)); // Allocate memory for the input string

    if (input == NULL) // Check if memory allocation was successful
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

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

    free(input); // Free the dynamically allocated memory

    return 0;
}
