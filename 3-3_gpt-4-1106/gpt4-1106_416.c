unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        char filename[10];
        sprintf(filename, "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if (!hypo_table[i][j]) {
            perror("Error opening file");
            // Handle error, maybe close all opened files and exit
        }
    }
}

// ... Rest of your code to work with the files
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        if (hypo_table[i][j]) {
            fclose(hypo_table[i][j]);
        }
    }
}
