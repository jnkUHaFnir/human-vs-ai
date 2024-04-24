#include <stdio.h>
#include <string.h>

#define MAX_LINES 4000
#define bufSize 1024

void processBlock(char block[MAX_LINES][bufSize]) {
    // Replace this with your own code to manipulate the block of lines
    for (int i = 0; i < MAX_LINES; i++) {
        if (strlen(block[i]) == 0) break; // in case less than 4000 lines were filled in the block
        printf("%s", block[i]);
    }
    printf("\nCompleted processing a block of lines.\n");
}

int main(int argc, char *argv[]) {
    FILE* fp;
    char block[MAX_LINES][bufSize];
    int lineCount = 0;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        return 1;
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror("fopen source-file");
        return 1;
    }

    while(fgets(block[lineCount], bufSize, fp) != NULL) {
        if(++lineCount == MAX_LINES) {
            processBlock(block);
            memset(block, 0, sizeof block); // clear
            lineCount = 0; // reset line count
        }
    }
    
    // process remaining lines (less than MAX_LINES)
    if (lineCount > 0) {
        processBlock(block);
    }
    
    fclose(fp);
    return 0;
}
