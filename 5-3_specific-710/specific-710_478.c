unsigned char error_array[4][4][256];
FILE *hypo_table;
hypo_table = fopen("00.txt", "w");
unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];
hypo_table[0][0] = fopen("00.txt", "w");
hypo_table[1][0] = fopen("10.txt", "w");
// assignments for hypo_table continued...
hypo_table[1][0] = fopen("10.txt", "w");
for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
        hypo_table[i][j] = fopen(fileName[i][j], "w");
        for(hypo_key = 0; hypo_key < 256; hypo_key++) {
            // process error_array
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
        }
    }
}
