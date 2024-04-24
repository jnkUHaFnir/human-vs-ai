#include <stdio.h>

int main() {
    FILE *student;
    char brst[255];
    int lines = 0;

    student = fopen("student.txt", "r");
    if (student == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(brst, 255, student) != NULL) {
        printf("%s", brst);
        lines++;
    }

    printf("\nNumber of lines: %d\n", lines);

    fclose(student);
    return 0;
}
