#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char* input = (char*)malloc(256 * sizeof(char)); // Allocating memory for input string
    if (input == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    char temp;
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf("%255s", input); // Limiting input to 255 characters to avoid buffer overflow

    j = strlen(input) - 1;

    while (i < j)
    {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
        i++;
        j--;
    }

    printf("Reverse = %s", input);

    free(input); // Freeing the allocated memory

    return 0;
}
