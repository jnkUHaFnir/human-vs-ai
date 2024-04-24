#include <stdio.h>

int main() {
    FILE *student;
    char brst[255];
    int line_counter = 0;

    student = fopen("student.txt", "r");

    if (student == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(brst, 255, student) != NULL) {
        printf("%s", brst);
        line_counter++;
    }

    printf("Number of lines: %d\n", line_counter);

    fclose(student);

    return 0;
}
