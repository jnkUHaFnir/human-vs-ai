#include <stdio.h>

int main() {
    int count = 0;
    int x;
    char Grade[3];
    char studentName[50];
    int studentID = 0;
    int f = 0;

    do {
        Grade[0] = '\0'; // Reset Grade for each student
        printf("\nEnter student ID: ");
        scanf("%d", &studentID);

        if (studentID != 0) {
            printf("Enter student name: ");
            scanf("%49s", studentName);
            printf("Enter student marks: ");
            scanf("%d", &x);

            if (x >= 80 && x <= 100)
                strcpy(Grade, "A");
            else if (x >= 75 && x <= 79)
                strcpy(Grade, "A-");
            // Add other grade comparisons here

            if (Grade[0] == '\0') {
                strcpy(Grade, "Invalid"); // Default to "Invalid" if grade not found
            }

            printf("%s has the following marks %d and the Grade is %s\n", studentName, x, Grade);
            count++;
            if (Grade[0] == 'F')
                f++;
        }
    } while (studentID != 0);

    printf("Number of students = %d\n", count);
    printf("Number of students failed = %d\n", f);

    return 0;
}
