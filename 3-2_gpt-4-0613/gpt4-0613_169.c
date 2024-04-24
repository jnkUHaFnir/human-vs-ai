#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("textfile", "r");
    if (f == NULL) {
        printf("file opening error");
        return 1;
    }

    char ch;
    char line1[100], line2[100]; // make sure your file line doesn't exceed array size
    int i = 0;

    while ((ch = fgetc(f)) != '\n' && ch != EOF) {
        line1[i++] = ch;
    }
    line1[i] = '\0';

    i = 0;

    while ((ch = fgetc(f)) != '\n' && ch != EOF) {
        line2[i++] = ch;
    }
    line2[i] = '\0';

    printf("Line 1: %s\n", line1);
    printf("Line 2: %s\n", line2);

    fclose(f);

    return 0;
}
