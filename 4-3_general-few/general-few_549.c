#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *input = (char *)malloc(256 * sizeof(char));
    char temp;
    int i = 0, j = 0;

    if (input == NULL) {
        printf("Error allocating memory\n");
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

    free(input); // Free dynamically allocated memory
    return 0;
}
