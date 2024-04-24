#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *f = fopen("textfile", "r");

    if (!f) {
        printf("Error opening file\n");
        return 1;
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    char ch;
    int i = 0;
    int line_count = 1;

    while ((ch = fgetc(f)) != EOF && ch != '\n') {
        if (line_count == 1) {
            line1[i++] = ch;
        } else if (line_count == 2) {
            line2[i++] = ch;
        }

        if (ch == ' ') {
            line_count++;
            i = 0;
        }
    }

    line1[i] = '\0'; // Null-terminate the strings
    i = 0;
    while ((ch = fgetc(f)) != EOF && ch != '\n') {
        line2[i++] = ch;
    }
    line2[i] = '\0'; // Null-terminate the second line

    printf("1st line: %s\n", line1);
    printf("2nd line: %s\n");

    fclose(f);

    return 0;
}
