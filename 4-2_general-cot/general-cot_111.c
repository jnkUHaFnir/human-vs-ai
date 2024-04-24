#include <stdio.h>

int main() {
    int count = 0;
    int x;
    char Grade[4]; // Increased the size to accommodate multi-character grades
    char studentName[50];
    int studentID = 0;
    int f = 0;

    do {
        printf("\nEnter student ID: ");
        scanf("%d", &studentID);

        if(studentID != 0) {
            printf("Enter student name: ");
            scanf("%s", studentName);
            printf("Enter student marks: ");
            scanf("%d", &x);

            if(x >= 80)
                strcpy(Grade, "A");
            else if(x >= 75)
                strcpy(Grade, "A-");
            else if(x >= 70)
                strcpy(Grade, "B+");
            else if(x >= 65)
                strcpy(Grade, "B");
            else if(x >= 60)
                strcpy(Grade, "B-");
            else if(x >= 55)
                strcpy(Grade, "C+");
            else if(x >= 50)
                strcpy(Grade, "C");
            else if(x >= 45)
                strcpy(Grade, "C-");
            else if(x >= 40)
                strcpy(Grade, "D+");
            else if(x >= 35)
                strcpy(Grade, "D");
            else if(x >= 30)
                strcpy(Grade, "D-");
            else
            {
                strcpy(Grade, "F");
                f++;
            }   
            printf("%s has the following marks %d and the Grade is %s\n", studentName, x, Grade);
            count++;        
        }   
    } while(studentID != 0);

    printf("Sum of students =  %d\n", count);
    printf("Sum of failed students = %d\n", f);

    return 0;
}
