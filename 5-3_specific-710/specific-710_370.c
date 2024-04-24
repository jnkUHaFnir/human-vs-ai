#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fPtr;
    char name[20];
    double gpa;

    fPtr = fopen("data.txt", "r");

    if (fPtr == NULL) {
        puts("File open for read failed");
        return 1;
    }

    while (fscanf(fPtr, "%s %lf", name, &gpa) == 2) {
        if (strcmp(name, "Oakley") == 0) {
            printf("Name: %s\n", name);
            printf("GPA: %.1f\n", gpa);
            break; // Found Oakley, exit loop
        }
    }

    fclose(fPtr);
    return 0;
}
