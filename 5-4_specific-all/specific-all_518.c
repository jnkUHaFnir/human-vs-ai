#include <stdio.h>

#define MAX_SIZE 1000000

int main() {
    char source[MAX_SIZE];
    FILE *fp = fopen("TheFile.txt", "r");

    if(fp != NULL) {
        if(fgets(source, MAX_SIZE, fp) != NULL) {
            // Successfully read the file into the buffer
            // Do whatever you need with the content in source
        } else {
            // Error handling for fgets failure
        }

        fclose(fp);
    } else {
        // Error opening file
    }

    return 0;
}
for(int x = 0; source[x] != '\0'; x++) {
    // Process chars
}
