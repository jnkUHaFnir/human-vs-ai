unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

// Initialize all file pointers to NULL or open them with fopen, and check for errors
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        char filename[6];
        sprintf(filename, "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if (!hypo_table[i][j]) {
            perror("Failed to open file");
            // Handle error, e.g., by exiting the loop, or by setting the pointer to NULL
            hypo_table[i][j] = NULL;
        }
    }
}

// Now you can write to the files
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        for (int hypo_key = 0; hypo_key < 256; hypo_key++) {
            // Check if the file pointer was successfully opened before writing to it
            if (hypo_table[i][j]) {
                fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            }
            if (hypo_key == 255)
                break;
        }
    }
}

// Close all files that were successfully opened
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        if (hypo_table[i][j]) {
            fclose(hypo_table[i][j]);
        }
    }
}
