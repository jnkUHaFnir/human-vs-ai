#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f;
    char line1[100], line2[100];

    f = fopen("textfile", "r");

    if (!f) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the first line
    if (fgets(line1, sizeof(line1), f) != NULL) {
        // Remove the newline character if present
        line1[strcspn(line1, "\n")] = '\0';
    }

    // Read the second line
    if (fgets(line2, sizeof(line2), f) != NULL) {
        // Remove the newline character if present
        line2[strcspn(line2, "\n")] = '\0';
    }

    fclose(f);

    printf("1st line ==> %s\n", line1);
    printf("2nd line ==> %s\n", line2);

    return 0;
}
