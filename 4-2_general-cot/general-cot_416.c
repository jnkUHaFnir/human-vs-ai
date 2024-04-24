#include <stdio.h>

unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

// Open all files before writing to them
for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
        char filename[10];
        sprintf(filename, "%dx%d.txt", i, j); // Generate filename dynamically
        hypo_table[i][j] = fopen(filename, "w");
        if (hypo_table[i][j] == NULL) {
            perror("Error opening file");
            return 1; // Exit if file opening fails
        }
    }
}

// Write to each file
for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
        for (size_t hypo_key = 0; hypo_key < 256; hypo_key++) {
            // Process error_array
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            if (hypo_key == 255) {
                break;
            }
        }
    }
}

// Close all files after writing
for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
        fclose(hypo_table[i][j]);
    }
}
