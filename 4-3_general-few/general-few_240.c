#include <stdio.h>

typedef struct {
    int *a;
    int *b;
    int *c;
    size_t cnt;
} str_t;

void save(const str_t * const str, const char *name) {
    FILE* f;
    int i;

    if(str->cnt == 0)
        return;

    f = fopen(name, "wb"); // Open the file in binary write mode
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++) {
        int values[3] = { str->a[i], str->b[i], str->c[i] };
        fwrite(values, sizeof(int), 3, f); // Write the integer values directly to the file
        fputc('\n', f); // Add a newline character at the end of each line
    }

    fclose(f);
}
