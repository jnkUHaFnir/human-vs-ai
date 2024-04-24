#include <stdio.h>

int main()
{
    FILE *fPtr;
    char name[20];
    double gpa;

    fPtr = fopen("data.txt", "r");

    if (fPtr == NULL) {
        puts("File open for read failed");
        return 1;
    }

    while (fscanf(fPtr, "%s %lf", name, &gpa) != EOF) {
        // Print the data read from the file
        fprintf(stdout, "Name: %s\n", name);
        fprintf(stdout, "GPA: %lf\n", gpa);
    }

    fclose(fPtr);
    
    return 0;
}
