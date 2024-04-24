#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024
#define LINES_PER_BLOCK 4000

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[BUF_SIZE];
    int line_count = 0;

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

    while (!feof(fp)) // Continue until the end of the file
    {
        // Process in blocks of LINES_PER_BLOCK lines
        for (line_count = 0; line_count < LINES_PER_BLOCK && !feof(fp); line_count++)
        {
            if (fgets(buf, sizeof(buf), fp) != NULL)
            {
                buf[strlen(buf) - 1] = '\0'; // Remove the newline character
                // Perform your line-specific manipulation here
                printf("%s\n", buf);
            }
        }

        // Now we've read LINES_PER_BLOCK lines, or we've reached the end of the file
        // Perform your block-specific manipulation here, if any.

        // You can process buf here or accumulate data from each line before processing
    }

    fclose(fp);
    return 0;
}
