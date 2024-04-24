#include <stdio.h>

int main(){

    FILE *student;
    char brst[255];
    int linesCount = 0;

    student = fopen("student.txt", "r");
    if( student == NULL ){
        perror("Error while opening the file.\n");
        return -1;
    }

    while(fgets(brst, 255, student) != NULL) 
    {
        linesCount++;
        printf("%s", brst);
    }

    printf("\nNumber of lines are %d\n", linesCount);

    fclose(student);

    return 0;
}
