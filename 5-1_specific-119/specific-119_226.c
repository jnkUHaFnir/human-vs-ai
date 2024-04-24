#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 81

int main() {
    FILE *file;
    char buffer[BUFFSIZE];

    file = fopen("in.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char bigWord[30];
    int lineNum = 0;

    while (fgets(buffer, BUFFSIZE, file) != NULL) {
        char currWord[30];
        int bigSize = 0;

        char tempWord[30];
        int tempSize;

        lineNum++;

        // Using sscanf to read words from the line
        char* ptr = buffer;
        while (sscanf(ptr, "%29s%n", tempWord, &tempSize) == 1) {
            ptr += tempSize;
            tempSize = strlen(tempWord);

            if (tempSize > bigSize) {
                strncpy(bigWord, tempWord, sizeof(bigWord) - 1);
                bigWord[sizeof(bigWord) - 1] = '\0'; // Ensure null-termination
                bigSize = tempSize;
            }
        }

        printf("Line %d's word: %s\n", lineNum, bigWord);
    }

    fclose(file);

    return 0;
}
