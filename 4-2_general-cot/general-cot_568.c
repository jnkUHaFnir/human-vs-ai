#include <stdio.h>

int main() {
    FILE *student;
    char brst[255];
    int count = 0;

    student = fopen("student.txt", "r");

    if (student == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(brst, 255, student) != NULL) {
        printf("%s", brst);
        count++;
    }

    printf("Number of lines in the file: %d\n", count);

    fclose(student);

    return 0;
}
