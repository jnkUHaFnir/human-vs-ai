#include <stdio.h>
#include <stdlib.h>

char *input(void) {
    int n = 0; // Start with n = 0 since we add the space for the null terminator later
    char *str = NULL; // Initialize str as NULL
    char *current_str;
    int ch; // Use an int to capture EOF as well

    // Allocate space for at least one character
    current_str = realloc(str, sizeof(char));
    if (current_str == NULL) {
        exit(EXIT_FAILURE); // In case realloc fails
    }
    str = current_str;
    
    while ((ch = getchar()) != '\n' && ch != EOF) {
        str[n] = (char)ch;
        n++;
        current_str = realloc(str, sizeof(char) * (n+1)); // +1 for the null terminator
        if (current_str == NULL) {
            free(str); // Free previously allocated memory
            exit(EXIT_FAILURE); // In case realloc fails
        }
        str = current_str;
    }

    str[n] = '\0'; // Null terminate the string
    return str;
}

int main(int argc, char const *argv[]) {
    char *str = input();
    printf("%s\n", str);
    free(str);
    return 0;
}
