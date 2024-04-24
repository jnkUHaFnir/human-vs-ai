#include <stdio.h>
#include <stdlib.h>

void save(const str_t * const str, const char *name) {
    FILE* f;
    int i;
    char buffer[64]; // Adjust the buffer size as needed

    if(str->cnt == 0)
        return;

    f = fopen(name, "w");
    if(f == NULL)
        return;

    setvbuf(f, NULL, _IOFBF, 4096); // Set a larger buffer size for improved performance

    for(i = 0; i < str->cnt; i++) {
        snprintf(buffer, sizeof(buffer), "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        fwrite(buffer, 1, strlen(buffer), f);
    }

    fclose(f);
}
