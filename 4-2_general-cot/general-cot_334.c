#include <stdio.h>

#define ROWS 10
#define COLS 5

int main() {
    FILE* file = fopen("grades.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int matrix[ROWS][COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                printf("Error reading file!\n");
                return 1;
            }
        }
    }
    
    fclose(file);
    
    // Calculate and print average student scores
    for (int i = 0; i < ROWS; i++) {
        double sum = 0.0;
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
        double average = sum / COLS;
        printf("Student %d average score: %.2f\n", i + 1, average);
    }
    
    return 0;
}
