#include <stdio.h>
#include <stdlib.h>

int main() {
    float number = 1245.12;
    
    // allocate memory for the pointer
    char *number_as_string = (char *)malloc(50 * sizeof(char));
    
    if (number_as_string == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    sprintf(number_as_string, "%f", number);
    
    // Print the string
    printf("Number as string: %s\n", number_as_string);

    // Don't forget to free the allocated memory
    free(number_as_string);

    return 0;
}
