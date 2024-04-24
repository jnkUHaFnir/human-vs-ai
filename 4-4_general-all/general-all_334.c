#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* spTemp;
    char filename[] = "/home/chronos/u-user/Downloads/grades.txt"; // Path to the downloaded file on Chromebook

    spTemp = fopen(filename, "r");
    if (spTemp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read the content of the file
    // Assuming a 10x5 matrix, you can adjust the dimensions as needed
    int matrix[10][5];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (fscanf(spTemp, "%d", &matrix[i][j]) != 1) {
                printf("Error reading from file.\n");
                fclose(spTemp);
                return 1;
            }
        }
    }

    // Calculate and print the average score of each student
    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += matrix[i][j];
        }
        double average = (double)sum / 5;
        printf("Student %d Average Score: %.2f\n", i + 1, average);
    }

    fclose(spTemp);

    return 0;
}
