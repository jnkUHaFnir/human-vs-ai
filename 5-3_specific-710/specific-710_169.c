#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("textfile", "r");

    if (!f) {
        printf("Error opening file");
        return 1;
    }

    char line1[100]; // Assuming maximum line length is 100 characters
    char line2[100];
    
    // Read characters for line 1
    int i = 0;
    char c;
    while ((c = fgetc(f)) != '\n' && c != EOF) {
        line1[i++] = c;
    }
    line1[i] = '\0'; // Null-terminate the string

    // Read characters for line 2
    i = 0;
    while ((c = fgetc(f)) != '\n' && c != EOF) {
        line2[i++] = c;
    }
    line2[i] = '\0'; // Null-terminate the string

    printf("Line 1: %s\n", line1);
    printf("Line 2: %s\n", line2);

    fclose(f);
    return 0;
}
