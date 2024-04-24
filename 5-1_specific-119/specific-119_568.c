#include <stdio.h>

int main() {
    FILE *student;
    char line[255];
    int lineCount = 0;

    student = fopen("student.txt", "r");
    if (student == NULL) {
        printf("File opening failed.");
        return 1;
    }

    while (fgets(line, sizeof(line), student) != NULL) {
        printf("%s", line);
        lineCount++;
    }

    printf("Number of lines: %d\n", lineCount);

    fclose(student);

    return 0;
}
