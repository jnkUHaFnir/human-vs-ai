#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Type the name of a file to be read (30 character max): ");
    char fileName[30];
    scanf("%s", fileName);
    printf("Type the name of destination file (30 character max): ");
    char fileNameW[30];
    scanf("%s", fileNameW);

    FILE *fPointerForWriting = fopen(fileNameW, "w");
    if (fPointerForWriting == NULL) {
        perror("Error opening file for writing");
        return -1;
    }

    FILE *fPointer = fopen(fileName, "r");
    if (fPointer == NULL) {
        perror("Error opening file for reading");
        fclose(fPointerForWriting);
        return -2;
    }

    int i = 1;
    char singleLineContent[150];

    while (fgets(singleLineContent, 150, fPointer)) {
        char *token = strtok(singleLineContent, ",\n");
        if (token == NULL) {
            printf("There are no tokens\n");
            break;
        }

        fprintf(fPointerForWriting, "%d", atoi(token));
        token = strtok(NULL, ",\n");
        if (token == NULL) {
            printf("Incomplete line at %d\n", i);
            break;
        }

        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
        i++;
    }

    if (ferror(fPointer)) {
        perror("Error reading from file");
    }

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
