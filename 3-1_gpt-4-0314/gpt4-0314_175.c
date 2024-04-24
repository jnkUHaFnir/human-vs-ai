#include <stdio.h>
#include <stdlib.h>

char *read_string()
{
    char* input = NULL;
    int counter = 0;
    int c;

    while ((c = getchar()) != '\n') //read until detect '\n'
    {
        // Resize input, allocate memory for one more char
        input = realloc(input, (counter + 1) * sizeof(char));

        if (input == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }

        input[counter] = (char) c;
        counter = counter + 1;
    }

    // Allocate memory for the null terminating character '\0'
    input = realloc(input, (counter + 1) * sizeof(char));

    if (input == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    input[counter] = '\0';
    printf("Length of string: %d\n", counter);
    return input;
}

int main()
{
    char *result = read_string();
    printf("The string is: %s\n", result);
    free(result); // Don't forget to free the allocated memory after using it
    return 0;
}
