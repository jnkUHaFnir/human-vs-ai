#include <stdio.h>

#define MAX_FILE_SIZE 1000000

int main() {
    char source[MAX_FILE_SIZE];
    char c;
    int index = 0;

    FILE *fp = fopen("TheFile.txt", "r");
    if(fp != NULL) {
        size_t bytesRead = fread(source, 1, MAX_FILE_SIZE, fp);
        source[bytesRead] = '\0'; // Null-terminate the buffer
        fclose(fp);

        for(int x = 0; (c = source[x]) != '\0'; x++) {
            // Process char c
        }
    }

    return 0;
}
