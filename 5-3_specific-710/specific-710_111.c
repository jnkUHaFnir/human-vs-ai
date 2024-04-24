#include <stdio.h>

int main()
{
    int count = 0;
    int x;
    char Grade[3]; // Change Grade to char array to store multi-character grades
    char studentName[50];
    int studentID = 0;
    int f = 0;

    do
    {
        printf("\nEnter student ID: ");
        scanf("%d", &studentID);

        if (studentID != 0)
        {
            printf("Enter student name: ");
            scanf("%s", studentName);
            printf("Enter student marks: ");
            scanf("%d", &x);

            if (x <= 100 && x >= 80)
                strcpy(Grade, "A");
            else if (x <= 79 && x >= 75)
                strcpy(Grade, "A-");
            else if (x <= 74 && x >= 70)
                strcpy(Grade, "B+");
            // Add other grade comparisons for B-, C+, C, C-, D+, D, D- based on your requirements
            else if (x <= 69 && x >= 0)
            {
                strcpy(Grade, "F");
                f++;
            }
            printf("%s has the following marks %d and the Grade is %s\n ", studentName, x, Grade);
            count++;
        }
    } while (studentID != 0);

    printf("Sum of students =  %d\n", count);
    printf("Sum of failed students = %d\n", f);

    return 0;
}
