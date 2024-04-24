#include <stdio.h>

int main() {
    FILE *student;
    char line[255];
    int lines = 0;

    student = fopen("student.txt", "r");

    if (student == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), student) != NULL) {
        printf("%s", line);
        lines++;
    }

    fclose(student);

    printf("\nNumber of lines: %d\n", lines);

    return 0;
}
