#include <stdio.h>

#define MAX_SIZE 1000000

int main() {
    char source[MAX_SIZE];
    FILE *fp = fopen("TheFile.txt", "r");

    if (fp != NULL) {
        size_t pos = 0;
        char line[MAX_SIZE];

        while (fgets(line, sizeof(line), fp) != NULL) {
            // Concatenate the line to the buffer
            size_t len = strlen(line);
            if (pos + len < MAX_SIZE) {
                strncpy(source + pos, line, len);
                pos += len;
            } else {
                // Handle buffer full
                break;
            }
        }

        source[pos] = '\0'; // Null-terminate the buffer
        fclose(fp);

        // Process the buffer
        for (int x = 0; source[x] != '\0'; x++) {
            // Process characters
        }
    }

    return 0;
}
