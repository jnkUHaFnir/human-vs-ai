#include <stdio.h>

int main() {
    FILE *student;
    char line[255];
    int count = 0;

    student = fopen("student.txt", "r");

    if (student == NULL) {
        perror("Error while opening the file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), student) != NULL) {
        printf("%s\n", line);
        count++;
    }

    printf("Number of lines in the file: %d\n", count);

    fclose(student);

    return 0;
}
