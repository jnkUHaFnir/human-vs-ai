#include <stdio.h>

int main()
{
    FILE *fPtr;
    char name[50]; // Make sure the array is large enough to hold the entire name
    double gpa;

    fPtr = fopen("data.txt", "r");

    if (fPtr == NULL)
    {
        puts("File open for read failed");
    }
    else
    {
        while (fscanf(fPtr, "%s %lf", name, &gpa) == 2)
        {
            fprintf(stdout, "Name = %s\n", name);
            fprintf(stdout, "GPA = %lf\n", gpa);
        }
    }

    fclose(fPtr);
    // system("pause"); // Remove this line

    return 0;
}
