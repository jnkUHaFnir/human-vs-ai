#include "stdafx.h"
#include <stdio.h>

int main(){

    FILE *student;
    char brst[255];
    int count = 0;

    student = fopen("student.txt", "r");

    if (student == NULL) {
        printf("Error opening the file");
        return 1;
    }

    while (fgets(brst, 255, student) != NULL) {
        printf("%s", brst);
        count++;
    }

    printf("Number of students: %d", count);

    fclose(student);

    return 0;
}
