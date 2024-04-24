#include <stdio.h>
#include "file.h" // Assuming this is your header file with struct definition

void save(const str_t * const str, const char *name)
{
    FILE* f;
    int i;
    char buffer[64]; // Buffer to hold the formatted integer strings

    if(str->cnt == 0)
        return;

    f = fopen(name, "wb");  // Open file in binary mode for better performance
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++)
    {
        // Format integers into a single buffer with space and newline
        int len = sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        
        // Write the buffer directly to the file
        fwrite(buffer, 1, len, f);
    }
    
    fclose(f);
}
