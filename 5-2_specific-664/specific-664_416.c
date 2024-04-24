#include <stdio.h>

unsigned char error_array[4][4][256];
FILE *hypo_table[4][4];

int main() {
    // Open files once and validate the file opening
    hypo_table[0][0] = fopen("00.txt", "w");
    hypo_table[1][0] = fopen("10.txt", "w");
    hypo_table[2][0] = fopen("20.txt", "w");
    hypo_table[3][0] = fopen("30.txt", "w");

    hypo_table[1][1] = fopen("11.txt", "w");
    hypo_table[1][2] = fopen("12.txt", "w");
    hypo_table[1][3] = fopen("13.txt", "w");

    hypo_table[2][1] = fopen("21.txt", "w");
    hypo_table[2][2] = fopen("22.txt", "w");
    hypo_table[2][3] = fopen("23.txt", "w");

    hypo_table[3][1] = fopen("31.txt", "w");
    hypo_table[3][2] = fopen("32.txt", "w");
    hypo_table[3][3] = fopen("33.txt", "w");

    int i, j, hypo_key;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (hypo_key = 0; hypo_key < 256 ; hypo_key++) {
                // Process error_array
                fprintf(hypo_table[i][j], "%.2x ", error_array[i][j][hypo_key]);
            }
        }
    }

    // Close files
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            fclose(hypo_table[i][j]);
        }
    }

    return 0;
}
