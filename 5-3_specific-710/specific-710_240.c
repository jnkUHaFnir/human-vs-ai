#include <stdio.h>
#include "file.h"

void save(const file_t * const file, const char *name)
{
    FILE* f;
    int i;
    char buffer[50]; // Adjust the buffer size as needed

    if(file->cnt == 0)
        return;

    f = fopen(name, "w");
    if(f == NULL)
        return;

    for(i = 0; i < file->cnt; i++) {
        // Format the integers into a buffer
        int len = snprintf(buffer, sizeof(buffer), "%d %d %d\n", file->a[i], file->b[i], file->c[i]);
        // Write the formatted data to the file using fwrite
        fwrite(buffer, 1, len, f);
    }

    fclose(f);
}
