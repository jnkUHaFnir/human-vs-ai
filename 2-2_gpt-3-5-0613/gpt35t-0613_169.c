#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("textfile", "r");
    if (!f) {
        printf("Error opening file.\n");
        return 1;
    }
    
    char line1[100];  // assuming lines will not exceed 100 characters
    char line2[100];

    int c, i = 0;

    // read and store characters until newline or end of file for line1
    while ((c = fgetc(f)) != '\n' && c != EOF && i < 99) {
        line1[i++] = c;
    }
    line1[i] = '\0';  // terminate the string

    i = 0; // reset counter for line2

    // read and store characters until newline or end of file for line2
    while ((c = fgetc(f)) != '\n' && c != EOF && i < 99) {
        line2[i++] = c;
    }
    line2[i] = '\0';  // terminate the string

    printf("Line 1: %s\n", line1);
    printf("Line 2: %s\n", line2);

    fclose(f);

    return 0;
}
