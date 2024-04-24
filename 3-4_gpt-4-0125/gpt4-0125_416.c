unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

// Initialize all to NULL
for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
        hypo_table[i][j] = NULL;
    }
}

// Open files and assign to hypo_table
hypo_table[0][0] = fopen("00.txt", "w");
// ...
// ensure you correctly open all required files here
// ...

// Check for successful file open before using the file pointers
for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
        if(hypo_table[i][j] == NULL) {
            fprintf(stderr, "Failed to open file for hypo_table[%d][%d]\n", i, j);
            // Handle error, e.g., clean up and exit
            exit(1);
        }
        for(int hypo_key = 0; hypo_key < 256; hypo_key++) {
            // Process error_array
            fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            if(hypo_key == 255)
                break;
        }
    }
}
