#include <stdio.h>

int main()
{
    char source[1000000]; // Buffer to read file contents
    FILE *fp = fopen("TheFile.txt", "r");

    if(fp != NULL)
    {
        size_t bytes_read = fread(source, 1, sizeof(source), fp);
        source[bytes_read] = '\0'; // Null-terminate the string

        fclose(fp);

        for(size_t x = 0; x < bytes_read; x++)
        {
            char c = source[x];
            // Process each character
            // You can process 'c' here instead of using source[x]
        }
    }

    return 0;
}
