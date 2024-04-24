#include <stdio.h>

#define BUFFER_SIZE 50

int main()
{
    FILE *fPtr;
    char name[BUFFER_SIZE];
    double gpa;

    fPtr = fopen("data.txt", "r");

    if (fPtr == NULL)
    {
        puts("File open for read failed");
        return 1;
    }

    while (fscanf(fPtr, "%s %lf", name, &gpa) == 2)
    {
        printf("Name: %s\n", name);
        printf("GPA: %.1lf\n", gpa);
    }

    fclose(fPtr);

    getchar(); // Wait for user input before exiting
    return 0;
}
