hypo_table[1][0] = fopen("10.txt", "w"); // First initialization
// ...
hypo_table[1][0] = fopen("10.txt", "w"); // Second initialization
char filename[6]; // Buffer to hold filenames like "00.txt"

for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
        snprintf(filename, sizeof(filename), "%d%d.txt", i, j);
        hypo_table[i][j] = fopen(filename, "w");
        if(hypo_table[i][j] == NULL) {
            fprintf(stderr, "Failed to open file %s\n", filename);
            // Handle error: You might decide to exit, or set a flag and clean up.
        }
    }
}
