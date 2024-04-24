#include <stdio.h>

int main() {
    // Assuming the file is in the Downloads directory, update the path accordingly
    const char* filename = "/home/yourusername/Downloads/grades.txt";
    FILE *spTemp = fopen(filename, "r");

    if (spTemp == NULL) {
        perror("Error opening file"); // Print the error if file doesn't open
        return 1;
    }

    // Assuming that student ID and grades are integers
    int studentId;
    int grades[5]; // An array to store grades for each student

    // Read the file line-by-line
    while (fscanf(spTemp, "%d %d %d %d %d %d", &studentId, &grades[0], &grades[1], &grades[2], &grades[3], &grades[4]) == 6) {
        float average = 0;

        // Calculate the average grade for the student
        for (int i = 0; i < 5; i++) {
            average += grades[i];
        }
        average /= 5;

        // Print the student ID and their average
        printf("Student ID: %d, Average Grade: %.2f\n", studentId, average);
    }

    // Close the file
    fclose(spTemp);

    return 0;
}
