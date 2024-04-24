#include <stdio.h>

int main() {
    // File pointer
    FILE* spTemp;
    
    // Open file in read mode
    spTemp = fopen("/home/chronos/user/Downloads/grades.txt", "r");

    // Check if file opened successfully
    if (spTemp == NULL) {
        printf("Could not open file grades.txt");
        return 1; // Return with error
    }

    // 2D Array to store student data
    int studentData[10][5];
    
    // Read the file
    for(int i=0; i<10; i++) {
        for(int j=0; j<5; j++) {
            fscanf(spTemp, "%d", &studentData[i][j]);
        }
    }

    // Close the file
    fclose(spTemp);

    // Print the student data
    for(int i=0; i<10; i++) {
        for(int j=0; j<5; j++) {
            printf("%d ", studentData[i][j]);
        }
        printf("\n");
    }

    return 0;
}
