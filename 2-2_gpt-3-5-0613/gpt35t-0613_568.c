#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* Argo[]) {

    FILE *student;
    char brst[255];
    int lineCount = 0;

    student = fopen("student.txt", "r");

    while (fgets(brst, sizeof(brst), student) != NULL) {
        printf("%s", brst);
        lineCount++;
    }

    printf("Number of lines: %d\n", lineCount);

    fclose(student);

    return 0;
}
