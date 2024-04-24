#include <stdio.h>

unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

// Open all files
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        char filename[10];
        sprintf(filename, "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if (hypo_table[i][j] == NULL) {
            perror("Error opening file");
            // Handle error or exit
            return -1;
        }
    }
}

// Write data to files
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        for (int hypo_key = 0; hypo_key < 256; hypo_key++) {
            // Process error_array
            if (fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]) < 0) {
                perror("Error writing to file");
                // Handle error
            }

            if (hypo_key == 255) {
                break;
            }
        }
    }
}

// Close all files
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        fclose(hypo_table[i][j]);
    }
}
