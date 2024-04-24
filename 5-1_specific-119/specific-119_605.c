#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char line[100]; // assuming each line will not exceed 100 characters
    int numbers[100]; // assuming there will be at most 100 integers per line
    int numbers_count;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char *token;
        numbers_count = 0;

        token = strtok(line, ":, \n");
        while (token != NULL) {
            numbers[numbers_count] = atoi(token);
            numbers_count++;

            token = strtok(NULL, ":, \n");
        }

        // Use the numbers array here for further processing
        for (int i = 0; i < numbers_count; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }

    return 0;
}
