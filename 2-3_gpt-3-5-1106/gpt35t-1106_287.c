#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define blockSize 4000

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[bufSize];
    int lineCount = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <soure-file>\n", argv[0]);
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    { /* Open source file. */
        perror("fopen source-file");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        buf[strlen(buf) - 1] = '\0'; /* eat the newline fgets() stores */
        printf("%s\n", buf);
        lineCount++;

        if (lineCount == blockSize)
        {
            // Perform manipulations with the 4000 lines here

            // Reset the line count
            lineCount = 0;
        }
    }

    fclose(fp);
    return 0;
}
