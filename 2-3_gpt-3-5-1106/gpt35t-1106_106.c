#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *result = malloc(1); // allocate memory for an empty string
    result[0] = '\0'; // make sure the string is properly terminated

    // .. build string out of variable-length data
    for (int i = 0; i < data_length; i++) {
        char *object_str = "some data"; // replace this with the actual data
        result = realloc(result, strlen(result) + strlen(object_str) + 1); // allocate more memory to accommodate the new string
        strcat(result, object_str); // concatenate the new string to the result
    }

    // .. some parts are conditional
    if (freezeCount < 0) {
        result = realloc(result, strlen(result) + 2); // allocate more memory for the additional characters
        strcat(result, "]");
    } else {
        result = realloc(result, strlen(result) + 2); // allocate more memory for the additional characters
        strcat(result, ")");
    }

    printf("%s\n", result); // print the final concatenated string

    free(result); // don't forget to free the allocated memory
    return 0;
}
