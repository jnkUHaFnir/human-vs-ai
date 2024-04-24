#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[100];
    int* integers = NULL;
    int integersSize = 0;
    int integersCount = 0;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char* token = strtok(line, ":,\n");

        while (token != NULL) {
            int num = atoi(token);

            // Expand the array if needed
            if (integersCount >= integersSize) {
                integersSize = (integersSize == 0) ? 1 : 2 * integersSize;
                integers = (int*)realloc(integers, integersSize * sizeof(int));
                if (integers == NULL) {
                    fprintf(stderr, "Memory reallocation failed");
                    exit(1);
                }
            }

            integers[integersCount] = num;
            integersCount++;

            token = strtok(NULL, ":,\n");
        }

        // Use the integers array for further processing
        // For now, let's just print the integers
        printf("Integers in current line: ");
        for (int i = 0; i < integersCount; i++) {
            printf("%d ", integers[i]);
        }
        printf("\n");
    }

    if (integers != NULL) {
        free(integers);
    }

    return 0;
}
