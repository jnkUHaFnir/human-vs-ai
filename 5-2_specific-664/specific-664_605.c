#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_INTS_PER_LINE 50

int main() {
    char line[MAX_LINE_LENGTH];
    int integers[MAX_INTS_PER_LINE];
    
    while (fgets(line, sizeof(line), stdin) != NULL) {
        int count = 0;
        char* token = strtok(line, ":, \n");
        
        while (token != NULL) {
            integers[count++] = atoi(token);
            token = strtok(NULL, ":, \n");
        }
        
        // Use the integers array for processing tasks
        
        // Print the integers from the current line
        for (int i = 0; i < count; i++) {
            printf("%d ", integers[i]);
        }
        printf("\n");
    }

    return 0;
}
