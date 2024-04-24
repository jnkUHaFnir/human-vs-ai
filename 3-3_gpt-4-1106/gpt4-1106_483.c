#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save(const str_t * const str, const char *name) {
    FILE *f;
    char *buffer;
    size_t bufferSize, offset = 0;
    int i;
    
    if(str->cnt == 0)
        return;
    
    // Estimate buffer size (max 12 digits per int + space or newline, times 3 ints per line)
    bufferSize = str->cnt * (12 * 3 + 1);
    buffer = (char *)malloc(bufferSize * sizeof(char));
    
    if(buffer == NULL)
        return;
    
    for(i = 0; i < str->cnt; i++) {
        offset += snprintf(buffer + offset, bufferSize - offset, "%d %d %d\n", str->a[i], str->b[i], str->c[i]);
        if (offset >= bufferSize)
            break; // Or handle buffer overrun
    }
    
    f = fopen(name, "w");
    if(f == NULL) {
        free(buffer);
        return;
    }

    fwrite(buffer, sizeof(char), offset, f);

    fclose(f);
    free(buffer);
}
