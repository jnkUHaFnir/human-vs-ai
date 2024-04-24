#include <stdio.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *f;
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];

    f = fopen("textfile.txt", "r");
    
    if (!f) {
        printf("Error opening file.");
        return 1;
    }
    
    // Read the first line
    if (fgets(line1, MAX_LINE_LENGTH, f) != NULL) {
        // Remove the newline character if present
        if (line1[strlen(line1) - 1] == '\n') {
            line1[strlen(line1) - 1] = '\0';
        }
        
        // Read the second line
        if (fgets(line2, MAX_LINE_LENGTH, f) != NULL) {
            // Remove the newline character if present
            if (line2[strlen(line2) - 1] == '\n') {
                line2[strlen(line2) - 1] = '\0';
            }
            
            printf("1st line: %s\n", line1);
            printf("2nd line: %s\n", line2);
        } else {
            printf("Error reading second line.");
        }
    } else {
        printf("Error reading first line.");
    }
    
    fclose(f);
    
    return 0;
}
