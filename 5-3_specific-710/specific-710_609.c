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
    FILE * fPointerForWriting = fopen(fileNameW, "w");
    FILE * fPointer;
    fPointer = fopen(fileName, "r");

    int i = 1;
    char *singleLineContent = NULL;
    size_t len = 0;
    ssize_t read;

    while((read = getline(&singleLineContent, &len, fPointer)) != -1)
    {
        char *token = strtok(singleLineContent, ",\n");
        fprintf(fPointerForWriting, "%d", atoi(token));
        token = strtok(NULL, ",\n");
        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
        if(token == NULL)
        {
            printf("There are no tokens\n");
            return -3;
        }
        i++;
    }

    // Free dynamically allocated memory
    free(singleLineContent);

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
