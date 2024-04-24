#include<stdio.h>

int main()
{
    int count=0;
    int x;
    char Grade[3]; // Change Grade to a string array
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
            scanf("%s", &studentName);
            printf("Enter student marks: ");
            scanf("%d", &x);

            if(x<=100 && x>=80)
                strcpy(Grade, "A");
            else if(x<=79 && x>=75)
                strcpy(Grade, "A-");
            // Add more strcpy statements for other grades
            
            printf("%s have the following marks %d and the Grade is %s\n", studentName, x, Grade);
            count++;        
        }   
    }while(studentID!=0);

    printf("Sum of student = %d\n", count);
    printf("Sum of fail student = %d\n", f);
}
