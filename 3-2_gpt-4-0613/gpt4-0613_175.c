#include <stdio.h>
#include <stdlib.h>

char *read_string()
{
    char *input = malloc(sizeof(char));  
    if(input == NULL)                     
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    int counter = 0;
    char ch;

    while ((ch = getchar()) != '\n')   //read until detect '\n'
    {
        input[counter] = ch;
        counter++;

        // Reallocate the memory for the new character.
        input = realloc(input, (counter+1) * sizeof(char));

        if(input == NULL)     // If failed to allocate memory, then exit the program.
        {
            printf("Memory not allocated.\n");
            exit(0);
        }

    }

    input[counter] = '\0';  // null terminate the string

    printf("String: %s\n", input);
    printf("Length of string: %d\n", counter);

    return input;
}

void main(){
  char *input = read_string();  // It's the caller responsibility to free the memory after usage.
  
  free(input);
}
