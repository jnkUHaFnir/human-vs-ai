#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buf = NULL;
    size_t bufsize = 0;
    
    while (getline(&buf, &bufsize, stdin) != -1) {
        // Remove newline character from the end of input
        buf[strcspn(buf, "\n")] = '\0';
        
        // Process the input string here
        printf("Input: %s\n", buf);
        
        // Free the dynamically allocated input buffer
        free(buf);
        buf = NULL;
        bufsize = 0;
    }
    
    return 0;
}
