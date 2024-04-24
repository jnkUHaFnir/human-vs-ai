unsigned char error_array[4][4][256];
FILE *hypo_table[4][4]; 

// Open all files
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        char filename[10];
        snprintf(filename, 10, "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if (hypo_table[i][j] == NULL) {
            // Handle error opening file
        }
    }
}

// Write data to files
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        for (hypo_key = 0; hypo_key < 256; hypo_key++) {
            // Process error_array
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
        }
    }
}

// Close all files
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        fclose(hypo_table[i][j]);
    }
}
