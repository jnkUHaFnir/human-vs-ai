unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        char filename[10];
        sprintf(filename, "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if (!hypo_table[i][j]) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }
}

for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        for (hypo_key = 0; hypo_key < 256; hypo_key++) {
            // process error_array
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            if (hypo_key == 255)
                break;
        }
    }
}
