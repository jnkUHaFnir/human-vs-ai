#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char* output[500];
    // Assume output array is filled with strings

    for (int j = 1; j < 500; j++) {
        char* doubled = malloc(strlen(output[j]) * 2 + 1); // Allocate memory for doubled string
        if (doubled == NULL) {
            // Handle allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        
        strcpy(doubled, output[j]);
        strcat(doubled, output[j]);

        int count = 0;
        for (int k = 0; k < j; k++) {
            if (strcmp(output[k], output[j]) == 0) {
                strcpy(output[j], doubled);
            }
            if (strcmp(output[k], doubled) == 0) {
                output[j] = "";
                count++;
            }
        }

        if (count >= 2) {
            output[j] = "";
        }

        free(doubled); // Free memory allocated for doubled string
    }

    // Code to handle the processed output array
    return 0;
}
