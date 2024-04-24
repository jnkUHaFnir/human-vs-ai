#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define block_size 4000

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[bufSize];
    int line_count = 0;

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
        // Perform manipulations on each line here

        line_count++;
        if (line_count % block_size == 0)
        {
            // Manipulations to be done for each block of 4000 lines
            printf("Processed %d lines\n", line_count);
        }
    }

    fclose(fp);
    return 0;
}
