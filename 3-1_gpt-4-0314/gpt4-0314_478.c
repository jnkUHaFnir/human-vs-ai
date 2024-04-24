for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        char filename[8];
        sprintf(filename, "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if (hypo_table[i][j] == NULL) {
            fprintf(stderr, "Error opening file: %s\n", filename);
            // handle the error, e.g., exit the program
        }
    }
}
