#include <stdio.h>

int main()
{
    FILE *fPtr;
    char name[50]; // Increase the size to accommodate full names
    double gpa;

    fPtr = fopen("data.txt", "r");

    if (fPtr == NULL)
    {
        puts("File open for read failed");
        return 1;
    }

    while (fscanf(fPtr, "%[^\n] %lf ", name, &gpa) != EOF)
    {
        fprintf(stdout, "Name: %s\n", name);
        fprintf(stdout, "GPA: %lf\n", gpa);
    }

    fclose(fPtr);
    return 0;
}
