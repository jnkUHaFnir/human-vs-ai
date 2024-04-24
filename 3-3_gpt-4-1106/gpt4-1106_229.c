#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

int main(int argc, const char * argv[]) {
    const char *s = "This is a test";
    int s_length = my_strlen(s);
    
    // Calculate the new string length: original length + extra length for "gho" - length for one "te"
    int newstring_length = s_length + (3 - 2);
    
    // Allocate memory for the new string
    char *newstring = malloc(newstring_length + 1); // +1 for null terminator
    if (newstring == NULL) {
        fprintf(stderr, "Memory allocation failed!");
        return 1;
    }
    
    // Build the new string
    int j = 0; // Index for writing into the new string
    for (int i = 0; i < s_length; i++) {
        if (s[i] == 't' && s[i+1] == 'e') {
            newstring[j++] = 'g';
            newstring[j++] = 'h';
            newstring[j++] = 'o';
            i++; // Skip the 'e' in "te"
        } else {
            newstring[j++] = s[i];
        }
    }
    
    // Ensure the new string is null-terminated
    newstring[newstring_length] = '\0';
    
    // Print the result
    printf("%s\n", newstring);
    
    // Free the allocated memory
    free(newstring);
    
    return 0;
}
