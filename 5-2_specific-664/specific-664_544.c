#include <stdio.h>
#include <stdlib.h>

void bar(char *fileName, int *pX) {
    FILE *fp = fopen(fileName, "r");
    
    if (fp != NULL) { // Check if file was opened successfully
        char buffer[15];
        if (fgets(buffer, 15, fp) != NULL) {
            // Use sscanf to parse the integer value from the buffer
            if (sscanf(buffer, "%d", pX) != 1) {
                printf("Failed to read integer from file.\n");
            }
        }
        else {
            printf("Failed to read from file.\n");
        }
        
        fclose(fp);
    } else {
        printf("Failed to open file.\n");
    }
}

int main() {
    char input[20] = "test.txt";
    int x = 1;
    bar(input, &x);
    printf("Value of x: %d\n", x);
    return 0;
}
