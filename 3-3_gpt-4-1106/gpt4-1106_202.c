#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    int a = 0; // initialize a to 0
    int b = 0; // initialize b to 0

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return (-1);
    }
    while (fgets(buffer, 1024, fp) != NULL) {
        char key[128];
        int value;

        // Parse key and value from the line
        if (sscanf(buffer, "%[^=]=%d", key, &value) == 2) {
            if (strcmp(key, "a") == 0) {
                a = value;
            }
            if (strcmp(key, "b") == 0) {
                b = value;
            }
        }
    }
    fclose(fp); // Close the file after reading is completed
    printf("a=%d, b=%d\n", a, b);
    return 0;
}
