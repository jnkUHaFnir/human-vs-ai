#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buf[1024]; // Temporary buffer
    char *str = NULL;
    size_t str_len = 0;

    while (fgets(buf, sizeof(buf), stdin)) {
        size_t buf_len = strlen(buf);
        char *new_str = realloc(str, str_len + buf_len + 1);
        if (new_str == NULL) {
            // Handle allocation failure...
            free(str);
            return 1;
        }
        str = new_str;
        memcpy(str + str_len, buf, buf_len + 1);
        str_len += buf_len;

        if (buf[buf_len - 1] == '\n') {
            // Process or print the complete line.
            printf("Received: %s", str);

            // Reset for the next line
            free(str);
            str = NULL;
            str_len = 0;
        }
    }

    free(str); // Cleanup
    return 0;
}
