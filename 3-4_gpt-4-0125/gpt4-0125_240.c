#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024 * 10 // Adjust buffer size according to your needs

// Efficient integer to string conversion, appends result to buffer
char* itoa_fast(int value, char* buffer, int* len) {
    char* ptr = buffer + *len;
    if(value == 0) {
        *ptr++ = '0';
    } else {
        // Handle negative numbers
        int is_negative = value < 0;
        if (is_negative) {
            value = -value;
            *ptr++ = '-';
        }

        int start_len = ptr - buffer;
        // Convert to string in reverse order
        while (value != 0) {
            *ptr++ = '0' + (value % 10);
            value /= 10;
        }
        *len = ptr - buffer;
        // Reverse the string
        for(int i = start_len, j = *len - 1; i < j; i++, j--) {
            char temp = buffer[i];
            buffer[i] = buffer[j];
            buffer[j] = temp;
        }
    }
    return ptr;
}

void save(const int* a, const int* b, const int* c, int count, const char* name) {
    FILE* f = fopen(name, "w");
    if (!f) return;

    char buffer[BUFFER_SIZE];
    int buflen = 0; // Current length of the buffer content

    for (int i = 0; i < count; i++) {
        // Ensure that the buffer has enough space for the next line
        if (buflen > BUFFER_SIZE - 50) { // 50 is an arbitrary safe margin
            fwrite(buffer, 1, buflen, f);
            buflen = 0;
        }

        itoa_fast(a[i], buffer, &buflen);
        buffer[buflen++] = ' ';
        itoa_fast(b[i], buffer, &buflen);
        buffer[buflen++] = ' ';
        itoa_fast(c[i], buffer, &buflen);
        buffer[buflen++] = '\n';
    }

    // Write any remaining content to the file
    if (buflen > 0) {
        fwrite(buffer, 1, buflen, f);
    }

    fclose(f);
}
