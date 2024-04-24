#include <stdio.h>

int main() {

    FILE* spTemp;

    spTemp = fopen("/home/chronos/user/Downloads/grades.txt", "r");

    // Check if the file opened successfully
    if (spTemp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the data from the file and process it
    int id, grade;
    int i, j;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 5; ++j) {
            fscanf(spTemp, "%d %d", &id, &grade);
            printf("Student ID: %d, Grade: %d\n", id, grade);
        }
    }

    // Close the file
    fclose(spTemp);

    return 0;
}
12345 90
23456 80
...
