#include <stdio.h>

// Assume "source" is large enough to hold the entire file plus the null terminator.
char source[1000000];
int index = 0; // This will keep track of where we are in "source".

FILE *fp = fopen("TheFile.txt", "r");
if (fp != NULL)
{
    int symbol;
    while ((symbol = fgetc(fp)) != EOF)
    {
        // Ensure we do not go beyond our buffer size.
        if (index < sizeof(source) - 1)
        {
            source[index] = (char)symbol;
            index++;
        }
        else
        {
            // Handle the case where the file is too large for the buffer.
            // e.g., by setting an error flag or breaking out of the loop.
            fprintf(stderr, "Error: Buffer is full\n");
            break;
        }
    }
    source[index] = '\0'; // Null-terminate the string.
    fclose(fp);
}
else
{
    perror("File open error");
}

// Now "source" contains the contents of the file and is properly null-terminated.
// You can process the buffer as before.
for (int x = 0; source[x] != '\0'; x++)
{
    // Process chars
    char c = source[x];
    // ... your processing code ...
}
