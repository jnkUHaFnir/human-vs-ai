#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];
    char zahla[128] = {0}; // Initialize array to avoid undefined behavior
    char zahlb[128] = {0}; // Initialize array to avoid undefined behavior

    fp = fopen("./0312.conf", "r");
    if (fp == NULL) {
        perror("error");
        return (-1);
    }
    while (fgets(buffer, 1024, fp) != NULL) {
        char key[128]; // Temporary storage for the key
        char value[128]; // Temporary storage for the value

        // Try to parse the key and value from the buffer
        if (sscanf(buffer, " %[^=]=%s", key, value) == 2) {
            // Check if the key is "a" and if so, copy the value to zahla
            if (strcmp(key, "a") == 0) {
                strncpy(zahla, value, sizeof(zahla) - 1);
            }
            // Check if the key is "b" and if so, copy the value to zahlb
            else if (strcmp(key, "b") == 0) {
                strncpy(zahlb, value, sizeof(zahlb) - 1);
            }
        }
    }
    fclose(fp); // Close the file since we're done with it

    printf("a=%s, b=%s\n", zahla, zahlb);

    return 0;
}
