#include <stdio.h>

int main() {
    FILE* file;
    char filename[] = "/home/chronos/user/Downloads/grades.txt";
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file. Exiting...\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int studentId;
        float grades[5];
        
        // Parse student ID and grades from the line
        sscanf(line, "%d %f %f %f %f %f", &studentId, &grades[0], &grades[1], &grades[2], &grades[3], &grades[4]);
        
        // Calculate average grade
        float avgGrade = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4]) / 5.0;
        
        // Process the data (e.g., store in a data structure, print, etc.)
        printf("Student ID: %d, Average Grade: %.2f\n", studentId, avgGrade);
    }
    
    // Close the file
    fclose(file);

    return 0;
}
