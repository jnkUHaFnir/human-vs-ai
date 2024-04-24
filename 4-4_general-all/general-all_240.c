#include <stdio.h>

void save(const str_t * const str, const char *name)
{
    FILE* f;
    int i;
    int data[3]; // Buffer to hold 3 integers

    if(str->cnt == 0)
        return;

    f = fopen(name, "wb"); // Open file in binary write mode
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++)
    {
        data[0] = str->a[i];
        data[1] = str->b[i];
        data[2] = str->c[i];

        fwrite(data, sizeof(int), 3, f); // Write 3 integers at once in binary format
    }
    fclose(f);
}
