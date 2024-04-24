#include <stdio.h>

int main() {
    unsigned char error_array[4][4][256];
    FILE *hypo_table[4][4];

    // Initialize all elements of the hypo_table array
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char filename[10];
            sprintf(filename, "%d%d.txt", i, j); // Generate file name based on i and j
            hypo_table[i][j] = fopen(filename, "w");
            if (hypo_table[i][j] == NULL) {
                perror("Error opening file");
                return 1; // Exit if file opening fails
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int hypo_key = 0; hypo_key < 256; hypo_key++) {
                // Process error_array
                fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            }
        }
    }

    // Remember to close all opened files
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            fclose(hypo_table[i][j]);
        }
    }

    return 0;
}
