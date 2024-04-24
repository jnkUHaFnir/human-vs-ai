#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    size_t cnt;
} str_t;

void save(const str_t * const str, const char *name)
{
    FILE* f;
    int i;

    if(str->cnt == 0)
        return;

    f = fopen(name, "wb");
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++)
    {
        fwrite(&str->a[i], sizeof(int), 1, f);
        fwrite(&str->b[i], sizeof(int), 1, f);
        fwrite(&str->c[i], sizeof(int), 1, f);
    }

    fclose(f);
}

int main() {
    // Create sample data
    str_t data;
    data.a = (int*)malloc(5 * sizeof(int));
    data.b = (int*)malloc(5 * sizeof(int));
    data.c = (int*)malloc(5 * sizeof(int));
    data.cnt = 5;

    for(int i = 0; i < data.cnt; i++) {
        data.a[i] = i;
        data.b[i] = i*2;
        data.c[i] = i*3;
    }

    // Save the data
    save(&data, "output.txt");

    // Clean up
    free(data.a);
    free(data.b);
    free(data.c);

    return 0;
}
