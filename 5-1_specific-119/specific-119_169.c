#include <stdio.h>

int main() {
    FILE *f = fopen("textfile.txt", "r");
    if (!f) {
       printf("Error opening file\n");
       return 1;
    }

    char line1[100]; // assuming max line length is 100 characters
    char line2[100];

    // Read the first line
    fgets(line1, sizeof(line1), f);

    // Read the second line
    fgets(line2, sizeof(line2), f);

    printf("1st line: %s", line1);
    printf("2nd line: %s", line2);

    fclose(f);
    return 0;
}
