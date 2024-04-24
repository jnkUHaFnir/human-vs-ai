#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *input = NULL;
    size_t input_size = 0;
    char temp;
    int i = 0, j = 0;

    printf("Enter the size of the string: ");
    scanf("%zu", &input_size);

    // Allocate memory for the input string
    input = (char *)malloc(input_size * sizeof(char));

    if (input == NULL)
    {
        printf("Memory allocation failed.");
        return 0;
    }

    printf("Enter the string: ");
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
    printf("Reverse = %s", input);

    // Free the allocated memory
    free(input);

    return 0;
}
