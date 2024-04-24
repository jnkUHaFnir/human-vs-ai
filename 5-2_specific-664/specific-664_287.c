#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define blockLines 4000

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[bufSize];
    int linesRead = 0;

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
        buf[strcspn(buf, "\n")] = 0; // Remove newline character
        printf("%s\n", buf);

        linesRead++;
        if (linesRead == blockLines)
        {
            // Do manipulations here for 4000 lines block

            linesRead = 0; // Reset lines read counter for next block
        }
    }

    fclose(fp);
    return 0;
}
