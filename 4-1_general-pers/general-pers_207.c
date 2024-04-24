#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the zero-terminator
    if (result == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main() {
    srand((unsigned int)time(NULL));
    int r = rand() % 1000000; // Generate a random 6-digit number (between 0 and 999999)

    char numberStr[7]; // Buffer for storing the string representation of the number
    snprintf(numberStr, sizeof(numberStr), "%06d", r); // Format the number as a 6-digit string

    char* result = concat("foo-", numberStr);
    if (result != NULL) {
        printf("%s\n", result);
        free(result); // Free the memory allocated for the result
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
