#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        perror("Error opening the file for writing");
        return -1;
    }

    FILE *fPointer = fopen(fileName, "r");
    if (fPointer == NULL) {
        perror("Error opening the file for reading");
        return -1;
    }

    int i = 1;
    char singleLineContent[256]; // Increase buffer size if necessary

    while (fgets(singleLineContent, sizeof(singleLineContent), fPointer))
    {
        char *token = strtok(singleLineContent, ",\n");
        if (token == NULL) {
            printf("No token found in line %d\n", i);
            return -1;
        }
        fprintf(fPointerForWriting, "%d", atoi(token));

        token = strtok(NULL, ",\n");
        if (token == NULL) {
            printf("Second token not found in line %d\n", i);
            return -1;
        }
        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);

        i++;
    }

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
