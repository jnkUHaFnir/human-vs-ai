#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void readFirstTwoLines(const char *filename, char *line1, char *line2) {
    FILE *f = fopen(filename, "r");

    if (!f) {
        printf("Error opening file.\n");
    } else {
        int c;
        int i = 0;
        int line_count = 0;

        while ((c = fgetc(f)) != EOF) {
            if (c == '\n') {
                if (line_count == 0) {
                    line1[i] = '\0'; // Null-terminate the string
                    line_count++;
                    i = 0;
                } else if (line_count == 1) {
                    line2[i] = '\0'; // Null-terminate the string
                    break; // Finished reading second line
                }
            } else {
                if (line_count == 0) {
                    if (i < MAX_LINE_LENGTH - 1) {
                        line1[i++] = (char)c;
                    }
                } else if (line_count == 1) {
                    if (i < MAX_LINE_LENGTH - 1) {
                        line2[i++] = (char)c;
                    }
                }
            }
        }

        fclose(f);
    }
}

int main() {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];

    readFirstTwoLines("textfile.txt", line1, line2);

    printf("First line: %s\n", line1);
    printf("Second line: %s\n", line2);

    return 0;
}
