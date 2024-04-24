#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char staticInput[256];
    char *input;
    char temp;
    int i = 0, j = 0;

    scanf("%s", staticInput);
    // Allocate memory for the dynamic input, +1 for the null terminator
    input = malloc((strlen(staticInput) + 1) * sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;  // Return with error code
    }

    // Copy the scanned string into the dynamically allocated space
    strcpy(input, staticInput);
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

     //Don't forget to free malloc'd memory
    free(input);

    return 0;
}
