#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define LINES_PER_BLOCK 4000

void process_lines(char lines[LINES_PER_BLOCK][bufSize], int num_lines) {
    // Do your manipulations with the block of lines here.
    // Use num_lines to know the actual number of lines if less than LINES_PER_BLOCK.
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }
}

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[bufSize];
    char lines[LINES_PER_BLOCK][bufSize];
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
        strncpy(lines[line_count], buf, bufSize);
        line_count++;

        if (line_count == LINES_PER_BLOCK) {
            process_lines(lines, line_count);
            line_count = 0; // Reset the line count for the next block
        }
    }

    // Process the remaining lines, if any
    if (line_count > 0) {
        process_lines(lines, line_count);
    }

    fclose(fp);
    return 0;
}
