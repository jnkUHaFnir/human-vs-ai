#include <stdio.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of the input line

int main() {
    char line[MAX_LINE_LENGTH];
    
    printf("Enter a line of text:\n");
    
    if(fgets(line, sizeof(line), stdin) != NULL) {
        // fgets succeeded
        // Remove the newline character at the end, if present
        char *newline = strchr(line, '\n');
        if (newline != NULL) {
            *newline = '\0'; // Replace newline with null terminator
        }
        
        printf("You entered: %s\n", line);
    } else {
        // fgets failed, handle error
        fprintf(stderr, "Error reading input.\n");
    }
    
    return 0;
}
