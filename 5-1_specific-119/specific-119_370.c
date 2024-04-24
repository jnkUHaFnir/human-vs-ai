#include <stdio.h>

int main()
{
    FILE * fPtr;
    char line[50];
    char name[20];
    double gpa;

    fPtr = fopen("data.txt", "r");

    if (fPtr == NULL) // open failure
        puts("File open for read failed");
    else
    {
        while(fgets(line, sizeof(line), fPtr) != NULL)
        {
            sscanf(line, "%s %lf", name, &gpa); // Tokenize the line to get name and GPA
            fprintf(stdout, "Name = %s\n", name);
            fprintf(stdout, "GPA = %lf \n", gpa);
        }
    }

    fclose(fPtr);
    return 0;
}
