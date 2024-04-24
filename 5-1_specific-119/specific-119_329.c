#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 150
#define MAX_FILE_NAME_LENGTH 30

int main()
{
    char fileName[MAX_FILE_NAME_LENGTH];
    char fileNameW[MAX_FILE_NAME_LENGTH];
    FILE *fPointerForWriting;
    FILE *fPointer;
    char singleLineContent[MAX_LINE_LENGTH];
    int tokenCount = 0;

    printf("Type the name of a file to be read (30 character max): ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = 0;  // Remove newline character

    printf("Type the name of destination file (30 character max): ");
    fgets(fileNameW, sizeof(fileNameW), stdin);
    fileNameW[strcspn(fileNameW, "\n")] = 0;  // Remove newline character

    fPointer = fopen(fileName, "r");
    if (fPointer == NULL) {
        perror("Error opening file for reading");
        return -1;
    }

    fPointerForWriting = fopen(fileNameW, "w");
    if (fPointerForWriting == NULL) {
        perror("Error opening file for writing");
        fclose(fPointer);
        return -1;
    }

    while (fgets(singleLineContent, sizeof(singleLineContent), fPointer)) {
        char *lineCopy = strdup(singleLineContent);  // Create a copy for tokenization
        char *token = strtok(lineCopy, ",\n");
        if (token != NULL) {
            fprintf(fPointerForWriting, "%d", atoi(token));
            tokenCount++;
            while ((token = strtok(NULL, ",\n")) != NULL) {
                fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), tokenCount);
            }
        }
        free(lineCopy);  // Free the allocated memory for the copy
    }

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
