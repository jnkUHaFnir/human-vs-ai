#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *input;
    char temp;
    int i = 0, j = 0;
    size_t len = 256; // initial buffer size
    
    // Allocate initial memory for the input
    input = (char *)malloc(len * sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter a string: ");
    
    // Get input safely instead of using scanf
    if (getline(&input, &len, stdin) == -1) {
        fprintf(stderr, "Error reading input\n");
        free(input); // Always free allocated memory if not used
        return 1;
    }
    
    // Remove newline character from getline input
    input[strcspn(input, "\n")] = '\0';

    // Calculate actual length of the input
    j = strlen(input) - 1;
    
    // Reverse the string
    while (i < j)
    {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
        i++;
        j--;
    }
    printf("Reverse = %s\n", input);
    
    // Free the dynamically allocated memory
    free(input);
    
    return 0;
}
