#include <stdio.h>
#include <stdlib.h>

int main() {
    float number = 1245.12;

    // allocate memory for the string
    char *number_as_string = (char *)malloc(50 * sizeof(char));
    
    if (number_as_string == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // format the float number into a string
    sprintf(number_as_string, "%f", number);

    // use the string
    printf("Number as string: %s\n", number_as_string);

    // free the dynamically allocated memory
    free(number_as_string);

    return 0;
}
