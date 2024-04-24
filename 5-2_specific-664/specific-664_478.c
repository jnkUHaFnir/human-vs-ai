#include <stdio.h>

unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

int main() {
    int i, j, hypo_key;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            char file_name[10];
            snprintf(file_name, sizeof(file_name), "%d%d.txt", i, j);
            hypo_table[i][j] = fopen(file_name, "w");
            
            if (hypo_table[i][j] == NULL) {
                perror("Error opening file");
                return 1;
            }

            for (hypo_key = 0; hypo_key < 256; hypo_key++) {
                // process error_array
                fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            }
        }
    }

    // Close all opened files
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            fclose(hypo_table[i][j]);
        }
    }

    return 0;
}
