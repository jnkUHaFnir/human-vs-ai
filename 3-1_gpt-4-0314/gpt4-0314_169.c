#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    char line1[100], line2[100]; // Assumes each line has a maximum of 100 characters

    f = fopen("textfile", "r");

    if (!f) {
        printf("error");
    } else {
        // Read the first line and store it in line1
        if (fgets(line1, sizeof(line1), f) != NULL) {
            // Remove newline character from the end of the line
            line1[strcspn(line1, "\n")] = '\0';
        }

        // Read the second line and store it in line2
        if (fgets(line2, sizeof(line2), f) != NULL) {
            // Remove newline character from the end of the line
            line2[strcspn(line2, "\n")] = '\0';
        }

        printf("line1 = \"%s\"\n", line1);
        printf("line2 = \"%s\"\n", line2);

        fclose(f);
    }

    return 0;
}
