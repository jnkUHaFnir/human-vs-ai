#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define linesPerBlock 4000

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[bufSize];
    int linesCount = 0;

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
        buf[strcspn(buf, "\n")] = 0; // Remove newline character if present

        printf("%s\n", buf);

        linesCount++;
        
        if (linesCount == linesPerBlock)
        {
            linesCount = 0;
            // Do manipulations here for each block of 4000 lines

            // If you need to stop reading after a certain number of blocks, you can break out of the loop here
            // break;
        }
    }

    fclose(fp);
    return 0;
}
