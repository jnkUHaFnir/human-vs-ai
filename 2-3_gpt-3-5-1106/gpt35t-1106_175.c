#include <stdio.h>
#include <stdlib.h>

int read_string()
{
    char* input = NULL;  // initialize input pointer to NULL
    int counter = 0;
    
    int c;
    while ((c = getchar()) != '\n')
    {
        char* temp = realloc(input, (counter + 1) * sizeof(char));  // dynamically allocate memory for the new character
        if (temp == NULL)
        {
            // handle allocation failure
            free(input);
            return -1;
        }
        
        input = temp;  // update input to point to the new memory
        input[counter] = c;
        counter++;
    }
    
    printf("Length of string: %d\n", counter);
    printf("String: %s\n", input);  // print the complete string
    
    free(input);  // free the allocated memory
    
    return 0;
}

int main()
{
    read_string();
    return 0;
}
