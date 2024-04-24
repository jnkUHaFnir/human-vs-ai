#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* spTemp;
    char filename[] = "/home/chronos/user/Downloads/grades.txt";
    
    spTemp = fopen(filename, "r");

    if (spTemp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the 10x5 matrix of student IDs and grades
    int matrix[10][5];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (fscanf(spTemp, "%d", &matrix[i][j]) != 1) {
                printf("Error reading from file.\n");
                return -1;
            }
        }
    }

    fclose(spTemp);

    // Perform calculations and other operations with the matrix data
    // (e.g., calculating average score for each student)

    return 0;
}
