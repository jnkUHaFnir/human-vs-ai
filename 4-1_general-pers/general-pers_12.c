#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 50
#define MAX_NUM_LINES 40

int main() {
    char line[MAX_LINE_LENGTH];
    char* lines[MAX_NUM_LINES];
    int i = 0;
    int count = 0;

    FILE* in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, in) != NULL && count < MAX_NUM_LINES) {
        lines[count] = strdup(line);
        count++;
    }

    fclose(in);

    for (int j = 0; j < count; j++) {
        // Do something with each line
        printf("Line %d: %s", j, lines[j]);
    }

    // Free memory for each line
    for (int j = 0; j < count; j++) {
        free(lines[j]);
    }

    return 0;
}
