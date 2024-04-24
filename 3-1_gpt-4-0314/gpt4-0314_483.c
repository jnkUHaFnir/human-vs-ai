#include <stdio.h>
#include <string.h>

typedef struct {
    int *a, *b, *c;
    int cnt;
} str_t;

void save(const str_t *const str, const char *name) {
    FILE *f;
    int i;

    if (str->cnt == 0) {
        return;
    }

    f = fopen(name, "wb");
    if (f == NULL) {
        return;
    }

    // Allocate a buffer to speed up the process
    size_t bufsize = str->cnt * 20;
    char *buffer = (char *)malloc(bufsize);
    size_t bufpos = 0;

    for (i = 0; i < str->cnt; i++) {
        // Avoid buffer overflow
        if (bufpos >= bufsize - 20) {
            fwrite(buffer, sizeof(char), bufpos, f);
            bufpos = 0;
        }

        char line[20];
        int len = sprintf(line, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        memcpy(buffer + bufpos, line, len);
        bufpos += len;
    }

    // Write remaining data in the buffer
    if (bufpos > 0) {
        fwrite(buffer, sizeof(char), bufpos, f);
    }

    free(buffer);
    fclose(f);
}
