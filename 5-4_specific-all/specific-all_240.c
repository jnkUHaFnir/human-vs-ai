#include <stdio.h>

void save(const str_t * const str, const char *name)
{
    FILE* f;
    int i;
    char buffer[50]; // Adjust the buffer size based on the expected maximum line length

    if(str->cnt == 0)
        return;

    f = fopen(name, "wb"); // Open in binary mode for better performance
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++)
    {
        int len = snprintf(buffer, sizeof(buffer), "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, 1, len, f);
    }

    fclose(f);
}
