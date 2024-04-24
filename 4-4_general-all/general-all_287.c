#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define linesPerBlock 4000

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[bufSize];
    int lineCount = 0; // Track the number of lines read

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
        buf[strcspn(buf, "\n")] = '\0'; // Remove newline character

        // Process the line here
        printf("%s\n", buf);

        lineCount++;
        if (lineCount == linesPerBlock)
        {
            lineCount = 0; // Reset line count for next block
            // Additional processing for each block can be done here

            // If you reached here, you processed 4000 lines. You can break out here,
            // or continue to read the next block of lines.
        }
    }

    fclose(fp);
    return 0;
}
