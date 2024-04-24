#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define blockCount 4000

int main(int argc, char *argv[]) {
    FILE* fp;
    char buf[bufSize];
    int lineCount = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror("fopen source-file");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        buf[strcspn(buf, "\r\n")] = 0; // remove newline characters

        // Process the line here or store it in an array/vector for later processing

        lineCount++;

        if (lineCount == blockCount) {
            lineCount = 0; // reset line count for next block
            // Additional logic for processing 4000 lines

            // Example: Print a separator
            printf("End of block\n");
        }
    }

    fclose(fp);
    return 0;
}
