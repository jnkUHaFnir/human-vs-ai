unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

int i, j;
// Initialize the hypo_table file array
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        char filename[6];
        snprintf(filename, sizeof(filename), "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
    }
}

for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        for (hypo_key = 0; hypo_key < 256; hypo_key++) {
            //process error_array
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            if (hypo_key == 255) {
                break;
            }
        }
    }
}
// Close all files in the hypo_table array
for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
        fclose(hypo_table[i][j]);
    }
}
