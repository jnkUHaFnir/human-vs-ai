#include <stdio.h>

int main() {
    FILE *file;
    char fileName[] = "/home/chronos/user/Downloads/grades.txt";
    file = fopen(fileName, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    // Read the 10x5 matrix of student IDs and grades
    int matrix[10][5];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error reading file.\n");
                return 1;
            }
        }
    }

    // Calculate average student scores
    float avgScores[10];
    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += matrix[i][j];
        }
        avgScores[i] = (float)sum / 5;
    }

    // Close the file
    fclose(file);

    // Further processing...

    return 0;
}
