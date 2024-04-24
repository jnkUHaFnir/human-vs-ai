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
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        return 1;
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        perror("fopen source-file");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        buf[strlen(buf) - 1] = '\0'; /* Remove newline character */

        // Process the line here

        lineCount++;

        if (lineCount == blockSize)
        {
            lineCount = 0;
            // Perform manipulations on the block of 4000 lines here

            // Reset the buffer position
            fseek(fp, -strlen(buf) - 1, SEEK_CUR);
            for (int i = 0; i < blockSize; i++)
            {
                fgets(buf, sizeof(buf), fp);
            }
        }
    }
    
    fclose(fp);
    return 0;
}
