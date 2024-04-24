#include <stdio.h>
#include <stdlib.h>

int main() {
    float number = 1245.12;

    // allocate memory for the pointer
    char *number_as_string = (char *)malloc(50 * sizeof(char));
    
    if(number_as_string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    sprintf(number_as_string, "%f", number);

    // do something with number_as_string
    
    // free the dynamically allocated memory
    free(number_as_string);

    return 0;
}
