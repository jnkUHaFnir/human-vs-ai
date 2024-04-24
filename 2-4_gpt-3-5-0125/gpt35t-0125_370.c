int main()
{
    FILE * fPtr;

    char name[50];
    double gpa;

    fPtr = fopen("data.txt", "r");

    if (fPtr == NULL) {
        puts("File open for read failed");
        return 1;
    }

    while (fscanf(fPtr, "%s %lf", name, &gpa) == 2) {
        fprintf(stdout, "Name: %s\n", name);
        fprintf(stdout, "GPA: %lf\n", gpa);
    }

    fclose(fPtr);
    return 0;
}
