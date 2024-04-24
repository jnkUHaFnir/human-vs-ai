#include <stdio.h>

int main() {
    int count = 0;
    int x;
    char Grade[3]; // Changed Grade to a string to handle multi-character grades
    char studentName[50];
    int studentID = 0;
    int f = 0;

    do {
        printf("\nEnter student ID: ");
        scanf("%d", &studentID);

        if (studentID != 0) {
            printf("Enter student name: ");
            scanf("%s", studentName);
            printf("Enter student marks: ");
            scanf("%d", &x);

            if (x <= 100 && x >= 80)
                snprintf(Grade, sizeof(Grade), "A");
            else if (x <= 79 && x >= 75)
                snprintf(Grade, sizeof(Grade), "A-");
            else if (x <= 74 && x >= 70)
                snprintf(Grade, sizeof(Grade), "B+");
            else if (x <= 69 && x >= 65)
                snprintf(Grade, sizeof(Grade), "B");
            else if (x <= 64 && x >= 60)
                snprintf(Grade, sizeof(Grade), "B-");
            else if (x <= 59 && x >= 55)
                snprintf(Grade, sizeof(Grade), "C+");
            else if (x <= 54 && x >= 50)
                snprintf(Grade, sizeof(Grade), "C");
            else if (x <= 49 && x >= 45)
                snprintf(Grade, sizeof(Grade), "C-");
            else if (x <= 44 && x >= 40)
                snprintf(Grade, sizeof(Grade), "D+");
            else if (x <= 39 && x >= 35)
                snprintf(Grade, sizeof(Grade), "D");
            else if (x <= 34 && x >= 30)
                snprintf(Grade, sizeof(Grade), "D-");
            else if (x <= 29 && x >= 0) {
                snprintf(Grade, sizeof(Grade), "F");
                f++;
            }
            printf("%s has the following marks %d and the Grade is %s\n ", studentName, x, Grade);
            count++;
        }
    } while (studentID != 0);

    printf("Sum of students = %d\n", count);
    printf("Sum of fail students = %d\n", f);

    return 0;
}
