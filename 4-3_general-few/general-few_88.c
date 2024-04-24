#include <stdio.h>

#define BUFFER_SIZE 1000000

char source[BUFFER_SIZE];

FILE *fp = fopen("TheFile.txt", "r");
if (fp != NULL)
{
    size_t bytesRead = fread(source, sizeof(char), BUFFER_SIZE, fp);
    if (bytesRead > 0)
    {
        // Process the content in the buffer
        for (size_t x = 0; x < bytesRead; x++)
        {
            char c = source[x];
            // Process chars
        }
    }
    fclose(fp);
}
