#include <stdio.h>
#include <stdlib.h>

void foo();
void bar(char *fileName, int *pX);

int main() {
    foo();
    return 0;
}

void foo() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
    // To check if x has been properly modified, you can print it
    printf("%d\n", x);
}

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", fileName);
        return;
    }

    char buffer[50]; // Adjust the buffer size as needed

    // Read a line from the file into the buffer
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Use sscanf to parse the integer from the buffer
        if (sscanf(buffer, "%d", pX) != 1) {
            fprintf(stderr, "Failed to parse integer from the file\n");
        }
    } else {
        fprintf(stderr, "Failed to read a line from the file\n");
    }

    fclose(fp);
}
