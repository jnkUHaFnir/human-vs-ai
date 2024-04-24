#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* Argo[]){

    FILE *student;
    char brst[255];
    int line_count = 0;

    student = fopen("student.txt", "r");

    if (student == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(brst, 255, student) != NULL)
    {
        printf("%s", brst);
        line_count++;
    }

    printf("Number of students: %d\n", line_count);

    fclose(student);

    return 0;
}
