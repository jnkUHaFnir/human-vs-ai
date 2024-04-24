#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define linesPerBlock 4000

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

    // Read and process the file block by block
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        buf[strcspn(buf, "\n")] = 0; // Remove newline character

        // Manipulations with the current line can be added here
        
        lineCount++;

        if (lineCount == linesPerBlock)
        {
            // Do manipulations with the block of lines read here

            // Reset lineCount for the next block
            lineCount = 0;
        }
    }

    fclose(fp);
    return 0;
}
