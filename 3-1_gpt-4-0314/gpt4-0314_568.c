#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[]){
    FILE *student;
    char brst[255];
    int no_of_lines = 0;

    student = fopen("student.txt", "r");
    if (!student) {
        perror("Error opening file");
        return -1;
    }

    while(fgets(brst, 255, student) != NULL)
    {
        printf("%s", brst);
        no_of_lines++;
    }

    printf("\nNumber of lines: %d\n", no_of_lines);
    fclose(student);
    return 0;
}
