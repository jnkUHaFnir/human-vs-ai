#include <stdio.h>
#include <stdlib.h>

int read_string(char** input)
{
    int capacity = 10; // initial capacity of the array
    int size = 0; // current size of the array
    int counter = 0;
    char ch;

    *input = malloc(capacity * sizeof(char)); // allocate memory for the array

    while ((ch = getchar()) != '\n')   // read until detect '\n'
    {
        if (counter >= capacity) {
            capacity *= 2; // double the capacity if needed
            *input = realloc(*input, capacity * sizeof(char)); // reallocate memory for the array
        }

        (*input)[counter] = ch; // store the character in the array
        counter++;
    }
    (*input)[counter] = '\0'; // add a null terminator to indicate the end of the string
    size = counter;

    printf("Length of string: %d\n", size);

    return size;
}

int main()
{
    char* input;
    read_string(&input);

    printf("Stored string: %s\n", input);

    free(input); // don't forget to free the allocated memory

    return 0;
}
