#include <stdio.h>

// Assuming str_t struct is defined elsewhere in your code
typedef struct {
    int *a;
    int *b;
    int *c;
    int cnt;
} str_t;

void save(const str_t * const str, const char *name) {
    FILE* f;
    int i, len;
    char buffer[64]; // Assuming that 64 characters is enough for your integers

    if(str->cnt == 0)
        return;

    f = fopen(name, "w");
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++) {
        len = sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, 1, len, f);
    }

    fclose(f);
}
