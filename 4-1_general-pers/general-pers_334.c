#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10
#define MAX_GRADES 5

int main() {
    FILE* file;
    char* filePath = "/path/to/downloads/grades.txt";
    int studentGrades[MAX_STUDENTS][MAX_GRADES];

    file = fopen(filePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Read student ID#s and grades from the file
    for (int i = 0; i < MAX_STUDENTS; i++) {
        for (int j = 0; j < MAX_GRADES; j++) {
            if (fscanf(file, "%d", &studentGrades[i][j]) != 1) {
                fprintf(stderr, "Error reading data from file\n");
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);

    // Calculate and print average scores
    for (int i = 0; i < MAX_STUDENTS; i++) {
        int sum = 0;
        for (int j = 0; j < MAX_GRADES; j++) {
            sum += studentGrades[i][j];
        }
        float avg = (float)sum / MAX_GRADES;
        printf("Average score for student %d: %.2f\n", studentGrades[i][0], avg);
    }

    return 0;
}
