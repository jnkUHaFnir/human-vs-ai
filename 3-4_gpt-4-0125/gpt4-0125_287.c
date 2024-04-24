#include <stdio.h>
#include <string.h>

#define bufSize 1024
#define LINES_PER_BLOCK 4000 // Define how many lines per block to process

void process_block(int lineCount) {
    // Dummy function to represent your manipulations
    // Replace with your actual processing logic
    printf("Processed %d lines.\n", lineCount);
}

int main(int argc, char *argv[]) {
    FILE* fp;
    char buf[bufSize];
    int linesRead = 0; // Counter for lines read

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        return 1;
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror("fopen source-file");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        linesRead++;
        buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
        printf("%s\n", buf); // Or process the line (e.g., store in a buffer for batch processing)

        // If we've read LINES_PER_BLOCK lines, process them
        if (linesRead == LINES_PER_BLOCK) {
            process_block(linesRead); // Process the block
            linesRead = 0; // Reset lines read counter for the next block
        }
    }

    // If there are any lines left after the main loop, process them too
    if (linesRead > 0) {
        process_block(linesRead);
    }

    fclose(fp);
    return 0;
}
