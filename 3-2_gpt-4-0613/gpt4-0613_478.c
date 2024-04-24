unsigned char error_array[4][4][256]
FILE *hypo_table[4][4];

char filename[6];
for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
        sprintf(filename, "%d%d.txt", i, j); // Create Filename
        hypo_table[i][j] = fopen(filename, "w");
        if (hypo_table[i][j] == NULL) {
            printf("Error opening file %s\n", filename);
            exit(1);
        }
    }
}

for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
        for(hypo_key = 0; hypo_key < 256; hypo_key++) {
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            if(hypo_key == 255)
                break;
        }
    }
}
