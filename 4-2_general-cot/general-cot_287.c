#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define blockLines 4000

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
        buf[strlen(buf) - 1] = '\0'; /* eat the newline fgets() stores */
        printf("%s\n", buf);
        
        lineCount++;
        
        if (lineCount == blockLines)
        {
            lineCount = 0;
            // Perform manipulations for 4000 lines block here
            
            // If you want to exit after the first block, you can break here
            // break;
        }
    }

    fclose(fp);
    return 0;
}
