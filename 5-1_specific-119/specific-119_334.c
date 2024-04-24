#include <stdio.h>

int main() {
    FILE* spTemp;
    int studentId, grade;

    spTemp = fopen("grades.txt", "r"); // Open the file in read mode

    if (spTemp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read and display student ID#s and grades
    while (fscanf(spTemp, "%d %d", &studentId, &grade) == 2) {
        printf("Student ID: %d, Grade: %d\n", studentId, grade);
    }

    fclose(spTemp); // Don't forget to close the file

    return 0;
}
