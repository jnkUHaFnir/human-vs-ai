#include <stdio.h>

typedef struct {
    int cnt;
    int *a;
    int *b;
    int *c;
} str_t;

void save(const str_t * const str, const char *name) {
    FILE* f;
    int i;
    char buffer[16]; // Assuming maximum integer size is within 16 bytes

    if(str->cnt == 0)
        return;

    f = fopen(name, "wb");
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++) {
        // Write integers as string
        sprintf(buffer, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, sizeof(char), strlen(buffer), f);
    }

    fclose(f);
}
