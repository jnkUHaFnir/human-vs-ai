#include <stdio.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    int cnt;
} str_t;

void save(const str_t * const str, const char *name)
{
    FILE* f;
    int i;
    char buffer[20]; // Assuming max int digits

    if(str->cnt == 0)
        return;

    f = fopen(name, "w");
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++)
    {
        sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, sizeof(char), strlen(buffer), f);
    }
    fclose(f);
}
