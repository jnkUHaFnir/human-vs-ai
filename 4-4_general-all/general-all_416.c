#include <stdio.h>

int main() {
    unsigned char error_array[4][4][256];
    FILE *hypo_table[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char filename[10];
            snprintf(filename, sizeof(filename), "%d%d.txt", i, j);
            hypo_table[i][j] = fopen(filename, "w");
            if (hypo_table[i][j] == NULL) {
                // Handle error opening file
                perror("Error opening file");
                return 1;
            }
        }
    }

    // Assuming error_array is properly populated

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int hypo_key = 0; hypo_key < 256; hypo_key++) {
                //process error_array
                fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            }
        }
    }

    // Close all opened files
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            fclose(hypo_table[i][j]);
        }
    }

    return 0;
}
