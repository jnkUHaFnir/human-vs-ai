#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    char line1[100];
    char line2[100];

    f = fopen("textfile.txt", "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    if (fgets(line1, sizeof(line1), f) != NULL) {
        // Remove trailing newline character if present
        if (line1[strlen(line1) - 1] == '\n') {
            line1[strlen(line1) - 1] = '\0';
        }
    }

    if (fgets(line2, sizeof(line2), f) != NULL) {
        // Remove trailing newline character if present
        if (line2[strlen(line2) - 1] == '\n') {
            line2[strlen(line2) - 1] = '\0';
        }
    }

    printf("1st line: %s\n", line1);
    printf("2nd line: %s\n", line2);

    fclose(f);
    return 0;
}
