#include <stdio.h>
#include <stdlib.h>

char* read_input() 
{
    char *input = NULL; 
    char temp;
    
    // allocates memory block
    input = (char*)malloc(sizeof(char));
    // checks whether memory has been successfully allocated
    if(input == NULL) 
    {
        printf("Error in memory allocation.\n");
        exit(0);
    }

    int i = 0;
    while((temp = getchar()) != '\n')
    {
        input[i++] = temp;
        // when i reaches the limit, reallocate 
        input = realloc(input, (i+1) * sizeof(char)); 
        if(input == NULL) 
        {
            printf("Error in memory allocation.\n");
            exit(0);
        }
    }
    // null terminate the string
    input[i] = '\0'; 

    return input;
}

int main()
{
    char* str;
    printf("Enter the address:\n");
    str = read_input();
    printf("Address: %s", str);
    // Don't forget to free the allocated memory
    free(str);
    return 0;
}
