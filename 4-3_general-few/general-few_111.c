#include<stdio.h>
#include<string.h>

int main()
{
    int count=0;
    int x;
    char Grade[3]; // Modified to hold grades with suffixes
    char studentName[50];
    int studentID=0;
    int f=0;

    do
    {
        printf("\nEnter student ID: ");
        scanf("%d", &studentID);

        if(studentID!=0)
        {           
            printf("Enter student name: ");
            scanf("%s", studentName);
            printf("Enter student marks: ");
            scanf("%d", &x);

            if(x<=100 && x>=80)
                strcpy(Grade, "A");
            else if(x<=79 && x>=75)
                strcpy(Grade, "A-");
            else if(x<=74 && x>=70)
                strcpy(Grade, "B+");
            else if(x<=69 && x>=65)
                strcpy(Grade, "B");
            // Add similar conditions for other grades with suffixes
            
            printf("%s have the following marks %d and the Grade is %s\n ", studentName, x, Grade);
            
            // Increment fail count if Grade is 'F'
            if(strcmp(Grade, "F") == 0)
            {
                f++;
            }

            count++;        
        }   
    } while(studentID != 0);

    printf("Sum of student = %d\n", count);
    printf("Sum of fail student = %d\n", f);

    return 0;
}
