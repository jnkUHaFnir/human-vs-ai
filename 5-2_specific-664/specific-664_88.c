#include <stdio.h>

#define MAX_SIZE 1000000

int main() {
    char source[MAX_SIZE];
    int c;
    size_t index = 0;

    FILE *fp = fopen("TheFile.txt", "r");
    if (fp != NULL) {
        while (((c = getc(fp)) != EOF) && (index < MAX_SIZE - 1)) {
            source[index++] = c;
        }
        source[index] = '\0'; // Null-terminate the string
        fclose(fp);

        // Process the content in source
        for (size_t x = 0; source[x] != '\0'; x++) {
            // Process chars
        }
    }
    return 0;
}
