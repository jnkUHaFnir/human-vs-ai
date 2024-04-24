#include <stdio.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    size_t cnt;
} str_t;

void save(const str_t * const str, const char *name)
{
    FILE* f;
    size_t i;
    int buffer[3];

    if(str->cnt == 0)
        return;

    f = fopen(name, "wb");
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++)
    {
        buffer[0] = str->a[i];
        buffer[1] = str->b[i];
        buffer[2] = str->c[i];
        
        fwrite(buffer, sizeof(int), 3, f);
    }
    
    fclose(f);
}
