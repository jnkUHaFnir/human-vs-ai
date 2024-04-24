unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

// Assuming all file paths are correctly defined

// Initialize all file pointers in the hypo_table array
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        char filename[10];
        sprintf(filename, "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if (hypo_table[i][j] == NULL) {
            fprintf(stderr, "Error opening file for writing\n");
            // Handle error, maybe exit the program
        }
    }
}

// Write data to files using initialized file pointers
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        for (hypo_key = 0; hypo_key < 256; hypo_key++) {
            // Process error_array
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
        }
    }
}

// Close all files after writing
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        fclose(hypo_table[i][j]);
    }
}
