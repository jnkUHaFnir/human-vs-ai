#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100   // Adjust the size according to your needs

char* safe_strcat(const char* str1, const char* str2) {
    // Allocate memory for the concatenated string
    char *result = (char*)malloc(MAX_LENGTH * sizeof(char));
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the result as an empty string
    result[0] = '\0';

    // Concatenate str1 to result
    strncat(result, str1, MAX_LENGTH);

    // Concatenate str2 to result
    strncat(result, str2, MAX_LENGTH - strlen(result) - 1);

    return result;
}

int main() {
    const char* var = "variable";
    const char* foo = "foo";
    const char* bar = "bar";

    char* message = safe_strcat("TEXT ", var);
    printf("message: %s\n", message);
    free(message);

    char* message2 = safe_strcat(safe_strcat("TEXT ", foo), safe_strcat(" TEXT ", bar));
    printf("message2: %s\n", message2);
    free(message2);

    return 0;
}
