#include <stdio.h>

int main()
{
    int count = 0;
    int x;
    char Grade;
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
            scanf("%s", studentName);  // Removed '&' before studentName

            printf("Enter student marks: ");
            scanf("%d", &x);

            if (x <= 100 && x >= 80)
                Grade = 'A';
            else if (x <= 79 && x >= 75)
                Grade = 'a';  // Change "A-" to "a" due to limitations of char
            else if (x <= 74 && x >= 70)
                Grade = 'B';
            else if (x <= 69 && x >= 65)
                Grade = 'b';  // Change "B-" to "b" due to limitations of char
            else if (x <= 64 && x >= 60)
                Grade = 'C';
            else if (x <= 59 && x >= 55)
                Grade = 'c';  // Change "C+" to "c" due to limitations of char
            else if (x <= 54 && x >= 50)
                Grade = 'D';
            else if (x <= 49 && x >= 45)
                Grade = 'd';  // Change "D-" to "d" due to limitations of char
            else if (x <= 44 && x >= 40)
                Grade = 'F';
            else
            {
                Grade = 'F';
                f++;
            }
            printf("%s has the following marks %d and the Grade is %c\n ", studentName, x, Grade);
            count++;
        }
    } while (studentID != 0);

    printf("Sum of students =  %d\n", count);
    printf("Sum of fail students = %d\n", f);

    return 0;
}
