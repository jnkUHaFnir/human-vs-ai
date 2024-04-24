#include <stdio.h>

unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

// Initialize all file pointers in the hypo_table array
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        char filename[5];
        sprintf(filename, "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if (hypo_table[i][j] == NULL) {
            // Error handling if file opening fails
            perror("Error opening file");
            return 1; // Exit the program or handle the error accordingly
        }
    }
}

// Write data to the files
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        for (hypo_key = 0; hypo_key < 256; hypo_key++) {
            // Process error_array
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
        }
    }
}

// Close all file pointers when done
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        fclose(hypo_table[i][j]);
    }
}
