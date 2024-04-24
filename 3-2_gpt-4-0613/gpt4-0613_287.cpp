#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define LINES 4000

int process_lines(char lines[LINES][bufSize], int count)
{
    /* put your lines processing code here */
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", lines[i]);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    FILE* fp;
    char buf[bufSize];
    char lines[LINES][bufSize];
    int idx = 0;
    
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
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
        strcpy(lines[idx], buf);
        idx++;
        
        if (idx == LINES)
        {
            process_lines(lines, LINES);
            idx = 0; // start over for next block of lines
        }
    }
    
    // process leftover lines at the end of file if any
    if (idx > 0)
    {
        process_lines(lines, idx);
    }
    
    fclose(fp);
    return 0;
}
