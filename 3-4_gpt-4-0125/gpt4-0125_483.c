#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 8192 // Adjust based on experimentation

// Example integer to string function - you might need to optimize further
int intToStr(int value, char *str) {
    return sprintf(str, "%d", value);
}

void save(const str_t * const str, const char *name) {
    FILE *f;
    char buffer[BUFFER_SIZE];
    int i;
    int bufPos = 0; // Position in buffer

    if(str->cnt == 0)
        return;

    f = fopen(name, "w");
    if(f == NULL)
        return;

    for(i = 0; i < str->cnt; i++) {
        // Check if we have enough space in buffer, if not, flush it
        if (bufPos > BUFFER_SIZE - 40) { // Rough estimate of max space needed
            fwrite(buffer, bufPos, 1, f);
            bufPos = 0;
        }

        // Convert integers to string directly into the buffer
        bufPos += intToStr(str->a[i], buffer + bufPos);
        buffer[bufPos++] = ' ';
        bufPos += intToStr(str->b[i], buffer + bufPos);
        buffer[bufPos++] = ' ';
        bufPos += intToStr(str->c[i], buffer + bufPos);
        buffer[bufPos++] = '\n';
    }

    if (bufPos > 0) {
        // Write any remaining data in the buffer to the file
        fwrite(buffer, bufPos, 1, f);
    }

    fclose(f);
}

// Placeholder for str_t definition as it's not provided
typedef struct {
    int cnt;
    int *a, *b, *c;
} str_t;
