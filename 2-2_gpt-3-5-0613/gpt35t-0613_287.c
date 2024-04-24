#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define blockSize 4000

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[bufSize];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <soure-file>\n", argv[0]);
        return 1;
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("fopen source-file");
        return 1;
    }

    int lineCount = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        buf[strlen(buf) - 1] = '\0'; /* eat the newline fgets() stores */
        printf("%s\n", buf);
        lineCount++;
        if (lineCount == blockSize)
        {
            // Perform manipulations with the block of lines here

            // Clear line count for next block
            lineCount = 0;
        }
    }
    fclose(fp);
    return 0;
}
