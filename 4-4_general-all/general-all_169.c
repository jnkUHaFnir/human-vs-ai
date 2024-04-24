#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100 // maximum length of a line

int main() {
    FILE *f = fopen("textfile", "r");
    char line1[MAX_LEN];
    char line2[MAX_LEN];
    int ch;
    int index = 0;
    int line = 1; // track which line is being read

    if (!f) {
        printf("Error opening file\n");
        return 1;
    }

    while ((ch = fgetc(f)) != EOF && line <= 2) {
        if (ch == '\n') {
            if (line == 1) {
                line1[index] = '\0'; // add null terminator to mark end of line
                line = 2; // move to the next line
                index = 0; // reset index for the next line
            } else if (line == 2) {
                line2[index] = '\0'; // add null terminator to mark end of line
                break; // break out of the loop once second line is read
            }
        } else {
            if (line == 1) {
                line1[index] = (char)ch; // store character in line1
            } else if (line == 2) {
                line2[index] = (char)ch; // store character in line2
            }
            index++;
        }
    }

    printf("1st line ==> %s\n", line1);
    printf("2nd line ==> %s\n", line2);

    fclose(f);
    return 0;
}
