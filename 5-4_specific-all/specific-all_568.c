#include "stdafx.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

    FILE *student;
    char brst[255];
    int count = 0;

    student = fopen("student.txt", "r");

    if (student == NULL) {
        printf("Error opening file.");
        return 1;
    }

    while (fgets(brst, sizeof(brst), student) != NULL) {
        printf("%s", brst);
        count++;
    }

    printf("Number of lines: %d\n", count);

    fclose(student);

    return 0;
}
